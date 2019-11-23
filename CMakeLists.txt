cmake_minimum_required(VERSION 3.13)
project(algorithms_lab1)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
add_subdirectory(src/queue)
add_subdirectory(src/heap)
add_subdirectory(src/heap_spec)

set(SOURCE_FILES main.cpp)
add_executable(algorithms_lab1 ${SOURCE_FILES})
target_link_libraries(algorithms_lab1 gtest gtest_main)