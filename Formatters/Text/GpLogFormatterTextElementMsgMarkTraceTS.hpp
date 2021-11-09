#pragma once

#include "../../GpLog_global.hpp"

namespace GPlatform {

class GPLOG_API GpLogFormatterTextElementMsgMarkTraceTS final: public GpByteSerializer
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpLogFormatterTextElementMsgMarkTraceTS)
    CLASS_DECLARE_DEFAULTS(GpLogFormatterTextElementMsgMarkTraceTS)

public:
                            GpLogFormatterTextElementMsgMarkTraceTS     (void) noexcept;
    virtual                 ~GpLogFormatterTextElementMsgMarkTraceTS    (void) noexcept override final;

    virtual void            Format                                      (const std::any&    aObject,
                                                                         GpByteWriter&      aWriter) const override final;
};

}//namespace GPlatform
