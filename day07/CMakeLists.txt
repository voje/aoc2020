cmake_minimum_required(VERSION 3.10)

project(day07)

# messed up the "bag" library by using the relative path to "graph"

add_library(
    bag
    ./lib/bag.cpp
)

add_subdirectory(../lib/graph include)
include_directories(../lib/graph)

add_executable(main main.cpp)
target_link_libraries(main bag graph)
