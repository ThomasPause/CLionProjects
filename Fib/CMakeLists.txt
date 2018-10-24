cmake_minimum_required(VERSION 3.10)
project(Fib C)

set(CMAKE_C_STANDARD 11)

set(GCC_COVERAGE_COMPILE_FLAGS "-Werror -Wall -pedantic -Wextra -std=c11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")


add_executable(Fib fibonacci.c)