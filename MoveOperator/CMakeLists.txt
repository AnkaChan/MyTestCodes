cmake_minimum_required(VERSION 2.8)

project(MoveOperator)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(MoveOperator ${SRC})