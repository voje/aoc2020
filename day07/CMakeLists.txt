cmake_minimum_required(VERSION 3.10)

project(day07)

add_subdirectory(lib)
include_directories(lib)

add_executable(main main.cpp)
target_link_libraries(main bag)
