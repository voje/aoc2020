cmake_minimum_required (VERSION 3.10)

add_library (
    binary 
    binary.cpp
    binary.hpp
)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Compile tests
add_executable (binary_tests binary_tests.cpp)
target_link_libraries (binary_tests binary ${GTEST_LIBRARIES} pthread)
