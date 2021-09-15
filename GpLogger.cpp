#include "GpLogger.hpp"
#include "Consumers/GpLogConsumerConfigBuilder.hpp"

namespace GPlatform {

GpLogger    GpLogger::sLogger;

GpLogger::GpLogger (void) noexcept:
iStartSteadyTS(GpDateTimeOps::SSteadyTS_us())
{
}

GpLogger::~GpLogger (void) noexcept
{
}

void    GpLogger::StartFromConfig (const GpLogConfigDesc& aCfgDesc)
{
    THROW_GPE_COND
    (
        iLogExecutor.IsNULL(),
        "Log already configured"_sv
    );

    iDefaultLevel   = aCfgDesc.default_level.Value();

    for (auto&[k, v]: aCfgDesc.category_levels)
    {
        iCategoryLevels[k] = GpLogLevel::SFromString(v);
    }

    iLogExecutor = MakeSP<GpLogExecutor>();
    iLogExecutor->Start(GpLogConsumerConfigBuilder::SFromConfig(aCfgDesc.consumers));
}

void    GpLogger::Stop (void)
{
    THROW_GPE_COND
    (
        iLogExecutor.IsNotNULL(),
        "Log not configured"_sv
    );

    iLogExecutor->RequestStop();
    iLogExecutor->Join();
}

void    GpLogger::Log
(
    std::string_view                aMessage,
    const GpLogLevel::EnumT         aLevel,
    std::string_view                aCategory,
    std::string_view                aChainId,
    const GpLogConsumeMode::EnumT   aConsumeMode
)
{
    const auto iter = iCategoryLevels.find(aCategory);

    std::string         category;
    GpLogLevel::EnumT   maxLevel;

    if (iter == iCategoryLevels.end())
    {
        category    = std::string("default"_sv);
        maxLevel    = iDefaultLevel;
    } else
    {
        category    = aCategory;
        maxLevel    = iter->second.Value();
    }

    if (int(aLevel) < int(maxLevel))
    {
        return;
    }

    GpTaskFiber::SP currentTask = GpTaskFiber::SCurrentTask();

    GpLogElement logElement
    (
        GpDateTimeOps::SUnixTS_ms(),
        GpDateTimeOps::SSteadyTS_us() - iStartSteadyTS,
        std::this_thread::get_id(),
        currentTask.IsNotNULL() ? std::string(currentTask->Name()) : std::string(""_sv),
        aLevel,
        std::move(category),
        std::string(aMessage),
        aConsumeMode
    );

    iLogExecutor->AddElement(aChainId, std::move(logElement));
}

}//namespace GPlatform
