#include <stdio.h>

#include "logger.hpp"

int main() {
    printf("Starting from line: %d in %s\n", __LINE__, __FILE__);

    Logger::Log(LogLevel::TRACE, "Testing the logger");
    Logger::Log(LogLevel::DEBUG, "Testing the logger");
    LOG_WARN("Testing the logger");
    Logger::Log(LogLevel::ERROR, "Testing the logger");
    LOG_FATAL("Testing the logger");

    return 0;
}