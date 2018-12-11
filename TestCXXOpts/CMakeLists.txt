cmake_minimum_required(VERSION 2.8)

project(TesCxxopts)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(TesCxxopts ${SRC})