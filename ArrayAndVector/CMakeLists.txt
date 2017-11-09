cmake_minimum_required(VERSION 2.8)

project(Example)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(Example ${SRC})