cmake_minimum_required(VERSION 2.8)

project(LongestPalindromic)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(LongestPalindromic ${SRC})