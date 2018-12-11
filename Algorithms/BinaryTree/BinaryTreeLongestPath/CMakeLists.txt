cmake_minimum_required(VERSION 2.8)

project(BinaryTreeLongestPath)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(BinaryTreeLongestPath ${SRC})