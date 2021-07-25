#pragma once

#include "GpLogConsumerFactory.hpp"
#include "GpLogConsumerConfigDesc.hpp"

namespace GPlatform {

class GPLOG_API GpLogConsumerConfigBuilder
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpLogConsumerConfigBuilder)
    CLASS_DECLARE_DEFAULTS(GpLogConsumerConfigBuilder)

public:
    static GpLogConsumerFactory::C::Vec::SP     SFromConfig (const GpLogConsumerConfigDesc& aConfigDesc);
};

}//namespace GPlatform
