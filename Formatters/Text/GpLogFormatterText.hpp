#pragma once

#include "GpLogFormatterTextConfigDesc.hpp"
#include "../../GpLogLevel.hpp"
#include "../../Formatters/GpLogElementFormatter.hpp"

namespace GPlatform {

class GpLogElementMsg;

class GPLOG_API GpLogFormatterText final: public GpByteSerializer
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpLogFormatterText)
    CLASS_DECLARE_DEFAULTS(GpLogFormatterText)

public:
                            GpLogFormatterText  (const GpLogFormatterTextConfigDesc&    aConfigDesc,
                                                 const GpLogElementFormatter&           aElementFormatter);
    virtual                 ~GpLogFormatterText (void) noexcept override final;

    virtual void            Format              (const std::any&    aObject,
                                                 GpByteWriter&      aWriter) const override final;

private:
    void                    WriteLevel          (const GpLogLevel::EnumT    aLevel,
                                                 GpByteWriter&              aWriter) const;
    void                    WriteThreadId       (const std::thread::id&     aThreadId,
                                                 GpByteWriter&              aWriter) const;
    void                    WriteTaskName       (std::string_view           aTaskName,
                                                 GpByteWriter&              aWriter) const;
    void                    WriteCategory       (std::string_view           aCategory,
                                                 GpByteWriter&              aWriter) const;
    void                    WriteUnixTS         (const unix_ts_ms_t         aUnixTS,
                                                 GpByteWriter&              aWriter) const;
    void                    WriteSteadyTS       (const microseconds_t       aSteadyTS,
                                                 GpByteWriter&              aWriter) const;
    void                    WriteMessage        (const GpLogElementMsg&     aMessage,
                                                 GpByteWriter&              aWriter) const;

private:
    const GpLogFormatterTextConfigDesc                                      iConfigDesc;
    const GpLogElementFormatter                                             iElementFormatter;
    static const GpArray<std::string, GpLogLevel::SCount().As<size_t>()>    sLevels;
};

}//namespace GPlatform
