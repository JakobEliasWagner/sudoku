
#include <algorithm>
#include <utility>
#include "sudoku.h"
#include "drawing_strategies/console_drawing_strategy.h"

void Sudoku::insertNumber(const unsigned int &number, const unsigned int &row,
                          const unsigned int &column) {
    data_[row][column] = number;
}


bool Sudoku::insertNumberProtected(const unsigned int &number,
                                   const unsigned int &row,
                                   const unsigned int &column) {
    insertNumber(number, row, column);

    auto row_ok = chekRow(row);
    auto column_ok = checkColumn(column);
    auto block_ok = checkBlock(row, column);

    // sudoku game logic
    if (row_ok && column_ok && block_ok) {
        return true;
    }

    // when rules are violated, reset cell and indicate failure with false
    insertNumber(0, row, column);
    return false;
}

bool Sudoku::chekRow(const unsigned int &row) {
    for (auto element = 0; element < ELEMENTS; ++element) {
        if (data_[row][element] == 0) continue;
        auto i = std::find(data_[row].begin() + element + 1,
                           data_[row].end(),
                           data_[row][element]);
        if (i != std::end(data_[row])) return false;
    }
    return true;
}

bool Sudoku::checkColumn(const unsigned int &column) {
    for (auto row = 0; row < ELEMENTS; ++row) {
        if (data_[row][column] == 0) continue;
        for (auto i = row + 1; i < ELEMENTS; ++i) {
            if (data_[row][column] == data_[i][column]) return false;
        }
    }
    return true;
}

bool Sudoku::checkBlock(const unsigned int &row, const unsigned int &column) {
    auto cell_value = data_[row][column];
    if (cell_value == 0) return true;

    auto cell_row = row / CELL_SIZE;
    auto cell_column = column / CELL_SIZE;

    auto min_row = cell_row * CELL_SIZE;
    auto max_row = (cell_row + 1) * CELL_SIZE;

    auto min_col = cell_column * CELL_SIZE;
    auto max_col = (cell_column + 1) * CELL_SIZE;

    for (auto row_tst = min_row; row_tst < max_row; ++row_tst) {
        for (auto col_tst = min_col; col_tst < max_col; ++col_tst) {
            if (row_tst == row && col_tst == column) continue;
            if (cell_value == data_[row_tst][col_tst]) return false;
        }
    }
    return true;
}

void Sudoku::setData(const sudoku_array &data) {
    data_ = data;
}

const sudoku_array &Sudoku::getData() const {
    return data_;
}

Sudoku::Sudoku(SudokuDrawingStrategy drawing_strategy)
        : drawing(std::move(drawing_strategy)) {

}

Sudoku::Sudoku()
        : drawing(ConsoleDrawingStrategy) {

}

