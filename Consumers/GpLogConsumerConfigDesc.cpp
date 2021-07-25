#include "GpLogConsumerConfigDesc.hpp"

namespace GPlatform {

TYPE_STRUCT_IMPLEMENT(GpLogConsumerConfigDesc, GP_MODULE_UUID)

GpLogConsumerConfigDesc::GpLogConsumerConfigDesc (void) noexcept
{
}

GpLogConsumerConfigDesc::~GpLogConsumerConfigDesc (void) noexcept
{
}

void    GpLogConsumerConfigDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(console);
    PROP(file);
}

}//namespace GPlatform
