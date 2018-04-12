cmake_minimum_required(VERSION 2.8)

project(TestDynamicProp)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(TestDynamicProp ${SRC})