#pragma once

#include "../GpCore2/GpCore.hpp"
#include "../GpJson/GpJson.hpp"

#if defined(GPLOG_LIBRARY)
    #define GPLOG_API GP_DECL_EXPORT
#else
    #define GPLOG_API GP_DECL_IMPORT
#endif
