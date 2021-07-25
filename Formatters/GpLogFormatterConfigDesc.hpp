#pragma once

#include "../GpLog_global.hpp"
#include "Text/GpLogFormatterTextConfigDesc.hpp"

namespace GPlatform {

class GPLOG_API GpLogFormatterConfigDesc final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_MOVE(GpLogFormatterConfigDesc);
    CLASS_DECLARE_DEFAULTS(GpLogFormatterConfigDesc)
    TYPE_STRUCT_DECLARE("e52b467e-d5f9-4c8c-9c66-0c7d13a695fe"_sv)

public:
                                        GpLogFormatterConfigDesc    (void) noexcept;
    virtual                             ~GpLogFormatterConfigDesc   (void) noexcept override final;

public:
    GpLogFormatterTextConfigDesc::SP    text;
};

}//namespace GPlatform
