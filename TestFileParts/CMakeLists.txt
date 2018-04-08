cmake_minimum_required(VERSION 2.8)

project(TestFileParts)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(TestFileParts ${SRC})