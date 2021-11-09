#include "GpLogConsumerConsole.hpp"

#include <iostream>

namespace GPlatform {

GpLogConsumerConsole::GpLogConsumerConsole (GpByteSerializer::SP aFormatter) noexcept:
GpLogConsumer(std::move(aFormatter))
{
}

GpLogConsumerConsole::~GpLogConsumerConsole (void) noexcept
{
}

void    GpLogConsumerConsole::Consume (GpLogChain::CSP aLogChain)
{
    const GpLogChain& logChain = aLogChain.VC();

    GpBytesArray                    data;
    GpByteWriterStorageByteArray    dataStorage(data);
    GpByteWriter                    dataWriter(dataStorage);

    Formatter().Format(std::make_any<std::reference_wrapper<const GpLogChain>>(logChain), dataWriter);

    std::cout << GpRawPtrByteR(data).AsStringView();
    std::cout.flush();
}

void    GpLogConsumerConsole::OnFlush (void) noexcept
{
    std::cout.flush();
}

}//namespace GPlatform
