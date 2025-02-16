cmake_minimum_required(VERSION 3.31)

project(GameOfLife VERSION 0.1.0 LANGUAGES C CXX)

add_library(game STATIC src/main.cpp)

set_target_properties(game PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(game PUBLIC src)

add_subdirectory(src)

add_executable(GameOfLife src/main.cpp)

target_link_libraries(GameOfLife PRIVATE game)