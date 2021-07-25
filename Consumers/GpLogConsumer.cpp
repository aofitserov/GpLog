#include "GpLogConsumer.hpp"

namespace GPlatform {

GpLogConsumer::GpLogConsumer (GpLogFormatter::SP aFormatter) noexcept:
iFormatter(std::move(aFormatter))
{
}

GpLogConsumer::~GpLogConsumer (void) noexcept
{
}

}//namespace GPlatform
