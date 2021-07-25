#pragma once

#include "GpLogLevel.hpp"
#include "Formatters/GpLogFormatterConfigDesc.hpp"
#include "Consumers/GpLogConsumerConfigDesc.hpp"

namespace GPlatform {

class GPLOG_API GpLogConfigDesc final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpLogConfigDesc);
    CLASS_DECLARE_DEFAULTS(GpLogConfigDesc)
    TYPE_STRUCT_DECLARE("f007fab7-abbf-4ced-a230-0d6c18a73bdd"_sv)

    using CategoryLevelsT   = GpMap<std::string, std::string, std::less<>>;

public:
                            GpLogConfigDesc     (void) noexcept;
    virtual                 ~GpLogConfigDesc    (void) noexcept override final;

public:
    GpLogLevel              default_level   = GpLogLevel::INFO;
    CategoryLevelsT         category_levels;
    GpLogConsumerConfigDesc consumers;
};

}//namespace GPlatform
