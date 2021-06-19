cmake_minimum_required(VERSION 3.0)
project(ChessGame C)

add_subdirectory(lib)

set(MAIN_SRCS "main.c")
set(TEST_SRCS "test.c")

add_executable(main.out ${MAIN_SRCS})
add_executable(test.out ${TEST_SRCS})

target_link_libraries(main.out chess)
target_link_libraries(test.out chess)

enable_testing()

set(test_executable test.out)

if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/tests/)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tests/)

    file(GLOB files "${CMAKE_CURRENT_LIST_DIR}/tests/*.in")
    foreach(file ${files})
        string(REGEX REPLACE "\\.[^.]*$" "" FILE_WITHOUT_EXT ${file})
        string(REGEX REPLACE "${CMAKE_CURRENT_LIST_DIR}" "${CMAKE_CURRENT_BINARY_DIR}" FILE_TEST_OUT_PATH ${FILE_WITHOUT_EXT})

        file(READ ${file} file_args)
        message("Adding test for ${FILE_WITHOUT_EXT}")

        add_test(NAME ${FILE_WITHOUT_EXT} COMMAND sh -c "${CMAKE_CURRENT_BINARY_DIR}/${test_executable} ${file_args} >${FILE_TEST_OUT_PATH}.out")
        add_test(NAME ${FILE_WITHOUT_EXT}_compare COMMAND ${CMAKE_COMMAND} -E compare_files ${FILE_TEST_OUT_PATH}.out ${FILE_WITHOUT_EXT}.exp)
    endforeach()
endif()
