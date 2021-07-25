#pragma once

#include "GpLogFormatterFactory.hpp"
#include "GpLogFormatterConfigDesc.hpp"

namespace GPlatform {

class GPLOG_API GpLogFormatterConfigBuilder
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpLogFormatterConfigBuilder)
    CLASS_DECLARE_DEFAULTS(GpLogFormatterConfigBuilder)

public:
    static GpLogFormatterFactory::SP    SFromConfig (const GpLogFormatterConfigDesc& aConfigDesc);
};

}//namespace GPlatform
