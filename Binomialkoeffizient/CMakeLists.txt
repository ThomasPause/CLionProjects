cmake_minimum_required(VERSION 3.10)
project(Binomialkoeffizient C)

set(CMAKE_C_STANDARD 11)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Werror -Wall -Wextra -pedantic")
add_executable(Binomialkoeffizient main.c binokoeffi.c binokoeffi.h)