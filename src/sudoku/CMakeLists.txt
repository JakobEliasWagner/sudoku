add_library(sudoku)

target_sources(sudoku
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/sudoku.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/sudoku.h)

target_include_directories(sudoku
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )