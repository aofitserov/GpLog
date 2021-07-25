#include "GpLogConsumerFactory.hpp"

namespace GPlatform {

GpLogConsumerFactory::GpLogConsumerFactory (GpLogFormatter::SP aFormatter) noexcept:
iFormatter(std::move(aFormatter))
{
}

GpLogConsumerFactory::~GpLogConsumerFactory (void) noexcept
{
}

}//namespace GPlatform
