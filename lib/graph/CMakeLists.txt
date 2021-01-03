cmake_minimum_required(VERSION 3.10)

project(graph)

add_library(
    graph
    graph.hpp
    graph.cpp
)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add debug flags
set(CMAKE_BUILD_TYPE Debug)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(tests tests.cpp)
target_link_libraries(tests graph ${GTEST_LIBRARIES} pthread)

