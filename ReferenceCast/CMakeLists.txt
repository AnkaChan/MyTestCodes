cmake_minimum_required(VERSION 2.8)

project(CastTest)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(CastTest ${SRC})