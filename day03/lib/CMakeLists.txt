cmake_minimum_required(VERSION 3.10)

add_library(
    map 
    map.cpp
    map.hpp
)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(map_tests tests.cpp)
target_link_libraries(map_tests map ${GTEST_LIBRARIES} pthread)
