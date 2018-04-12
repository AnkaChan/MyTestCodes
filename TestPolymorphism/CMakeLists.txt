cmake_minimum_required(VERSION 2.8)

project(TestPolymorphism)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(TestPolymorphism ${SRC})