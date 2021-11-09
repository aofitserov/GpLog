#include "GpLogFormatterTextConfigDesc.hpp"

namespace GPlatform {

TYPE_STRUCT_IMPLEMENT(GpLogFormatterTextConfigDesc, GP_MODULE_UUID)

GpLogFormatterTextConfigDesc::GpLogFormatterTextConfigDesc (void) noexcept
{
}

GpLogFormatterTextConfigDesc::GpLogFormatterTextConfigDesc (const GpLogFormatterTextConfigDesc& /*aDesc*/)
{
}

GpLogFormatterTextConfigDesc::~GpLogFormatterTextConfigDesc (void) noexcept
{
}

void    GpLogFormatterTextConfigDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& /*aPropsOut*/)
{
    //PROP();
}

}//namespace GPlatform
