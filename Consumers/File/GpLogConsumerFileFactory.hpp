#pragma once

#include "../GpLogConsumerFactory.hpp"
#include "GpLogConsumerFileConfigDesc.hpp"

namespace GPlatform {

class GPLOG_API GpLogConsumerFileFactory final: public GpLogConsumerFactory
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpLogConsumerFileFactory)
    CLASS_DECLARE_DEFAULTS(GpLogConsumerFileFactory)

public:
                                    GpLogConsumerFileFactory    (std::string_view       aOutFilePath,
                                                                 std::string_view       aOutFilePrefix,
                                                                 const size_byte_t      aFileMaxSize,
                                                                 const milliseconds_t   aMaxFlushPeriod,
                                                                 const size_byte_t      aMaxBufferSize,
                                                                 GpLogFormatter::SP     aFormatter);
                                    GpLogConsumerFileFactory    (const GpLogConsumerFileConfigDesc& aConfigDesc);
    virtual                         ~GpLogConsumerFileFactory   (void) noexcept override final;

    virtual GpLogConsumer::SP       NewInstance                     (void) const override final;

private:
    const std::string               iOutFilePath;
    const std::string               iOutFilePrefix;
    const size_byte_t               iFileMaxSize;
    const milliseconds_t            iMaxFlushPeriod;
    const size_byte_t               iMaxBufferSize;
};

}//namespace GPlatform
