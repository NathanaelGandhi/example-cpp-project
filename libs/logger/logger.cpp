#include "logger.hpp"

#include <ctime>

/* PUBLIC FUNCTIONS */
void Logger::SetLogLevel(const LogLevel level) {
    GetInstance().current_log_level_ = level;
}

void Logger::Log(const LogLevel level, const char* message) {
    Logger& logger_instance = GetInstance();
    if (logger_instance.current_log_level_ <= level) {
        const char* level_string = logger_instance.LogLevelToString(level);
        if (NULL != level_string) {
            // Generate a timestamp
            std::time_t time_raw = std::time(0);
            std::tm* time_info = std::localtime(&time_raw);
            char time_buffer[80];
            strftime(time_buffer, sizeof(time_buffer), "%T", time_info);

            printf("[%s] [%s]: %s\n", level_string, time_buffer, message);
        }
    }
}

/* PRIVATE FUNCTIONS */
Logger::Logger() {
    // default log level
    current_log_level_ = LogLevel::TRACE;
}

Logger::~Logger() {}

Logger& Logger::GetInstance() {
    static Logger logger;
    return logger;
}

const char* Logger::LogLevelToString(LogLevel level) {
    const char* log_level_string = NULL;

    switch (level) {
        case LogLevel::TRACE:
            log_level_string = "TRACE";
            break;
        case LogLevel::DEBUG:
            log_level_string = "DEBUG";
            break;
        case LogLevel::WARN:
            // string is spaced to provide a consistent output
            log_level_string = " WARN";
            break;
        case LogLevel::ERROR:
            log_level_string = "ERROR";
            break;
        case LogLevel::FATAL:
            log_level_string = "FATAL";
            break;

        default:
            GetInstance().Log(LogLevel::ERROR, "LogLevel unknown");
            break;
    }

    return log_level_string;
}