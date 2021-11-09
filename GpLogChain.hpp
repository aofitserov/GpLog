#pragma once

#include "Elements/GpLogElements.hpp"

namespace GPlatform {

class GPLOG_API GpLogChain
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpLogChain)
    CLASS_DECLARE_DEFAULTS(GpLogChain)

    using ElementsT = GpLogElement::C::Vec::Val;

public:
                                    GpLogChain      (std::string&& aChainId) noexcept;
                                    ~GpLogChain     (void) noexcept;

    std::string_view                ChainId         (void) const noexcept {return iChainId;}
    void                            AddElement      (GpLogElement&& aElement);
    const ElementsT&                Elements        (void) const {return iElements;}

private:
    mutable GpSpinlock              iLock;
    const std::string               iChainId;
    ElementsT                       iElements;
};

}//namespace GPlatform
