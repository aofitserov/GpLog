#include "GpLogConsumerConsoleConfigDesc.hpp"

namespace GPlatform {

TYPE_STRUCT_IMPLEMENT(GpLogConsumerConsoleConfigDesc, GP_MODULE_UUID)

GpLogConsumerConsoleConfigDesc::GpLogConsumerConsoleConfigDesc (void) noexcept
{
}

GpLogConsumerConsoleConfigDesc::~GpLogConsumerConsoleConfigDesc (void) noexcept
{
}

void    GpLogConsumerConsoleConfigDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(formatter);
}

}//namespace GPlatform
