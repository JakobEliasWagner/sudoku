#ifndef SUDOKU_SUDOKU_H
#define SUDOKU_SUDOKU_H

#include <array>
#include <functional>
#include <memory>

constexpr unsigned ELEMENTS{9};
constexpr unsigned CELL_SIZE{3};
constexpr unsigned EMPTY_VALUE{10};
typedef std::array<std::array<unsigned, ELEMENTS>, ELEMENTS> sudoku_array;

class Sudoku;

typedef std::function<void(Sudoku const *)> SudokuDrawingStrategy;

class Sudoku {
public:
    Sudoku();

    explicit Sudoku(SudokuDrawingStrategy drawing_strategy);

    void setData(const sudoku_array &data);

    void insertNumber(const unsigned &number,
                      const unsigned &row,
                      const unsigned &column);

    bool insertNumberProtected(const unsigned &number,
                               const unsigned &row,
                               const unsigned &column);

    [[nodiscard]] const sudoku_array &getData() const;

    void draw() {
        drawing(this);
    }

    bool chekRow(const unsigned &row);

    bool checkColumn(const unsigned &column);

    bool checkBlock(const unsigned &row,
                    const unsigned &column);

private:
    sudoku_array data_{EMPTY_VALUE};
    SudokuDrawingStrategy drawing;

};


#endif //SUDOKU_SUDOKU_H
