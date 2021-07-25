#pragma once

#include "GpLogFormatter.hpp"

namespace GPlatform {

class GPLOG_API GpLogFormatterFactory
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpLogFormatterFactory)
    CLASS_DECLARE_DEFAULTS(GpLogFormatterFactory)

public:
                                GpLogFormatterFactory   (void) noexcept;
    virtual                     ~GpLogFormatterFactory  (void) noexcept;

    virtual GpLogFormatter::SP  NewInstance             (void) const = 0;
};

}//namespace GPlatform
