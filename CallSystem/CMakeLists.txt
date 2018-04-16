cmake_minimum_required(VERSION 2.8)

project(CallSystem)

file(GLOB SRC1
    "*.h"
    "main.cpp"
)
add_executable(CallSystem ${SRC1})

project(SayHello)
file(GLOB SRC2
    "*.h"
    "sayHello.cpp"
)
add_executable(SayHello ${SRC2})