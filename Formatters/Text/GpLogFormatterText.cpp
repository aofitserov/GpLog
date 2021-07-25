#include "GpLogFormatterText.hpp"
#include <sstream>

namespace GPlatform {

const GpArray<std::string, GpLogLevel::SCount().As<size_t>()>   GpLogFormatterText::sLevels =
{
    std::string("[D]"_sv),
    std::string("[I]"_sv),
    std::string("[W]"_sv),
    std::string("[E]"_sv),
    std::string("[!]"_sv)
};

GpLogFormatterText::GpLogFormatterText (void) noexcept
{
}

GpLogFormatterText::~GpLogFormatterText (void) noexcept
{
}

void    GpLogFormatterText::Format
(
    const GpLogChain&   aLogChain,
    GpByteWriter&       aWriter
) const
{
    const GpLogElement::C::Vec::Val& chainElements = aLogChain.Elements();

    //Separator (begin)
    std::string_view chainId = aLogChain.ChainId();
    if (chainId.length() > 0)
    {
        aWriter
            .Bytes("-------------------------------------- Begin: "_sv)
            .Bytes(chainId)
            .Bytes(" --------------------------------------\n"_sv);
    } else
    {
        aWriter
            .Bytes("-------------------------------------- Begin --------------------------------------\n"_sv);
    }

    for (const GpLogElement& element: chainElements)
    {
        WriteLevel(element.Level(), aWriter);
        WriteUnixTS(element.UnixTS(), aWriter);
        WriteSteadyTS(element.SteadyTS(), aWriter);
        WriteThreadId(element.ThreadId(), aWriter);
        WriteTaskName(element.TaskName(), aWriter);
        WriteCategory(element.Category(), aWriter);     
        WriteMessage(element.Message(), aWriter);

        aWriter.
            Bytes("\n"_sv);
    }

    //Separator (end)
    if (chainId.length() > 0)
    {
        aWriter
            .Bytes("-------------------------------------- End: "_sv)
            .Bytes(chainId)
            .Bytes(" --------------------------------------\n"_sv);
    } else
    {
        aWriter
            .Bytes("-------------------------------------- End --------------------------------------\n"_sv);
    }
}

void    GpLogFormatterText::WriteLevel
(
    const GpLogLevel::EnumT aLevel,
    GpByteWriter&           aWriter
) const
{
    aWriter
        .Bytes(GpLogFormatterText::sLevels.at(int(aLevel)));
}

void    GpLogFormatterText::WriteThreadId
(
    const std::thread::id&  aThreadId,
    GpByteWriter&           aWriter
) const
{
    std::ostringstream s;
    s << aThreadId;

    aWriter
        .Bytes(" ThreadID: "_sv)
        .Bytes(s.str());
}

void    GpLogFormatterText::WriteTaskName
(
    std::string_view    aTaskName,
    GpByteWriter&       aWriter
) const
{
    aWriter
        .Bytes(", task: '"_sv)
        .Bytes(aTaskName)
        .Bytes("'"_sv);
}

void    GpLogFormatterText::WriteCategory
(
    std::string_view    aCategory,
    GpByteWriter&       aWriter
) const
{
    aWriter
        .Bytes(", category: '"_sv)
        .Bytes(aCategory)
        .Bytes("'"_sv);
}

void    GpLogFormatterText::WriteUnixTS
(
    const unix_ts_ms_t  aUnixTS,
    GpByteWriter&       aWriter
) const
{
    const std::string str = GpDateTimeOps::SUnixTsToStr(aUnixTS, GpDateTimeFormat::STD_DATE_TIME);

    aWriter
        .Bytes("(TS: "_sv)
        .Bytes(str);
}

void    GpLogFormatterText::WriteSteadyTS
(
    const microseconds_t    aSteadyTS,
    GpByteWriter&           aWriter
) const
{
    const std::string str = StrOps::SFromDouble(aSteadyTS.Value());

    aWriter
        .Bytes(", steady TS: "_sv)
        .Bytes(str)
        .Bytes("us)"_sv);
}

void    GpLogFormatterText::WriteMessage
(
    std::string_view    aMessage,
    GpByteWriter&       aWriter
) const
{
    aWriter
        .Bytes("\n"_sv)
        .Bytes(aMessage);
}

}//namespace GPlatform
