

#include "Reflex-Logging.h"

#include <utility>



Reflex::Log::Logger::Logger(const std::string& name)
{
    m_loggerName = name;
    m_logger = spdlog::get(name);
    if (!m_logger) 
    {
        
        m_logger = spdlog::stdout_color_mt(name);
    }
}

Reflex::Log::Logger::Logger(std::shared_ptr<spdlog::logger> pLogger)
{
    m_logger = std::move(pLogger);
}

void Reflex::Log::Logger::testLog() const
{
    m_logger->info("Log from {1}", m_loggerName);
}

std::string Reflex::Log::Logger::getLoggerName() const {
    return m_loggerName;
}

void Reflex::Log::shutdown()
{
    spdlog::shutdown();
}

void Reflex::Log::setDefaultLog(const std::string& logName)
{
    auto log = spdlog::get(logName);
    if (!log)
        std::make_shared<Reflex::Log::Logger>("Default-Log");

    spdlog::set_default_logger(spdlog::get(logName));
}

void Reflex::Log::removeLog(const std::string& logName)
{
    if(spdlog::get(logName))
        spdlog::drop(logName);
}

std::shared_ptr<Reflex::Log::Logger> Reflex::Log::createNewLogger(const std::string& logName)
{
    using Reflex::Log::Logger;

    return std::make_shared<Logger>(logName);
    /*if(logMap.empty())
    {
        auto newLog = std::make_shared<Logger>(logName);
        return logMap.try_emplace(logName, newLog).first->second;
    }

    for(auto t = logMap.begin(); t != logMap.end(); ++t)
    {
        if(t->first == logName)
        {
            return t->second;
        }

        if(t == logMap.end() || logMap.size() == 0)
        {
            auto newLog = std::make_shared<Logger>(logName);
            return logMap.try_emplace(logName, newLog).first->second;
        }
    }
    return nullptr;*/
}

//std::shared_ptr<Reflex::Log::Logger> Reflex::Log::LogRegister::getLoggerByName (const std::string& logName)
//{
//    return logMap[logName];
//}
