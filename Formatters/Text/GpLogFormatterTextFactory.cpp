#include "GpLogFormatterTextFactory.hpp"
#include "GpLogFormatterText.hpp"

namespace GPlatform {

GpLogFormatterTextFactory::GpLogFormatterTextFactory (void)
{
}

GpLogFormatterTextFactory::GpLogFormatterTextFactory (const GpLogFormatterTextConfigDesc& /*aConfigDesc*/)
{
}

GpLogFormatterTextFactory::~GpLogFormatterTextFactory (void) noexcept
{
}

GpLogFormatter::SP  GpLogFormatterTextFactory::NewInstance (void) const
{
    return MakeSP<GpLogFormatterText>();
}

}//namespace GPlatform
