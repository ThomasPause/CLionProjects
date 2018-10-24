cmake_minimum_required(VERSION 3.9)
project(PwI1 C)

set(CMAKE_C_STANDARD 11)
set(CC_COVERAGE_COMPILE_FLAGS "-Werror -Wall -pedantic -Wextra")

add_executable(PwI1 main.c main.c)