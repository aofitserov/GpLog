#include "GpLogFormatterTextElementMsgStrFn.hpp"
#include "../../Elements/GpLogElementMsgStrFn.hpp"

namespace GPlatform {

GpLogFormatterTextElementMsgStrFn::GpLogFormatterTextElementMsgStrFn (void) noexcept
{
}

GpLogFormatterTextElementMsgStrFn::~GpLogFormatterTextElementMsgStrFn (void) noexcept
{
}

void    GpLogFormatterTextElementMsgStrFn::Format
(
    const std::any& aObject,
    GpByteWriter&   aWriter
) const
{
    const GpLogElementMsgStrFn& e = static_cast<const GpLogElementMsgStrFn&>
    (
        std::any_cast<std::reference_wrapper<const GpLogElementMsg>>(aObject).get()
    );

    aWriter.Bytes(e.Message());
}

}//namespace GPlatform
