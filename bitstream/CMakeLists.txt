cmake_minimum_required(VERSION 3.10)
project(bitstream C)

set(CMAKE_C_STANDARD 11)
set(GCC_COVERAGE_COMPILE_FLAGS "-Werror -Wall -pedantic -Wextra -std=c11 -lm")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(bitstream bitmain.c bitstream.c bitstream.h)