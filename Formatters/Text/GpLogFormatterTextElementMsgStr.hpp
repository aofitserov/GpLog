#pragma once

#include "../../GpLog_global.hpp"

namespace GPlatform {

class GPLOG_API GpLogFormatterTextElementMsgStr final: public GpByteSerializer
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpLogFormatterTextElementMsgStr)
    CLASS_DECLARE_DEFAULTS(GpLogFormatterTextElementMsgStr)

public:
                            GpLogFormatterTextElementMsgStr     (void) noexcept;
    virtual                 ~GpLogFormatterTextElementMsgStr    (void) noexcept override final;

    virtual void            Format                              (const std::any&    aObject,
                                                                 GpByteWriter&      aWriter) const override final;
};

}//namespace GPlatform
