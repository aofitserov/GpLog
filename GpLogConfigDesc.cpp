#include "GpLogConfigDesc.hpp"

namespace GPlatform {

TYPE_STRUCT_IMPLEMENT(GpLogConfigDesc, GP_MODULE_UUID)

GpLogConfigDesc::GpLogConfigDesc (void) noexcept
{
}

GpLogConfigDesc::~GpLogConfigDesc (void) noexcept
{
}

void    GpLogConfigDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(default_level);
    PROP(category_levels);
    PROP(consumers);
}

}//namespace GPlatform
