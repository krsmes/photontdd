cmake_minimum_required(VERSION 3.3)
project(photontdd)

if(testing_macro)
    enable_testing()
    add_definitions(-DTESTING)
endif(testing_macro)

add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(lib/gmock)

include_directories(
        lib/firmware/system/inc
        lib/firmware/hal/inc
        lib/firmware/hal/shared
        lib/firmware/hal/src/stm32f2xx
        lib/firmware/services/inc
        lib/firmware/wiring/inc
        lib/firmware/user/inc
        )
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(SOURCE_FILES
        LEDFlasher.h LEDFlasher.cpp
        tests/ParticleMock.h tests/ParticleMock.cpp
        tests/test_basic.cpp
        tests/test_LEDFlasher.cpp
        )

add_executable(runTests ${SOURCE_FILES})

target_link_libraries(runTests gtest gtest_main gmock gmock_main)
