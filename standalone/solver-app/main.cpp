#include <iostream>

#include "sudoku.h"

int main(int argc, char *argv[]) {
    Sudoku sudoku{};

    sudoku_array data{{
                              {0, 0, 0, 8, 4, 6, 5, 7, 3},
                              {0, 8, 3, 5, 7, 1, 2, 9, 4},
                              {0, 5, 7, 3, 2, 9, 1, 6, 8},
                              {8, 2, 9, 6, 1, 3, 4, 5, 7},
                              {1, 6, 4, 9, 5, 7, 8, 3, 2},
                              {3, 7, 5, 2, 8, 4, 6, 1, 9},
                              {7, 4, 6, 1, 9, 2, 3, 8, 5},
                              {5, 9, 1, 4, 3, 8, 7, 2, 6},
                              {2, 3, 8, 7, 6, 5, 9, 4, 1},
                      }
    };

    sudoku.setData(data);

    sudoku.draw();

    return 0;
}