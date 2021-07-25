#pragma once

#include "../GpLogFormatter.hpp"

namespace GPlatform {

class GpLogFormatterText final: public GpLogFormatter
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpLogFormatterText)
    CLASS_DECLARE_DEFAULTS(GpLogFormatterText)

public:
                            GpLogFormatterText  (void) noexcept;
    virtual                 ~GpLogFormatterText (void) noexcept override final;

    virtual void            Format              (const GpLogChain&  aLogChain,
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
    void                    WriteMessage        (std::string_view           aMessage,
                                                 GpByteWriter&              aWriter) const;

private:
    static const GpArray<std::string, GpLogLevel::SCount().As<size_t>()>    sLevels;
};

}//namespace GPlatform
