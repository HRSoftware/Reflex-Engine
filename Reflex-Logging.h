#pragma once


#include <map>
#include <string>
#include <memory>
#include <vector>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/stdout_sinks.h>

namespace Reflex::Log
{
    class Logger
    {

    protected:
        std::shared_ptr<spdlog::logger> m_logger;
        std::string m_loggerName = "NotSet";


    public:
        Logger() = delete;
        Logger(const std::string& name);
        Logger(std::shared_ptr<spdlog::logger> logName);
        ~Logger() = default;


        void  testLog() const;
        std::string getLoggerName() const;

        template <typename... Args>
        void writeWarning(const std::string& message, Args ... arguments)
        {
            m_logger->warn(message, std::forward<Args>(arguments)...);
        }

        template <typename... Args>
        void writeNotice(const std::string& message, Args ... arguments)
        {
            m_logger->info(message, std::forward<Args>(arguments)...);
        }

        template <typename... Args>
        void writeError(const std::string& message, Args ... arguments)
        {
            m_logger->error(message, std::forward<Args>(arguments)...);
        }

        template <typename... Args>
        void writeDebug(const std::string& message, Args ... arguments)
        {
            m_logger->debug(message, std::forward<Args>(arguments)...);
        }

        template <typename... Args>
        void writeCritical(const std::string& message, Args ... arguments)
        {
            m_logger->critical(message, std::forward<Args>(arguments)...);
        };

        template <typename... Args>
        void writeTrace(const std::string& message, Args ... arguments)
        {
            m_logger->trace(message, std::forward<Args>(arguments)...);
        }


    };
    //improve
    // Replace gets()-> with pre-created var

    void shutdown();
    void setDefaultLog(const std::string& logName);
    void removeLog(const std::string& logName);
    std::shared_ptr<Reflex::Log::Logger> createNewLogger(const std::string& logName);
    //static std::shared_ptr<Reflex::Log::Logger> getLoggerByName(const std::string& logName);





}
