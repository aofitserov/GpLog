#include "GpLogFormatterConfigDesc.hpp"

namespace GPlatform {

TYPE_STRUCT_IMPLEMENT(GpLogFormatterConfigDesc, GP_MODULE_UUID)

GpLogFormatterConfigDesc::GpLogFormatterConfigDesc (void) noexcept
{
}

GpLogFormatterConfigDesc::~GpLogFormatterConfigDesc (void) noexcept
{
}

void    GpLogFormatterConfigDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(text);
}

}//namespace GPlatform
