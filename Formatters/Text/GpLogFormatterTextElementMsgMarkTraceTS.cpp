#include "GpLogFormatterTextElementMsgMarkTraceTS.hpp"
#include "../../Elements/GpLogElementMsgMarkTraceTS.hpp"

namespace GPlatform {

GpLogFormatterTextElementMsgMarkTraceTS::GpLogFormatterTextElementMsgMarkTraceTS (void) noexcept
{
}

GpLogFormatterTextElementMsgMarkTraceTS::~GpLogFormatterTextElementMsgMarkTraceTS (void) noexcept
{
}

void    GpLogFormatterTextElementMsgMarkTraceTS::Format
(
    const std::any& aObject,
    GpByteWriter&   aWriter
) const
{
    const GpLogElementMsgMarkTraceTS& e = static_cast<const GpLogElementMsgMarkTraceTS&>
    (
        std::any_cast<std::reference_wrapper<const GpLogElementMsg>>(aObject).get()
    );

    const GpMarkTraceTS&            markTraceTS = e.MarkTraceTS();
    const GpMarkTS::C::Vec::Val&    marks       = markTraceTS.Marks();

    size_t          tsId        = 0;
    microseconds_t  nowHiResTs  = 0.0_si_us;
    microseconds_t  prevHiResTs = 0.0_si_us;
    microseconds_t  duration    = 0.0_si_us;
    microseconds_t  delta       = 0.0_si_us;

    for (const GpMarkTS& mark: marks)
    {
        std::string str;

        if (tsId > 0)
        {
            aWriter.Bytes("\n"_sv);
        }

        //id
        tsId++;
        str = StrOps::SFromUI64(u_int_64(tsId));
        aWriter
            .Bytes("["_sv)
            .Bytes(str)
            .Bytes("]: STS: "_sv);

        //steady ts
        str = StrOps::SFromDouble(mark.SteadyTS().As<seconds_t>().Value());
        aWriter
            .Bytes(str)
            .Bytes("s, D: "_sv);

        //Delta
        nowHiResTs = mark.HiResTS();

        if (tsId <= 1)
        {
            prevHiResTs = nowHiResTs;
            delta       = 0.0_si_s;
        } else
        {
            delta       = nowHiResTs - prevHiResTs;
        }

        prevHiResTs = nowHiResTs;
        duration   += delta;

        //Duration
        str = StrOps::SFromDouble(duration.As<seconds_t>().Value());
        aWriter
            .Bytes(str)
            .Bytes("s: "_sv);

        //Comment
        aWriter
            .Bytes(mark.Comment());

        //Source location
        const auto& sourceLocation = mark.SourceLocation();

        if (sourceLocation.has_value())
        {
            const SourceLocationT& sl = sourceLocation.value();

            aWriter
                .Bytes("    Function: '"_sv)
                .Bytes(std::string_view(sl.function_name()))
                .Bytes("', file '"_sv)
                .Bytes(std::string_view(sl.file_name()))
                .Bytes("', line "_sv)
                .Bytes(StrOps::SFromUI64(sl.line()));
        }
    }
}

}//namespace GPlatform
