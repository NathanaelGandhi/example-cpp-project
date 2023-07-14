# example-cpp-project

## Libraries

These are found under [libs/](libs/). Each one has its own CMakeLists.txt. 
To compile a library into the project add the library name to the projects [CMakeLists.txt](CMakeLists.txt) file under ```set(PROJECT_LIBS```.

- [logger](libs/logger/)
  - Provides TRACE, DEBUG, WARN, ERROR, FATAL log levels
  - Stamps log messages with time
  - Appends a user supplied message to the log message
  - Called via either the class function or helper macro
    - Logger::Log(LogLevel::DEBUG, "Testing the logger");
    - LOG_WARN("Testing the logger");