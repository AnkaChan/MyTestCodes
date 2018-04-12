cmake_minimum_required(VERSION 2.8)

project(TemplateAndStatic)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(TemplateAndStatic ${SRC})