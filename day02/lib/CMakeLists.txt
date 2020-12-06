cmake_minimum_required(VERSION 3.10)

add_library(
    pwrecord
    pwrecord.cpp
    pwrecord.hpp
)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(pwrecord_test tests.cpp)
target_link_libraries(pwrecord_test pwrecord ${GTEST_LIBRARIES} pthread)
