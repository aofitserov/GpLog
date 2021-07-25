#pragma once

#include "../GpLogFormatterFactory.hpp"
#include "GpLogFormatterTextConfigDesc.hpp"

namespace GPlatform {

class GPLOG_API GpLogFormatterTextFactory final: public GpLogFormatterFactory
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpLogFormatterTextFactory)
    CLASS_DECLARE_DEFAULTS(GpLogFormatterTextFactory)

public:
                                    GpLogFormatterTextFactory   (void);
                                    GpLogFormatterTextFactory   (const GpLogFormatterTextConfigDesc& aConfigDesc);
    virtual                         ~GpLogFormatterTextFactory  (void) noexcept override final;

    virtual GpLogFormatter::SP      NewInstance                 (void) const override final;
};

}//namespace GPlatform
