#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <stdio.h>

#define LOG_TRACE(message) (Logger::Log(LogLevel::TRACE, message))
#define LOG_DEBUG(message) (Logger::Log(LogLevel::DEBUG, message))
#define LOG_WARN(message) (Logger::Log(LogLevel::WARN, message))
#define LOG_ERROR(message) (Logger::Log(LogLevel::ERROR, message))
#define LOG_FATAL(message) (Logger::Log(LogLevel::FATAL, message))

enum class LogLevel { TRACE, DEBUG, WARN, ERROR, FATAL };

class Logger {
   public:
    void SetLogLevel(const LogLevel level);
    static void Log(const LogLevel level, const char* message);

   protected:
    /* data */

   private:
    Logger();
    // prohibit copy constructor
    Logger(const Logger&) = delete;
    // prohibit copy assignment operator
    Logger& operator=(const Logger&) = delete;
    ~Logger();
    static Logger& GetInstance();
    const char* LogLevelToString(LogLevel level);
    LogLevel current_log_level_;
};

#endif