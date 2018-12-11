cmake_minimum_required(VERSION 2.8)

project(Dijkstra)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(Dijkstra ${SRC})