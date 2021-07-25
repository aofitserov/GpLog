#pragma once

#include "GpLogConsumer.hpp"

namespace GPlatform {

class GPLOG_API GpLogConsumerFactory
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpLogConsumerFactory)
    CLASS_DECLARE_DEFAULTS(GpLogConsumerFactory)

protected:
                                GpLogConsumerFactory    (GpLogFormatter::SP aFormatter) noexcept;

public:
    virtual                     ~GpLogConsumerFactory   (void) noexcept;

    virtual GpLogConsumer::SP   NewInstance             (void) const = 0;

protected:
    GpLogFormatter::SP          Formatter               (void) const noexcept {return iFormatter;}

private:
    GpLogFormatter::SP          iFormatter;
};

}//namespace GPlatform
