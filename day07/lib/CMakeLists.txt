cmake_minimum_required(VERSION 3.10.0)

project(bag)

add_library(
    bag
    bag.cpp
)

# Add debug flags
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(../../lib/graph lib/graph)
include_directories(../../lib/graph)


# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(bag_tests bag_tests.cpp)
target_link_libraries (bag_tests graph bag ${GTEST_LIBRARIES} pthread)
