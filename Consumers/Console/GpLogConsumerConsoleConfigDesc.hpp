#pragma once

#include "../../GpLog_global.hpp"
#include "../../Formatters/GpLogFormatterConfigDesc.hpp"

namespace GPlatform {

class GPLOG_API GpLogConsumerConsoleConfigDesc final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_MOVE(GpLogConsumerConsoleConfigDesc);
    CLASS_DECLARE_DEFAULTS(GpLogConsumerConsoleConfigDesc)
    TYPE_STRUCT_DECLARE("76655e7d-b896-440b-a78d-6b77ba8f1384"_sv)

public:
                                GpLogConsumerConsoleConfigDesc  (void) noexcept;
    virtual                     ~GpLogConsumerConsoleConfigDesc (void) noexcept override final;

public:
    GpLogFormatterConfigDesc    formatter;
};

}//namespace GPlatform
