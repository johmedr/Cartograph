cmake_minimum_required(VERSION 3.6)
project(Embedded)

set(EXECUTABLE_OUTPUT_PATH bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmraa")


set(SOURCE_FILES src)

add_executable(Embedded ${SOURCE_FILES})