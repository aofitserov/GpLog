#pragma once

#include "../GpLogChain.hpp"
#include "../Formatters/GpLogFormatter.hpp"

namespace GPlatform {

class GPLOG_API GpLogConsumer
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpLogConsumer)
    CLASS_DECLARE_DEFAULTS(GpLogConsumer)

protected:
                            GpLogConsumer   (GpLogFormatter::SP aFormatter) noexcept;

public:
    virtual                 ~GpLogConsumer  (void) noexcept;

    virtual void            Consume         (GpLogChain::CSP aLogChain) = 0;
    virtual void            OnFlush         (void) noexcept = 0;

protected:
    const GpLogFormatter&   Formatter       (void) const {return iFormatter.VC();}

private:
    GpLogFormatter::SP      iFormatter;
};

}//namespace GPlatform
