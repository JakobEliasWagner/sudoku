add_library(visualization)

target_sources(visualization
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/console.cpp
        ${CMAKE_CURRENT_LIST_DIR}/visualizer.cpp
        ${CMAKE_CURRENT_LIST_DIR}/visualizer.h
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/console.h)

target_include_directories(visualization
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )