#pragma once

#include "GpLogElementMsg.hpp"

namespace GPlatform {

class GPLOG_API GpLogElementMsgMarkTraceTS final: public GpLogElementMsg
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpLogElementMsgMarkTraceTS)
    CLASS_DECLARE_DEFAULTS(GpLogElementMsgMarkTraceTS)

public:
    inline                      GpLogElementMsgMarkTraceTS  (const GpMarkTraceTS& aMarkTraceTS);
    inline                      GpLogElementMsgMarkTraceTS  (GpMarkTraceTS&& aMarkTraceTS) noexcept;
    virtual                     ~GpLogElementMsgMarkTraceTS (void) noexcept override final;

    const GpMarkTraceTS&        MarkTraceTS                 (void) const noexcept {return iMarkTraceTS;}

private:
    const GpMarkTraceTS         iMarkTraceTS;
};

GpLogElementMsgMarkTraceTS::GpLogElementMsgMarkTraceTS (const GpMarkTraceTS& aMarkTraceTS):
iMarkTraceTS(aMarkTraceTS)
{
}

GpLogElementMsgMarkTraceTS::GpLogElementMsgMarkTraceTS (GpMarkTraceTS&& aMarkTraceTS) noexcept:
iMarkTraceTS(std::move(aMarkTraceTS))
{
}

}//namespace GPlatform
