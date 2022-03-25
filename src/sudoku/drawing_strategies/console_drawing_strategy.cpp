#include <iostream>
#include <iomanip>
#include "console_drawing_strategy.h"

void ConsoleDrawingStrategy(const Sudoku *sudoku) {
    auto data = sudoku->getData();

    for (int row = 0; row < ELEMENTS; ++row) {
        if (row % CELL_SIZE == 0 && row != 0) {
            std::cout << std::setfill('-') << std::setw(ELEMENTS * 5 - 3)
                      << "\n";
        }
        for (int col = 0; col < ELEMENTS; ++col) {
            if (col % CELL_SIZE == 0 && col != 0) {
                std::cout << "|\t";
            }
            if (data[row][col] == 0) {
                std::cout << "\t";
                continue;
            }
            std::cout << data[row][col] << "\t";
        }
        std::cout << "\n";
    }
}
