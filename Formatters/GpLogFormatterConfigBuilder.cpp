#include "GpLogFormatterConfigBuilder.hpp"
#include "Text/GpLogFormatterTextFactory.hpp"

namespace GPlatform {

GpLogFormatterFactory::SP   GpLogFormatterConfigBuilder::SFromConfig (const GpLogFormatterConfigDesc& aConfigDesc)
{
    if (aConfigDesc.text.IsNotNULL())
    {
        return MakeSP<GpLogFormatterTextFactory>(aConfigDesc.text.VC());
    } else
    {
        THROW_GPE("No log formatters was found in config"_sv);
    }
}

}//namespace GPlatform
