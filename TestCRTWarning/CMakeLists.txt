cmake_minimum_required(VERSION 2.8)

project(TestCRTWarning)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(TestCRTWarning ${SRC})