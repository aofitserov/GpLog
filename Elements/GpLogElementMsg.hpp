#pragma once

#include "../GpLogLevel.hpp"
#include "../GpLogConsumeMode.hpp"

namespace GPlatform {

class GPLOG_API GpLogElementMsg
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpLogElementMsg)
    CLASS_DECLARE_DEFAULTS(GpLogElementMsg)

protected:
                                GpLogElementMsg     (void) noexcept = default;

public:
    virtual                     ~GpLogElementMsg    (void) noexcept = default;
};

}//namespace GPlatform
