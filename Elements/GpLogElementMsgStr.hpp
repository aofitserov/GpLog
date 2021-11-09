#pragma once

#include "GpLogElementMsg.hpp"

namespace GPlatform {

class GPLOG_API GpLogElementMsgStr final: public GpLogElementMsg
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpLogElementMsgStr)
    CLASS_DECLARE_DEFAULTS(GpLogElementMsgStr)

public:
    inline                      GpLogElementMsgStr  (std::string_view aMessage);
    inline                      GpLogElementMsgStr  (std::string&& aMessage) noexcept;
    virtual                     ~GpLogElementMsgStr (void) noexcept override final;

    std::string_view            Message             (void) const noexcept {return iMessage;}

private:
    std::string                 iMessage;
};

GpLogElementMsgStr::GpLogElementMsgStr (std::string_view aMessage):
iMessage(aMessage)
{
}

GpLogElementMsgStr::GpLogElementMsgStr (std::string&& aMessage) noexcept:
iMessage(std::move(aMessage))
{
}

}//namespace GPlatform
