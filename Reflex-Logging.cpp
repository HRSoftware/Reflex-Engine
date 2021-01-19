

#include "Reflex-Logging.h"

#include <utility>

//BOOL APIENTRY DllMain( HMODULE hModule,
//                       DWORD  ul_reason_for_call,
//                       LPVOID lpReserved
//                     )
//{
//    return TRUE;
//}
//


Reflex::Log::Logger::Logger(const std::string& name)
{
    m_loggerName = name;
    m_logger = spdlog::stdout_color_mt(name);
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

//APPLIB_EXPORT void Reflex::Log::registerLogger(std::shared_ptr<spdlog::logger> logger)
//{
//    spdlog::register_logger(logger);
//}
