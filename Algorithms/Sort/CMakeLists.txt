cmake_minimum_required(VERSION 2.8)

project(QuickSort)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(QuickSort ${SRC})