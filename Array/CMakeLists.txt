cmake_minimum_required(VERSION 2.8)

project(Array)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(Array ${SRC})