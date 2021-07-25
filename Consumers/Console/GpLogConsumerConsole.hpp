#pragma once

#include "../GpLogConsumer.hpp"

namespace GPlatform {

class GpLogConsumerConsole final: public GpLogConsumer
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpLogConsumerConsole)
    CLASS_DECLARE_DEFAULTS(GpLogConsumerConsole)

public:
                            GpLogConsumerConsole    (GpLogFormatter::SP aFormatter) noexcept;
    virtual                 ~GpLogConsumerConsole   (void) noexcept override final;

    virtual void            Consume                 (GpLogChain::CSP aLogChain) override final;
    virtual void            OnFlush                 (void) noexcept override final;
};

}//namespace GPlatform
