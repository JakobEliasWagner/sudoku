
# Sudoku Class
add_executable(test-sudoku "")

target_sources(test-sudoku
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/test_sudoku.cpp
        )

target_link_libraries(test-sudoku
        PRIVATE
        gtest_main
        sudoku
        )

enable_testing()

add_test(
        NAME google_test
        COMMAND $<TARGET_FILE:test-sudoku>
)