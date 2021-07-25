#pragma once

#include "GpLogLevel.hpp"
#include "GpLogConsumeMode.hpp"

namespace GPlatform {

class GPLOG_API GpLogElement
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_COPY(GpLogElement)
    CLASS_DECLARE_DEFAULTS(GpLogElement)

public:
    inline                          GpLogElement    (const unix_ts_ms_t             aUnixTS,
                                                     const microseconds_t           aSteadyTS,
                                                     std::thread::id                aThreadId,
                                                     std::string&&                  aTaskName,
                                                     const GpLogLevel::EnumT        aLevel,
                                                     std::string&&                  aCategory,
                                                     std::string&&                  aMessage,
                                                     const GpLogConsumeMode::EnumT  aConsumeMode) noexcept;
    inline                          GpLogElement    (GpLogElement&& aElement) noexcept;
                                    ~GpLogElement   (void) noexcept;

    GpLogElement&                   operator=       (GpLogElement&& aElement) noexcept = delete;

    unix_ts_ms_t                    UnixTS          (void) const noexcept {return iUnixTS;}
    microseconds_t                  SteadyTS        (void) const noexcept {return iSteadyTS;}
    const std::thread::id&          ThreadId        (void) const noexcept {return iThreadId;}
    std::string_view                TaskName        (void) const noexcept {return iTaskName;}
    GpLogLevel::EnumT               Level           (void) const noexcept {return iLevel;}
    std::string_view                Category        (void) const noexcept {return iCategory;}
    std::string_view                Message         (void) const noexcept {return iMessage;}
    GpLogConsumeMode::EnumT         ConsumeMode     (void) const noexcept {return iConsumeMode;}

private:
    const unix_ts_ms_t              iUnixTS;
    const microseconds_t            iSteadyTS;
    const std::thread::id           iThreadId;
    const std::string               iTaskName;
    const GpLogLevel::EnumT         iLevel;
    const std::string               iCategory;
    const std::string               iMessage;
    const GpLogConsumeMode::EnumT   iConsumeMode;
};

GpLogElement::GpLogElement
(
    const unix_ts_ms_t              aUnixTS,
    const microseconds_t            aSteadyTS,
    std::thread::id                 aThreadId,
    std::string&&                   aTaskName,
    const GpLogLevel::EnumT         aLevel,
    std::string&&                   aCategory,
    std::string&&                   aMessage,
    const GpLogConsumeMode::EnumT   aConsumeMode
) noexcept:
iUnixTS(aUnixTS),
iSteadyTS(aSteadyTS),
iThreadId(aThreadId),
iTaskName(aTaskName),
iLevel(aLevel),
iCategory(std::move(aCategory)),
iMessage(std::move(aMessage)),
iConsumeMode(aConsumeMode)
{
}

GpLogElement::GpLogElement (GpLogElement&& aElement) noexcept:
iUnixTS(std::move(aElement.iUnixTS)),
iSteadyTS(std::move(aElement.iSteadyTS)),
iThreadId(std::move(aElement.iThreadId)),
iTaskName(std::move(aElement.iTaskName)),
iLevel(std::move(aElement.iLevel)),
iCategory(std::move(aElement.iCategory)),
iMessage(std::move(aElement.iMessage)),
iConsumeMode(std::move(aElement.iConsumeMode))
{
}

}//namespace GPlatform
