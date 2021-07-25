#include "GpLogConsumerConfigBuilder.hpp"
#include "Console/GpLogConsumerConsoleFactory.hpp"
#include "File/GpLogConsumerFileFactory.hpp"

namespace GPlatform {

GpLogConsumerFactory::C::Vec::SP    GpLogConsumerConfigBuilder::SFromConfig (const GpLogConsumerConfigDesc& aConfigDesc)
{
    GpLogConsumerFactory::C::Vec::SP consumerFactories;

    //Console
    if (aConfigDesc.console.IsNotNULL())
    {
        consumerFactories.emplace_back(MakeSP<GpLogConsumerConsoleFactory>(aConfigDesc.console.VC()));
    }

    //File
    if (aConfigDesc.file.IsNotNULL())
    {
        consumerFactories.emplace_back(MakeSP<GpLogConsumerFileFactory>(aConfigDesc.file.VC()));
    }

    return consumerFactories;
}

}//namespace GPlatform
