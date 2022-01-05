#pragma once

#include "../../GpLog_global.hpp"

namespace GPlatform {

class GPLOG_API GpLogFormatterTextElementMsgStrFn final: public GpByteSerializer
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpLogFormatterTextElementMsgStrFn)
    CLASS_DECLARE_DEFAULTS(GpLogFormatterTextElementMsgStrFn)

public:
                            GpLogFormatterTextElementMsgStrFn   (void) noexcept;
    virtual                 ~GpLogFormatterTextElementMsgStrFn  (void) noexcept override final;

    virtual void            Format                              (const std::any&    aObject,
                                                                 GpByteWriter&      aWriter) const override final;
};

}//namespace GPlatform
