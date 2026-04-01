cmake_minimum_required(VERSION 4.1)
project(Dungeon C)

set(CMAKE_C_STANDARD 23)

add_executable(Dungeon main.c
        dungeon.c
        dungeon.h)
