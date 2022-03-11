#ifndef SUDOKU_SUDOKU_H
#define SUDOKU_SUDOKU_H

#include <array>

constexpr unsigned ELEMENTS{9};
constexpr unsigned CELL_SIZE{3};
constexpr unsigned EMPTY_VALUE{10};
typedef std::array<std::array<unsigned, ELEMENTS>, ELEMENTS> sudoku_array;


class Sudoku {
public:
    void setData(const sudoku_array &data);

    void insertNumber(const unsigned &number,
                      const unsigned &row,
                      const unsigned &column);

    bool insertNumberProtected(const unsigned &number,
                               const unsigned &row,
                               const unsigned &column);

    bool chekRow(const unsigned &row);

    bool checkColumn(const unsigned &column);

    bool checkBlock(const unsigned &row,
                    const unsigned &column);

private:
    sudoku_array data_{EMPTY_VALUE};


};


#endif //SUDOKU_SUDOKU_H
