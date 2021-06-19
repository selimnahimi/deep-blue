cmake_minimum_required(VERSION 3.0)
project(ChessGame C)

add_subdirectory(lib)

set(MAIN_SRCS "main.c")
add_executable(main.a ${MAIN_SRCS})
target_link_libraries(main.a chess)
