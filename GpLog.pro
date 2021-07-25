TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 0
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=f4a073f8-2173-4902-9a45-64367c7591c0
QMAKE_CXXFLAGS += -DGP_TYPE_SYSTEM_STATIC_ADD_TO_MANAGER
DEFINES		   += GPLOG_LIBRARY
PACKET_NAME     = GpLog
DIR_LEVEL       = ./..

include(../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
	GP_CORE_LIB_V		= 2
	GP_JSON_LIB_V		= 0
}

os_linux{
}

LIBS += -lGpCore2$$TARGET_POSTFIX$$GP_CORE_LIB_V
LIBS += -lGpJson$$TARGET_POSTFIX$$GP_JSON_LIB_V
#------------------------------ LIBS END ---------------------------------

SOURCES += \
	Consumers/Console/GpLogConsumerConsole.cpp \
	Consumers/Console/GpLogConsumerConsoleConfigDesc.cpp \
	Consumers/Console/GpLogConsumerConsoleFactory.cpp \
	Consumers/File/GpLogConsumerFile.cpp \
	Consumers/File/GpLogConsumerFileConfigDesc.cpp \
	Consumers/File/GpLogConsumerFileFactory.cpp \
	Consumers/GpLogConsumer.cpp \
	Consumers/GpLogConsumerConfigBuilder.cpp \
	Consumers/GpLogConsumerConfigDesc.cpp \
	Consumers/GpLogConsumerFactory.cpp \
	Formatters/GpLogFormatter.cpp \
	Formatters/GpLogFormatterConfigBuilder.cpp \
	Formatters/GpLogFormatterConfigDesc.cpp \
	Formatters/GpLogFormatterFactory.cpp \
	Formatters/Text/GpLogFormatterText.cpp \
	Formatters/Text/GpLogFormatterTextConfigDesc.cpp \
	Formatters/Text/GpLogFormatterTextFactory.cpp \
	GpLogChain.cpp \	
	GpLogConfigDesc.cpp \
	GpLogConsumeMode.cpp \
	GpLogElement.cpp \
	GpLogExecutor.cpp \
	GpLogLevel.cpp \
	GpLogRunnable.cpp \
	GpLogger.cpp


HEADERS += \
	Consumers/Console/GpLogConsumerConsole.hpp \
	Consumers/Console/GpLogConsumerConsoleConfigDesc.hpp \
	Consumers/Console/GpLogConsumerConsoleFactory.hpp \
	Consumers/File/GpLogConsumerFile.hpp \
	Consumers/File/GpLogConsumerFileConfigDesc.hpp \
	Consumers/File/GpLogConsumerFileFactory.hpp \
	Consumers/GpLogConsumer.hpp \
	Consumers/GpLogConsumerConfigBuilder.hpp \
	Consumers/GpLogConsumerConfigDesc.hpp \
	Consumers/GpLogConsumerFactory.hpp \
	Consumers/GpLogConsumers.hpp \
	Formatters/GpLogFormatter.hpp \
	Formatters/GpLogFormatterConfigBuilder.hpp \
	Formatters/GpLogFormatterConfigDesc.hpp \
	Formatters/GpLogFormatterFactory.hpp \
	Formatters/GpLogFormatters.hpp \
	Formatters/Text/GpLogFormatterText.hpp \
	Formatters/Text/GpLogFormatterTextConfigDesc.hpp \
	Formatters/Text/GpLogFormatterTextFactory.hpp \
	GpLog.hpp \
	GpLogChain.hpp \
	GpLogConfigDesc.hpp \
	GpLogConsumeMode.hpp \
	GpLogElement.hpp \
	GpLogExecutor.hpp \
	GpLogLevel.hpp \
	GpLogRunnable.hpp \
	GpLog_global.hpp \
	GpLogger.hpp
