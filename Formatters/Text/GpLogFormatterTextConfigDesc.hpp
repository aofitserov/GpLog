#pragma once

#include "../../GpLog_global.hpp"

namespace GPlatform {

class GPLOG_API GpLogFormatterTextConfigDesc final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_MOVE(GpLogFormatterTextConfigDesc);
    CLASS_DECLARE_DEFAULTS(GpLogFormatterTextConfigDesc)
    TYPE_STRUCT_DECLARE("5d2d48f9-9047-4bac-a021-4dd495f3479f"_sv)

public:
                        GpLogFormatterTextConfigDesc    (void) noexcept;
    virtual             ~GpLogFormatterTextConfigDesc   (void) noexcept override final;

public:
};

}//namespace GPlatform
