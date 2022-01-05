#pragma once

#include "../GpLogChain.hpp"

namespace GPlatform {

class GPLOG_API GpLogConsumer
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpLogConsumer)
    CLASS_DECLARE_DEFAULTS(GpLogConsumer)

protected:
                            GpLogConsumer   (GpByteSerializer::SP aFormatter) noexcept;

public:
    virtual                 ~GpLogConsumer  (void) noexcept;

    virtual void            Consume         (GpLogChain::CSP aLogChain) = 0;
    virtual void            OnFlush         (void) noexcept = 0;

protected:
    const GpByteSerializer& Formatter       (void) const noexcept {return iFormatter.VCn();}

private:
    GpByteSerializer::SP    iFormatter;
};

}//namespace GPlatform
