cmake_minimum_required(VERSION 4.2)
project(vecfloor LANGUAGES C)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Library
add_library(vecfloor)
target_sources(vecfloor PUBLIC src/init.c src/cleanup.c src/modify.c src/shorthand.c src/string.c)
target_include_directories(vecfloor PUBLIC include)