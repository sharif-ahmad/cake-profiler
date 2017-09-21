
add_executable(poc_test "test.cpp")
target_link_libraries(poc_test poc_profiler Threads::Threads)


include_directories("${CMAKE_SOURCE_DIR}/externals/include")
link_directories("${CMAKE_SOURCE_DIR}/externals/libs")
add_executable(unittest "unittest.cpp")
target_link_libraries(unittest gmock gmock_main Threads::Threads)

