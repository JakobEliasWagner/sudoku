add_library(drawing-strategies)

target_sources(drawing-strategies
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/console_drawing_strategy.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/console_drawing_strategy.h
        )

target_include_directories(drawing-strategies
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )

target_link_libraries(drawing-strategies
        PRIVATE
        sudoku)