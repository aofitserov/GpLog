#include "GpLogElementFormatter.hpp"

namespace GPlatform {

GpLogElementFormatter::GpLogElementFormatter (void) noexcept
{
}

GpLogElementFormatter::GpLogElementFormatter (const GpLogElementFormatter& aFormatter):
iFormatters(aFormatter.iFormatters)
{
}

GpLogElementFormatter::GpLogElementFormatter (GpLogElementFormatter&& aFormatter) noexcept:
iFormatters(std::move(aFormatter.iFormatters))
{
}

GpLogElementFormatter::~GpLogElementFormatter (void) noexcept
{
}

void    GpLogElementFormatter::Register
(
    const std::type_index   aTypeIndex,
    GpByteSerializer::SP    aFormatter
)
{
    iFormatters.emplace(aTypeIndex, std::move(aFormatter));
}

const GpByteSerializer& GpLogElementFormatter::Find (const std::type_index aTypeIndex) const
{
    auto iter = iFormatters.find(aTypeIndex);

    if (iter != iFormatters.end())
    {
        return iter->second.VCn();
    } else
    {
        THROW_GPE("Formetter not found for type "_sv + aTypeIndex.name());
    }
}

}//namespace GPlatform
