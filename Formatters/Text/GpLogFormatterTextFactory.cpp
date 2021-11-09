#include "GpLogFormatterTextFactory.hpp"
#include "GpLogFormatterText.hpp"

namespace GPlatform {

GpLogFormatterTextFactory::GpLogFormatterTextFactory
(
    const GpLogFormatterTextConfigDesc& aConfigDesc,
    const GpLogElementFormatter&        aElementFormatter
):
iConfigDesc(aConfigDesc),
iElementFormatter(aElementFormatter)
{
}

GpLogFormatterTextFactory::~GpLogFormatterTextFactory (void) noexcept
{
}

GpByteSerializer::SP    GpLogFormatterTextFactory::NewInstance (void) const
{
    return MakeSP<GpLogFormatterText>(iConfigDesc, iElementFormatter);
}

}//namespace GPlatform
