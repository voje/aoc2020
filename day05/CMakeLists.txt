cmake_minimum_required(VERSION 3.10)

# Readinput library
add_subdirectory(../lib/readinput lib/readinput)
include_directories(../lib/readinput)

add_subdirectory(lib)
include_directories(lib)

add_executable(main main.cpp)
target_link_libraries(main binary readinput)
