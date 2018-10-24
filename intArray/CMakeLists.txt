cmake_minimum_required(VERSION 3.10)
project(intArray C)

set(CMAKE_C_STANDARD 11)
set(GCC_COVERAGE_COMPILE_FLAGS "-Werror -Wall -pedantic -Wextra -std=c11 -lm")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(intArray arraymain.c intarray.c intarray.h)