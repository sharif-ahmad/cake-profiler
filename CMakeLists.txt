cmake_minimum_required(VERSION 3.5)

project (piece_of_cake_profiler)

set (CMAKE_CXX_STANDARD 11)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories("include")
enable_testing()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(poc_profiler STATIC
    "include/poc.h"
    "include/pocdef.h"
    "include/profiler.h"
    "include/profilermanager.h"
    "include/logger.h"
    "include/triviallogger.h"
    "include/profilercontainer.h"
    "src/triviallogger.cpp"
    "src/profiler.cpp"
    "src/profilermanager.cpp"
    "src/profilercontainer.cpp"
    )


option(BUILD_TEST "Builds testing subprojects" OFF)

if(BUILD_TEST)
    add_subdirectory("test")
endif()

