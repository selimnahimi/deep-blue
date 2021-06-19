cmake_minimum_required(VERSION 3.8)

project(libchess VERSION 1.0 DESCRIPTION "Chess library")

add_library(libchess SHARED
	piece.c
	board.c
	input.c
)

set_target_properties(libchess PROPERTIES VERSION ${PROJECT_VERSION})

