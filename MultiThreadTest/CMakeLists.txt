cmake_minimum_required(VERSION 2.8)

project(MultiThreadTest)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(MultiThreadTest ${SRC})