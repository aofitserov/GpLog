#include "GpLogChain.hpp"

namespace GPlatform {

GpLogChain::GpLogChain (std::string&& aChainId) noexcept:
iChainId(std::move(aChainId))
{
}

GpLogChain::~GpLogChain (void) noexcept
{
}

void    GpLogChain::AddElement (GpLogElement&& aElement)
{
    std::scoped_lock lock(iLock);

    if (iElements.size() == 0)
    {
        iElements.reserve(32);
    }

    iElements.emplace_back(std::move(aElement));
}

}//namespace GPlatform
