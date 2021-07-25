#pragma once

#include "../GpLogChain.hpp"

namespace GPlatform {

class GPLOG_API GpLogFormatter
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpLogFormatter)
    CLASS_DECLARE_DEFAULTS(GpLogFormatter)

protected:
                            GpLogFormatter  (void) noexcept;

public:
    virtual                 ~GpLogFormatter (void) noexcept;

    virtual void            Format          (const GpLogChain&  aLogChain,
                                             GpByteWriter&      aWriter) const = 0;
};

}//namespace GPlatform
