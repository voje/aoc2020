cmake_minimum_required(VERSION 3.10)

add_library(
    aoc 
    customs.hpp
    customs.cpp
)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(tests tests.cpp)
target_link_libraries(tests aoc ${GTEST_LIBRARIES} pthread)
