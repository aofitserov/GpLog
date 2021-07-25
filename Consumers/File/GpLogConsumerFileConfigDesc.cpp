#include "GpLogConsumerFileConfigDesc.hpp"

namespace GPlatform {

TYPE_STRUCT_IMPLEMENT(GpLogConsumerFileConfigDesc, GP_MODULE_UUID)

GpLogConsumerFileConfigDesc::GpLogConsumerFileConfigDesc (void) noexcept
{
}

GpLogConsumerFileConfigDesc::~GpLogConsumerFileConfigDesc (void) noexcept
{
}

void    GpLogConsumerFileConfigDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(out_file_path);
    PROP(out_file_prefix);
    PROP(file_max_size);
    PROP(max_flush_period);
    PROP(max_buffer_size);
    PROP(formatter);
}

}//namespace GPlatform
