cmake_minimum_required(VERSION 3.6)
project(Embedded)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/home/yop/.arduino15/packages /home/yop/.arduino15/packages/arduino/hardware/avr/1.6.18/cores/arduino)

set(SOURCE_FILES
    CAccelero.cpp
    CAccelero.h
    CInterface.h
    CSensor.h
    CServo.cpp
    CServo.h
    CUltrasound.h
    CUtils.cpp
    CUtils.h
    Embedded.ino
    main.cpp CUltrasound.cpp CSerial.h CSerial.cpp)

add_executable(Embedded ${SOURCE_FILES})