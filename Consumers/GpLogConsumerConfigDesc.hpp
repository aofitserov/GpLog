#pragma once

#include "../GpLog_global.hpp"
#include "Console/GpLogConsumerConsoleConfigDesc.hpp"
#include "File/GpLogConsumerFileConfigDesc.hpp"

namespace GPlatform {

class GPLOG_API GpLogConsumerConfigDesc final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_MOVE(GpLogConsumerConfigDesc);
    CLASS_DECLARE_DEFAULTS(GpLogConsumerConfigDesc)
    TYPE_STRUCT_DECLARE("33ba916e-e102-4086-a5f3-7f727ee2262d"_sv)

public:
                                        GpLogConsumerConfigDesc     (void) noexcept;
    virtual                             ~GpLogConsumerConfigDesc    (void) noexcept override final;

public:
    GpLogConsumerConsoleConfigDesc::SP  console;
    GpLogConsumerFileConfigDesc::SP     file;
};

}//namespace GPlatform
