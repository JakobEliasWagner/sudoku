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

include(${CMAKE_CURRENT_LIST_DIR}/drawing_strategies/CMakeLists.txt)

target_link_libraries(sudoku
        PRIVATE
        drawing-strategies
        )