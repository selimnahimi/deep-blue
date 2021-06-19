cmake_minimum_required(VERSION 3.0)
project(Chess C)

add_library(chess SHARED IMPORTED)

set_target_properties(chess PROPERTIES
	IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/libchess.so"
)

set(MAIN_SRCS "main.c")
add_executable(main ${MAIN_SRCS})
target_link_libraries(main chess)
