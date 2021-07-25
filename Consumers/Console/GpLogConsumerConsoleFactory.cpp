#include "GpLogConsumerConsoleFactory.hpp"
#include "GpLogConsumerConsole.hpp"
#include "../../Formatters/GpLogFormatterConfigBuilder.hpp"

namespace GPlatform {

GpLogConsumerConsoleFactory::GpLogConsumerConsoleFactory (GpLogFormatter::SP aFormatter) noexcept:
GpLogConsumerFactory(std::move(aFormatter))
{
}

GpLogConsumerConsoleFactory::GpLogConsumerConsoleFactory (const GpLogConsumerConsoleConfigDesc& aConfigDesc):
GpLogConsumerConsoleFactory
(
    GpLogFormatterConfigBuilder::SFromConfig(aConfigDesc.formatter)->NewInstance()
)
{
}

GpLogConsumerConsoleFactory::~GpLogConsumerConsoleFactory (void) noexcept
{
}

GpLogConsumer::SP   GpLogConsumerConsoleFactory::NewInstance (void) const
{
    return MakeSP<GpLogConsumerConsole>(Formatter());
}

}//namespace GPlatform
