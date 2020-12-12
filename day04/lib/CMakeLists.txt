cmake_minimum_required (VERSION 3.10)

add_library (
    passport
    passport.hpp
    passport.cpp
)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Compile tests
add_executable (passport_tests passport_tests.cpp)
target_link_libraries (passport_tests passport ${GTEST_LIBRARIES} pthread)
