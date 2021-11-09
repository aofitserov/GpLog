#include "GpLogConsumer.hpp"

namespace GPlatform {

GpLogConsumer::GpLogConsumer (GpByteSerializer::SP aFormatter) noexcept:
iFormatter(std::move(aFormatter))
{
}

GpLogConsumer::~GpLogConsumer (void) noexcept
{
}

}//namespace GPlatform
