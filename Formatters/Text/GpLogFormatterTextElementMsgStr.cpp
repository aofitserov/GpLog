#include "GpLogFormatterTextElementMsgStr.hpp"
#include "../../Elements/GpLogElementMsgStr.hpp"

namespace GPlatform {

GpLogFormatterTextElementMsgStr::GpLogFormatterTextElementMsgStr (void) noexcept
{
}

GpLogFormatterTextElementMsgStr::~GpLogFormatterTextElementMsgStr (void) noexcept
{
}

void    GpLogFormatterTextElementMsgStr::Format
(
    const std::any& aObject,
    GpByteWriter&   aWriter
) const
{
    const GpLogElementMsgStr& e = static_cast<const GpLogElementMsgStr&>
    (
        std::any_cast<std::reference_wrapper<const GpLogElementMsg>>(aObject).get()
    );

    aWriter.Bytes(e.Message());
}

}//namespace GPlatform
