#include "GpLogRunnable.hpp"

namespace GPlatform {

GpLogRunnable::GpLogRunnable
(
    GpConditionVar::SP                      aCondVar,
    const GpLogConsumerFactory::C::Vec::SP& aConsumerFactories
):
GpRunnable(std::move(aCondVar)),
iConsumerFactories(aConsumerFactories)
{
}

GpLogRunnable::~GpLogRunnable (void) noexcept
{
}

void    GpLogRunnable::Run (GpThreadStopToken aStopToken) noexcept
{
    try
    {
        GpLogConsumer::C::Vec::SP consumers = CreateConsumers();

        while (!aStopToken.stop_requested())
        {
            Consume(consumers);
            //WaitForWakeup(0.5_si_s);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

        Consume(consumers);
        ConsumeNotEnded(consumers);
        Flush(consumers);
    } catch (const std::exception& e)
    {
        GpExceptionsSink::SSink(e);
    } catch (...)
    {
        GpExceptionsSink::SSinkUnknown();
    }
}

void    GpLogRunnable::AddElement
(
    std::string_view    aChainId,
    GpLogElement&&      aLogElement
)
{
    const GpLogConsumeMode::EnumT consumeMode = aLogElement.ConsumeMode();

    if (consumeMode == GpLogConsumeMode::CHAIN_END)
    {
        GpLogChain::SP chain;

        if (aChainId.length() > 0)
        {
            chain = FindAndRemoveChain(aChainId);
        } else
        {
            chain = MakeSP<GpLogChain>(std::string(aChainId));
        }

        chain->AddElement(std::move(aLogElement));

        PushToEnded(std::move(chain));
    } else
    {
        GpLogChain::SP chain;

        chain = FindOrRegisterChain(aChainId);
        chain->AddElement(std::move(aLogElement));
    }
}

GpLogChain::SP  GpLogRunnable::FindAndRemoveChain (std::string_view aChainId)
{
    auto chain = iChainsById.TryUnregister(aChainId);

    if (chain.has_value())
    {
        return chain.value();
    } else
    {
        return MakeSP<GpLogChain>(std::string(aChainId));
    }
}

GpLogChain::SP  GpLogRunnable::FindOrRegisterChain (std::string_view aChainId)
{
    return iChainsById.FindOrRegister
    (
        aChainId,
        [&]()
        {
            return MakeSP<GpLogChain>(std::string(aChainId));
        }
    );
}

void    GpLogRunnable::PushToEnded (GpLogChain::SP&& aChain)
{
    std::scoped_lock lock(iChainsEndedLock);
    iChainsEnded.push(std::move(aChain));
}

std::optional<GpLogChain::SP>   GpLogRunnable::PopFromEnded (void)
{
    std::scoped_lock lock(iChainsEndedLock);

    if (iChainsEnded.empty())
    {
        return std::nullopt;
    }

    GpLogChain::SP chain = iChainsEnded.front();
    iChainsEnded.pop();

    return chain;
}

void    GpLogRunnable::Consume (GpLogConsumer::C::Vec::SP& aConsumers)
{
    std::optional<GpLogChain::SP> chain = PopFromEnded();

    while (chain.has_value())
    {
        for (auto& consumer: aConsumers)
        {
            consumer->Consume(chain.value());
        }
        chain = PopFromEnded();
    }
}

void    GpLogRunnable::ConsumeNotEnded (GpLogConsumer::C::Vec::SP& aConsumers)
{
    ChainsByIdT chainsById = iChainsById.UnregisterAll();

    chainsById.Apply
    (
        [&](auto& aChain)
        {
            for (auto& consumer: aConsumers)
            {
                consumer->Consume(aChain);
            }
        }
    );
}

void    GpLogRunnable::Flush (GpLogConsumer::C::Vec::SP& aConsumers)
{
    for (auto& consumer: aConsumers)
    {
        consumer->OnFlush();
    }
}

GpLogConsumer::C::Vec::SP   GpLogRunnable::CreateConsumers (void)
{
    GpLogConsumer::C::Vec::SP consumers;

    for (auto& consumerFactory: iConsumerFactories)
    {
        consumers.emplace_back(consumerFactory->NewInstance());
    }

    return consumers;
}

}//namespace GPlatform
