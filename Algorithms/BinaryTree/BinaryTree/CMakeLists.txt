cmake_minimum_required(VERSION 2.8)

project(BinaryTree)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(BinaryTree ${SRC})