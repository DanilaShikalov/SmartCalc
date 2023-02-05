cmake_minimum_required(VERSION 3.22)
project(QTProjects C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(QTProjects
        graph.c
        graph.h
        polish_decoder.c
        polish_decoder.h
        stack.c
        stack.h)
