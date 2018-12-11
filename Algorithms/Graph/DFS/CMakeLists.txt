cmake_minimum_required(VERSION 2.8)

project(GraphDFS)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(GraphDFS ${SRC})