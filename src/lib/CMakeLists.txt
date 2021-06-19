cmake_minimum_required(VERSION 3.8)

project(chess C)

add_library(chess SHARED
	piece.c
	board.c
	input.c
)

set_target_properties(chess PROPERTIES VERSION 1.0)
target_include_directories(chess PUBLIC .)
