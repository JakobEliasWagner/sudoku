add_library(solver)

target_sources(solver
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/solver.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/solver.h)