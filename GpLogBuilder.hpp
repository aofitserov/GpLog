#pragma once

#include "GpLogger.hpp"
#include "Elements/GpLogElements.hpp"

namespace GPlatform {

class GPLOG_API GpLogBuilder
{
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpLogBuilder)

public:
    using MsgGenT = GpLogElementMsgStrFn::MsgGenT;

private:
                                GpLogBuilder    (GpLogElementMsg::CSP   aMessage) noexcept: iMessage(std::move(aMessage))  {}

public:
                                ~GpLogBuilder   (void) noexcept = default;

    static GpLogBuilder         SMsg            (std::string            aMessage)            {return GpLogBuilder(MakeCSP<GpLogElementMsgStr>(std::move(aMessage)));}
    static GpLogBuilder         SMsg            (MsgGenT                aMessageFn)          {return GpLogBuilder(MakeCSP<GpLogElementMsgStrFn>(aMessageFn));}
    static GpLogBuilder         SMsg            (const GpMarkTraceTS&   aMarkTraceTS)        {return GpLogBuilder(MakeCSP<GpLogElementMsgMarkTraceTS>(aMarkTraceTS));}
    static GpLogBuilder         SMsg            (GpMarkTraceTS&&        aMarkTraceTS)        {return GpLogBuilder(MakeCSP<GpLogElementMsgMarkTraceTS>(std::move(aMarkTraceTS)));}
    static GpLogBuilder         SMsg            (GpLogElementMsg::CSP   aMessage)   noexcept {return GpLogBuilder(std::move(aMessage));}
    static void                 SEndChain       (std::string_view       aChainId);

    GpLogBuilder&               Level           (GpLogLevel::EnumT      aLevel)     noexcept {iLevel    = aLevel; return *this;}
    GpLogBuilder&               Category        (std::string            aCategory)           {iCategory = std::move(aCategory); return *this;}
    GpLogBuilder&               ChainId         (std::string_view       aChainId)            {iChainId  = std::string(aChainId); iConsumeMode = GpLogConsumeMode::ADD_TO_CHAIN; return *this;}
    void                        Out             (void);

private:
    GpLogElementMsg::CSP        iMessage;
    GpLogLevel::EnumT           iLevel      = GpLogLevel::DEBUG;
    std::string                 iCategory;
    std::string                 iChainId;
    GpLogConsumeMode::EnumT     iConsumeMode= GpLogConsumeMode::CHAIN_END;
};

inline void GL_LOG_END_CHAIN (std::string_view aChainId)
{
    GpLogBuilder::SEndChain(aChainId);
}

inline void GL_LOG_DEBUG (std::string_view aMessage)
{
    GpLogBuilder::SMsg(std::string(aMessage)).Level(GpLogLevel::DEBUG).Out();
}

inline void GL_LOG_DEBUG (std::string aMessage)
{
    GpLogBuilder::SMsg(std::move(aMessage)).Level(GpLogLevel::DEBUG).Out();
}

inline void GL_LOG_DEBUG
(
    std::string_view    aMessage,
    std::string_view    aChainId
)
{
    GpLogBuilder::SMsg(std::string(aMessage)).Level(GpLogLevel::DEBUG).ChainId(aChainId).Out();
}

inline void GL_LOG_DEBUG
(
    std::string         aMessage,
    std::string_view    aChainId
)
{
    GpLogBuilder::SMsg(std::move(aMessage)).Level(GpLogLevel::DEBUG).ChainId(aChainId).Out();
}

inline void GL_LOG_INFO (std::string_view aMessage)
{
    GpLogBuilder::SMsg(std::string(aMessage)).Level(GpLogLevel::INFO).Out();
}

inline void GL_LOG_INFO (std::string aMessage)
{
    GpLogBuilder::SMsg(std::move(aMessage)).Level(GpLogLevel::INFO).Out();
}

inline void GL_LOG_INFO
(
    std::string_view    aMessage,
    std::string_view    aChainId
)
{
    GpLogBuilder::SMsg(std::string(aMessage)).Level(GpLogLevel::INFO).ChainId(aChainId).Out();
}

//------------------------------------- Text -------------------------------------

inline void GL_LOG_INFO
(
    std::string         aMessage,
    std::string_view    aChainId
)
{
    GpLogBuilder::SMsg(std::move(aMessage)).Level(GpLogLevel::INFO).ChainId(aChainId).Out();
}

inline void GL_LOG_WARNING (std::string_view aMessage)
{
    GpLogBuilder::SMsg(std::string(aMessage)).Level(GpLogLevel::WARNING).Out();
}

inline void GL_LOG_WARNING (std::string aMessage)
{
    GpLogBuilder::SMsg(std::move(aMessage)).Level(GpLogLevel::WARNING).Out();
}

inline void GL_LOG_WARNING
(
    std::string_view    aMessage,
    std::string_view    aChainId
)
{
    GpLogBuilder::SMsg(std::string(aMessage)).Level(GpLogLevel::WARNING).ChainId(aChainId).Out();
}

inline void GL_LOG_WARNING
(
    std::string         aMessage,
    std::string_view    aChainId
)
{
    GpLogBuilder::SMsg(std::move(aMessage)).Level(GpLogLevel::WARNING).ChainId(aChainId).Out();
}

inline void GL_LOG_ERROR (std::string_view aMessage)
{
    GpLogBuilder::SMsg(std::string(aMessage)).Level(GpLogLevel::ERROR).Out();
}

inline void GL_LOG_ERROR (std::string aMessage)
{
    GpLogBuilder::SMsg(std::move(aMessage)).Level(GpLogLevel::ERROR).Out();
}

inline void GL_LOG_ERROR
(
    std::string_view    aMessage,
    std::string_view    aChainId
)
{
    GpLogBuilder::SMsg(std::string(aMessage)).Level(GpLogLevel::ERROR).ChainId(aChainId).Out();
}

inline void GL_LOG_ERROR
(
    std::string         aMessage,
    std::string_view    aChainId
)
{
    GpLogBuilder::SMsg(std::move(aMessage)).Level(GpLogLevel::ERROR).ChainId(aChainId).Out();
}

inline void GL_LOG_CRITICAL_ERROR (std::string_view aMessage)
{
    GpLogBuilder::SMsg(std::string(aMessage)).Level(GpLogLevel::CRITICAL_ERROR).Out();
}

inline void GL_LOG_CRITICAL_ERROR (std::string aMessage)
{
    GpLogBuilder::SMsg(std::move(aMessage)).Level(GpLogLevel::CRITICAL_ERROR).Out();
}

inline void GL_LOG_CRITICAL_ERROR
(
    std::string_view    aMessage,
    std::string_view    aChainId
)
{
    GpLogBuilder::SMsg(std::string(aMessage)).Level(GpLogLevel::CRITICAL_ERROR).ChainId(aChainId).Out();
}

inline void GL_LOG_CRITICAL_ERROR
(
    std::string         aMessage,
    std::string_view    aChainId
)
{
    GpLogBuilder::SMsg(std::move(aMessage)).Level(GpLogLevel::CRITICAL_ERROR).ChainId(aChainId).Out();
}

//------------------------------------- GpMarkTraceTS -------------------------------------
inline void GL_LOG_DEBUG
(
    const GpMarkTraceTS&    aMarkTraceTS,
    std::string_view        aChainId
)
{
    GpLogBuilder::SMsg(aMarkTraceTS).Level(GpLogLevel::DEBUG).ChainId(aChainId).Out();
}

inline void GL_LOG_DEBUG
(
    GpMarkTraceTS&&     aMarkTraceTS,
    std::string_view    aChainId
)
{
    GpLogBuilder::SMsg(std::move(aMarkTraceTS)).Level(GpLogLevel::DEBUG).ChainId(aChainId).Out();
}

inline void GL_LOG_INFO
(
    const GpMarkTraceTS&    aMarkTraceTS,
    std::string_view        aChainId
)
{
    GpLogBuilder::SMsg(aMarkTraceTS).Level(GpLogLevel::INFO).ChainId(aChainId).Out();
}

inline void GL_LOG_INFO
(
    GpMarkTraceTS&&     aMarkTraceTS,
    std::string_view    aChainId
)
{
    GpLogBuilder::SMsg(std::move(aMarkTraceTS)).Level(GpLogLevel::INFO).ChainId(aChainId).Out();
}

inline void GL_LOG_WARNING
(
    const GpMarkTraceTS&    aMarkTraceTS,
    std::string_view        aChainId
)
{
    GpLogBuilder::SMsg(aMarkTraceTS).Level(GpLogLevel::WARNING).ChainId(aChainId).Out();
}

inline void GL_LOG_WARNING
(
    GpMarkTraceTS&&     aMarkTraceTS,
    std::string_view    aChainId
)
{
    GpLogBuilder::SMsg(std::move(aMarkTraceTS)).Level(GpLogLevel::WARNING).ChainId(aChainId).Out();
}

inline void GL_LOG_ERROR
(
    const GpMarkTraceTS&    aMarkTraceTS,
    std::string_view        aChainId
)
{
    GpLogBuilder::SMsg(aMarkTraceTS).Level(GpLogLevel::ERROR).ChainId(aChainId).Out();
}

inline void GL_LOG_ERROR
(
    GpMarkTraceTS&&     aMarkTraceTS,
    std::string_view    aChainId
)
{
    GpLogBuilder::SMsg(std::move(aMarkTraceTS)).Level(GpLogLevel::ERROR).ChainId(aChainId).Out();
}

inline void GL_LOG_CRITICAL_ERROR
(
    const GpMarkTraceTS&    aMarkTraceTS,
    std::string_view        aChainId
)
{
    GpLogBuilder::SMsg(aMarkTraceTS).Level(GpLogLevel::CRITICAL_ERROR).ChainId(aChainId).Out();
}

inline void GL_LOG_CRITICAL_ERROR
(
    GpMarkTraceTS&&     aMarkTraceTS,
    std::string_view    aChainId
)
{
    GpLogBuilder::SMsg(std::move(aMarkTraceTS)).Level(GpLogLevel::CRITICAL_ERROR).ChainId(aChainId).Out();
}


}//namespace GPlatform
