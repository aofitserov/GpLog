#pragma once

#include "GpLogFormatterTextConfigDesc.hpp"
#include "../../Formatters/GpLogElementFormatter.hpp"

namespace GPlatform {

class GPLOG_API GpLogFormatterTextFactory final: public GpByteSerializerFactory
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpLogFormatterTextFactory)
    CLASS_DECLARE_DEFAULTS(GpLogFormatterTextFactory)

public:
                                        GpLogFormatterTextFactory   (const GpLogFormatterTextConfigDesc&    aConfigDesc,
                                                                     const GpLogElementFormatter&           aElementFormatter);
    virtual                             ~GpLogFormatterTextFactory  (void) noexcept override final;

    virtual GpByteSerializer::SP        NewInstance                 (void) const override final;

private:
    const GpLogFormatterTextConfigDesc  iConfigDesc;
    const GpLogElementFormatter         iElementFormatter;
};

}//namespace GPlatform
