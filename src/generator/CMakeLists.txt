add_library(generator)

target_sources(generator
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/generator.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/generator.h)