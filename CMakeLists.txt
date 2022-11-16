cmake_minimum_required(VERSION 3.21)
project(exquisitus_c_adaveris C)

set(CMAKE_C_STANDARD 11)

add_executable(exquisitus_c_adaveris main.c tree.c tree.h list.c list.h derivative.c derivative.h io.c io.h menu.c menu.h)
