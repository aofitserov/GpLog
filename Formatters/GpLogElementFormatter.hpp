#pragma once

#include "../GpLog_global.hpp"
#include <typeindex>

namespace GPlatform {

class GPLOG_API GpLogElementFormatter
{
public:
    CLASS_DECLARE_DEFAULTS(GpLogElementFormatter)

public:
                                    GpLogElementFormatter   (void) noexcept;
                                    GpLogElementFormatter   (const GpLogElementFormatter& aFormatter);
                                    GpLogElementFormatter   (GpLogElementFormatter&& aFormatter) noexcept;
    virtual                         ~GpLogElementFormatter  (void) noexcept;

    void                            Register                (const std::type_index  aTypeIndex,
                                                             GpByteSerializer::SP   aFormatter);
    const GpByteSerializer&         Find                    (const std::type_index  aTypeIndex) const;

private:
    GpMap<std::type_index, GpByteSerializer::SP>    iFormatters;
};

}//namespace GPlatform
