#include "GpLogFormatterTextConfigDesc.hpp"

namespace GPlatform {

GP_ENUM_IMPL(GpLogFieldType);

TYPE_STRUCT_IMPLEMENT(GpLogFormatterTextConfigDesc, GP_MODULE_UUID)

GpLogFormatterTextConfigDesc::GpLogFormatterTextConfigDesc (void) noexcept
{
}

GpLogFormatterTextConfigDesc::GpLogFormatterTextConfigDesc (const GpLogFormatterTextConfigDesc& aDesc)
    : fields(aDesc.fields)
{
}

GpLogFormatterTextConfigDesc::~GpLogFormatterTextConfigDesc (void) noexcept
{
}

void    GpLogFormatterTextConfigDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(fields);
}

}//namespace GPlatform
