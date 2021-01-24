cmake_minimum_required(VERSION 3.10.0)

project(bag)

add_library(
    bag
    bag.cpp
)

add_subdirectory(../../lib/ include)
include_directories(../../lib)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(bag_test bag_test.cpp)
target_link_libraries (bag_test graph bag ${GTEST_LIBRARIES} pthread)
