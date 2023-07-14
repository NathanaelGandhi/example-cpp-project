cmake_minimum_required(VERSION 3.16)

# Set the source files for the library
set(PROJECT_SOURCES
    logger.cpp
)

# Project
get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${CURRENT_DIR_NAME})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

# Specify the include directories for the library
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Specify any additional dependencies for the library
# target_link_libraries(mylibrary <other_libraries>)