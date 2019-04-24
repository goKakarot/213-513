cmake_minimum_required(VERSION 3.14)
project(cprogramminglab_handout C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(cprogramminglab_handout
        console.c
        console.h
        harness.c
        harness.h
        qtest.c
        queue.c
        queue.h
        report.c
        report.h)
