#pragma once


#include <map>
#include <string>
#include <memory>
#include <vector>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/stdout_sinks.h>

#define APPLIB_EXPORT

namespace Reflex::Log
{


    class APPLIB_EXPORT Logger
    {

    private:
        std::shared_ptr<spdlog::logger> m_logger;
        std::string m_loggerName = "NotSet";

    public:
        Logger() = delete;
        Logger(const std::string& name);
        Logger(std::shared_ptr<spdlog::logger> pLogger);
        ~Logger() = default;
        void testLog() const;


        std::string getLoggerName() const;


        template <typename... Args>
        void writeWarning(std::string message, Args ... arguments)
        {
            m_logger->warn(message, std::forward<Args>(arguments)...);
        }

        template <typename... Args>
        void writeNotice(std::string message, Args ... arguments)
        {
            m_logger->info(message, std::forward<Args>(arguments)...);
        }

        template <typename... Args>
        void writeError(std::string message, Args ... arguments)
        {
            m_logger->error(message, std::forward<Args>(arguments)...);
        }

        template <typename... Args>
        void writeDebug(std::string message, Args ... arguments)
        {
            m_logger->debug(message, std::forward<Args>(arguments)...);
        }

        template <typename... Args>
        void writeCritical(std::string message, Args ... arguments)
        {
            m_logger->critical(message, std::forward<Args>(arguments)...);
        };

        template <typename... Args>
        void writeTrace(std::string message, Args ... arguments)
        {
            m_logger->trace(message, std::forward<Args>(arguments)...);
        }
    };
    //improve
    // Replace gets()-> with pre-created var

    APPLIB_EXPORT void registerLogger(std::shared_ptr<spdlog::logger> logger);

}
