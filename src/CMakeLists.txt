cmake_minimum_required(VERSION 3.0)
project(ChessGame C)

add_subdirectory(lib)

set(MAIN_SRCS "main.c")
set(TEST_SRCS "test.c")

add_executable(main.out ${MAIN_SRCS})
add_executable(test.out ${TEST_SRCS})

target_link_libraries(main.out chess)
target_link_libraries(test.out chess)

