cmake_minimum_required(VERSION 3.16)

# Compiler
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set (CMAKE_CXX_STANDARD 11)

# Sources
set(PROJECT_SOURCES
    "app/src/app.cpp"
)

#Project
get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${CURRENT_DIR_NAME})
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# Includes
target_include_directories(${PROJECT_NAME} PUBLIC 
    "app/inc"
)

# Libraries
set(PROJECT_LIBS
    "logger"
)
foreach(LIB ${PROJECT_LIBS})
    # Add library dependencies
    add_subdirectory(libs/${PROJECT_LIBS})
    # Link against Libraries
    target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_LIBS})
endforeach()

# Compile Options
target_compile_options(${PROJECT_NAME} PRIVATE 
    -pedantic               # Issue all the warnings demanded by strict ISO C
    -Wall                   # Warn about most questionable operations
    -Wwrite-strings         # Warn if not treating string literals as "const"
    -Wpointer-arith         # Warn about suspicious pointer operations
    -Wcast-align            # Warn about casts that increase alignment requirements
    -Werror                 # Treat warnings as errors (code should be clean)
)