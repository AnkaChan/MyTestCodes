cmake_minimum_required(VERSION 2.8)

project(MutexAndSpinLock)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(MutexAndSpinLock ${SRC})