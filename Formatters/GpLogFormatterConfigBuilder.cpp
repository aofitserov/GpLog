#include "GpLogFormatterConfigBuilder.hpp"

#include "Elements/GpLogElementMsgStr.hpp"
#include "Elements/GpLogElementMsgStrFn.hpp"
#include "Elements/GpLogElementMsgMarkTraceTS.hpp"

#include "Text/GpLogFormatterTextFactory.hpp"
#include "Text/GpLogFormatterTextElementMsgStr.hpp"
#include "Text/GpLogFormatterTextElementMsgStrFn.hpp"
#include "Text/GpLogFormatterTextElementMsgMarkTraceTS.hpp"

namespace GPlatform {

GpByteSerializerFactory::SP GpLogFormatterConfigBuilder::SFromConfig (const GpLogFormatterConfigDesc& aConfigDesc)
{
    if (aConfigDesc.text.IsNotNULL())
    {
        GpLogElementFormatter logElementFormatter;
        logElementFormatter.Register(std::type_index(typeid(GpLogElementMsgStr)),           GpLogFormatterTextElementMsgStr::SP::SNew());
        logElementFormatter.Register(std::type_index(typeid(GpLogElementMsgStrFn)),         GpLogFormatterTextElementMsgStrFn::SP::SNew());
        logElementFormatter.Register(std::type_index(typeid(GpLogElementMsgMarkTraceTS)),   GpLogFormatterTextElementMsgMarkTraceTS::SP::SNew());

        return MakeSP<GpLogFormatterTextFactory>
        (
            aConfigDesc.text.VC(),
            logElementFormatter
        );
    } else
    {
        THROW_GPE("No log formatters was found in config"_sv);
    }
}

}//namespace GPlatform
