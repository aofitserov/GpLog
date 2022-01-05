#include "GpLogBuilder.hpp"

namespace GPlatform {

void    GpLogBuilder::Out (void)
{
    GpLogger::S().Log
    (
        std::move(iMessage),
        iLevel,
        std::move(iCategory),
        std::move(iChainId),
        iConsumeMode
    );
}

void    GpLogBuilder::SEndChain (std::string_view aChainId)
{
    GpLogger::S().EndChain(aChainId);
}

}//namespace GPlatform
