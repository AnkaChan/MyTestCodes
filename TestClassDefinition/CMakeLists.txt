cmake_minimum_required(VERSION 2.8)

project(TestClassDefinition)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(TestClassDefinition ${SRC})