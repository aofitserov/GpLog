#pragma once

#include "Consumers/GpLogConsumers.hpp"
#include "GpLogConfigDesc.hpp"
#include "GpLogExecutor.hpp"
#include "GpLogChain.hpp"

namespace GPlatform {

class GPLOG_API GpLogger
{
    CLASS_REMOVE_CTRS_MOVE_COPY(GpLogger)
    CLASS_TAG(THREAD_SAFE)

    using CategoryLevelsT   = GpMap<std::string, GpLogLevel, std::less<>>;

public:
                            GpLogger            (void) noexcept;
                            ~GpLogger           (void) noexcept;

    static GpLogger&        S                   (void) noexcept {return sLogger;}

    void                    StartFromConfig     (const GpLogConfigDesc& aCfgDesc);
    void                    Stop                (void);

    inline void             Log                 (std::string_view               aMessage,
                                                 const GpLogLevel::EnumT        aLevel);

    void                    Log                 (std::string_view               aMessage,
                                                 const GpLogLevel::EnumT        aLevel,
                                                 std::string_view               aCategory,
                                                 std::string_view               aChainId,
                                                 const GpLogConsumeMode::EnumT  aConsumeMode);

private:
    GpLogExecutor::SP       iLogExecutor;
    GpLogLevel::EnumT       iDefaultLevel   = GpLogLevel::INFO;
    CategoryLevelsT         iCategoryLevels;

    static GpLogger         sLogger;
};

void    GpLogger::Log
(
    std::string_view        aMessage,
    const GpLogLevel::EnumT aLevel
)
{
    Log
    (
        aMessage,
        aLevel,
        ""_sv,
        ""_sv,
        GpLogConsumeMode::CHAIN_END
    );
}

inline void GL_LOG_DEBUG    (std::string_view aMessage)
{
    GpLogger::S().Log
    (
        aMessage,
        GpLogLevel::DEBUG
    );
}


inline void GL_LOG_INFO (std::string_view aMessage)
{
    GpLogger::S().Log
    (
        aMessage,
        GpLogLevel::INFO
    );
}

inline void GL_LOG_WARNING (std::string_view aMessage)
{
    GpLogger::S().Log
    (
        aMessage,
        GpLogLevel::WARNING
    );
}

inline void GL_LOG_ERROR (std::string_view aMessage)
{
    GpLogger::S().Log
    (
        aMessage,
        GpLogLevel::ERROR
    );
}

inline void GL_LOG_CRITICAL_ERROR (std::string_view aMessage)
{
    GpLogger::S().Log
    (
        aMessage,
        GpLogLevel::CRITICAL_ERROR
    );
}

}//namespace GPlatform
