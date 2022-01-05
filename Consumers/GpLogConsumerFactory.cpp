#include "GpLogConsumerFactory.hpp"

namespace GPlatform {

GpLogConsumerFactory::GpLogConsumerFactory (GpByteSerializer::SP aFormatter) noexcept:
iFormatter(std::move(aFormatter))
{
}

GpLogConsumerFactory::~GpLogConsumerFactory (void) noexcept
{
}

}//namespace GPlatform
