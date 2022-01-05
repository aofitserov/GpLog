#pragma once

#include "GpLogChain.hpp"
#include "Consumers/GpLogConsumerFactory.hpp"

namespace GPlatform {

class GPLOG_API GpLogRunnable final: public GpRunnable
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpLogRunnable)
    CLASS_DECLARE_DEFAULTS(GpLogRunnable)

    using ChainsByIdT   = GpElementsCatalog<std::string, GpLogChain::SP>;
    using ChainsEndedT  = GpLogChain::C::Queue::SP;

public:
                                        GpLogRunnable       (GpConditionVar::SP                         aCondVar,
                                                             const GpLogConsumerFactory::C::Vec::SP&    aConsumerFactories);
    virtual                             ~GpLogRunnable      (void) noexcept override final;

    virtual void                        Run                 (GpThreadStopToken aStopToken) noexcept override final;

    void                                AddElement          (std::string_view   aChainId,
                                                             GpLogElement&&     aLogElement);
    void                                EndChain            (std::string_view   aChainId);

private:
    GpLogChain::SP                      FindAndRemoveChain  (std::string_view aChainId);
    GpLogChain::SP                      FindOrRegisterChain (std::string_view aChainId);

    void                                PushToEnd           (GpLogChain::SP&& aChain);
    std::optional<GpLogChain::SP>       PopFromEnd          (void);

    void                                Consume             (GpLogConsumer::C::Vec::SP& aConsumers);
    void                                ConsumeNotEnded     (GpLogConsumer::C::Vec::SP& aConsumers);
    void                                Flush               (GpLogConsumer::C::Vec::SP& aConsumers);
    GpLogConsumer::C::Vec::SP           CreateConsumers     (void);

private:
    GpLogConsumerFactory::C::Vec::SP    iConsumerFactories;
    ChainsByIdT                         iChainsById;
    GpSpinlock                          iChainsEndedLock;
    ChainsEndedT                        iChainsEnded;
};

}//namespace GPlatform
