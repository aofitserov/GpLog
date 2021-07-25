#include "GpLogConsumerFileFactory.hpp"
#include "GpLogConsumerFile.hpp"
#include "../../Formatters/GpLogFormatterConfigBuilder.hpp"

namespace GPlatform {

GpLogConsumerFileFactory::GpLogConsumerFileFactory
(
    std::string_view        aOutFilePath,
    std::string_view        aOutFilePrefix,
    const size_byte_t       aFileMaxSize,
    const milliseconds_t    aMaxFlushPeriod,
    const size_byte_t       aMaxBufferSize,
    GpLogFormatter::SP      aFormatter
):
GpLogConsumerFactory(std::move(aFormatter)),
iOutFilePath(aOutFilePath),
iOutFilePrefix(aOutFilePrefix),
iFileMaxSize(aFileMaxSize),
iMaxFlushPeriod(aMaxFlushPeriod),
iMaxBufferSize(aMaxBufferSize)
{
}

GpLogConsumerFileFactory::GpLogConsumerFileFactory (const GpLogConsumerFileConfigDesc& aConfigDesc):
GpLogConsumerFileFactory
(
    aConfigDesc.out_file_path,
    aConfigDesc.out_file_prefix,
    aConfigDesc.file_max_size,
    aConfigDesc.max_flush_period,
    aConfigDesc.max_buffer_size,
    GpLogFormatterConfigBuilder::SFromConfig(aConfigDesc.formatter)->NewInstance()
)
{
}

GpLogConsumerFileFactory::~GpLogConsumerFileFactory (void) noexcept
{
}

GpLogConsumer::SP   GpLogConsumerFileFactory::NewInstance (void) const
{
    return MakeSP<GpLogConsumerFile>
    (
        iOutFilePath,
        iOutFilePrefix,
        iFileMaxSize,
        iMaxFlushPeriod,
        iMaxBufferSize,
        Formatter()
    );
}

}//namespace GPlatform
