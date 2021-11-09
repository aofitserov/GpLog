#pragma once

#include "../GpLogConsumerFactory.hpp"
#include "GpLogConsumerConsoleConfigDesc.hpp"

namespace GPlatform {

class GPLOG_API GpLogConsumerConsoleFactory final: public GpLogConsumerFactory
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpLogConsumerConsoleFactory)
    CLASS_DECLARE_DEFAULTS(GpLogConsumerConsoleFactory)

public:
                                GpLogConsumerConsoleFactory     (GpByteSerializer::SP aFormatter) noexcept;
                                GpLogConsumerConsoleFactory     (const GpLogConsumerConsoleConfigDesc& aConfigDesc);
    virtual                     ~GpLogConsumerConsoleFactory    (void) noexcept override final;

    virtual GpLogConsumer::SP   NewInstance                     (void) const override final;
};

}//namespace GPlatform
