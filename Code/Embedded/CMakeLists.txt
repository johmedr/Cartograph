cmake_minimum_required(VERSION 3.3)
project(Embedded)

set(EXECUTABLE_OUTPUT_PATH bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmraa -Wall")

include_directories(include)
set(SOURCE_FILES src/CServo.cpp include/CServo.h include/CInterface.h include/CSensor.h include/CUtils.h src/main.cpp src/CUtils.c)

add_executable(Embedded ${SOURCE_FILES})