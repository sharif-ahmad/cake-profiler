cmake_minimum_required(VERSION 3.5)

project (cake_profiler)

set (CMAKE_CXX_STANDARD 11)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories("include")

add_library(cake_profiler STATIC
    "include/cake.h"
    "include/cakedef.h"
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

add_executable(cake_test "test/test.cpp")
target_link_libraries(cake_test cake_profiler Threads::Threads)

