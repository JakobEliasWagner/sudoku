add_executable(solver-app ${CMAKE_CURRENT_LIST_DIR}/main.cpp)

target_link_libraries(solver-app
        PRIVATE
        sudoku
        )