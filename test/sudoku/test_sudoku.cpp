#include "gtest/gtest.h"

#include "sudoku.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(sudoku, can_initialize) {
    Sudoku puzzle{};
    SUCCEED();
}

TEST(sudoku, checkRow_success) {

    Sudoku puzzle{};

    sudoku_array test_data{{
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
    puzzle.setData(test_data);

    bool successful{true};
    for (int row = 0; row < ELEMENTS; ++row) {
        successful = successful and puzzle.chekRow(row);
    }

    ASSERT_TRUE(successful);
}

TEST(sudoku, checkRow_failure) {
    Sudoku puzzle{};

    sudoku_array test_data{{
                                   {0, 0, 0, 8, 4, 6, 5, 7, 3},
                                   {0, 8, 3, 5, 7, 1, 2, 9, 4},
                                   {0, 5, 7, 3, 2, 9, 1, 6, 8},
                                   {8, 2, 9, 6, 1, 3, 4, 1, 7},
                                   {1, 6, 4, 9, 5, 7, 8, 3, 2},
                                   {3, 7, 5, 2, 8, 4, 6, 0, 9},
                                   {7, 4, 6, 1, 9, 2, 3, 8, 5},
                                   {5, 9, 1, 4, 3, 8, 7, 2, 6},
                                   {2, 3, 8, 7, 6, 5, 9, 4, 1},
                           }
    };
    puzzle.setData(test_data);

    bool successful{true};
    for (int row = 0; row < ELEMENTS; ++row) {
        successful = successful and puzzle.chekRow(row);
    }

    ASSERT_FALSE(successful);

}

TEST(sudoku, checkColumn_success) {
    Sudoku puzzle{};

    sudoku_array test_data{{
                                   {9, 1, 2, 8, 4, 6, 5, 7, 3},
                                   {0, 0, 0, 5, 7, 1, 2, 9, 4},
                                   {4, 5, 0, 3, 2, 9, 1, 6, 8},
                                   {8, 2, 0, 6, 1, 3, 4, 5, 7},
                                   {1, 6, 4, 9, 5, 7, 8, 3, 2},
                                   {3, 7, 5, 2, 8, 4, 6, 1, 9},
                                   {7, 4, 6, 1, 9, 2, 3, 8, 5},
                                   {5, 9, 1, 4, 3, 8, 7, 2, 6},
                                   {2, 3, 8, 7, 6, 5, 9, 4, 1},
                           }
    };
    puzzle.setData(test_data);

    bool successful{true};
    for (int column = 0; column < ELEMENTS; ++column) {
        successful = successful and puzzle.checkColumn(column);
    }

    ASSERT_TRUE(successful);
}

TEST(sudoku, checkColumn_failure) {
    Sudoku puzzle{};

    sudoku_array test_data{{
                                   {9, 1, 2, 8, 4, 6, 5, 7, 3},
                                   {6, 8, 3, 5, 7, 1, 2, 9, 4},
                                   {0, 0, 7, 3, 2, 9, 1, 6, 8},
                                   {0, 2, 9, 6, 1, 3, 4, 5, 7},
                                   {0, 6, 4, 9, 5, 7, 8, 3, 2},
                                   {3, 7, 5, 2, 8, 4, 6, 1, 9},
                                   {7, 4, 6, 1, 9, 2, 3, 8, 5},
                                   {5, 9, 1, 4, 3, 8, 7, 2, 6},
                                   {2, 3, 8, 7, 1, 5, 9, 4, 0},
                           }
    };
    puzzle.setData(test_data);

    bool successful{true};
    for (int column = 0; column < ELEMENTS; ++column) {
        successful = successful and puzzle.checkColumn(column);
    }

    ASSERT_FALSE(successful);
}

TEST(sudoku, checkCell_successful) {
    Sudoku puzzle{};

    sudoku_array test_data{{
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
    puzzle.setData(test_data);

    bool successful{true};
    for (int row = 0; row < ELEMENTS; ++row) {
        for (int column = 0; column < ELEMENTS; ++column) {
            successful = successful and puzzle.checkBlock(row, column);
        }
    }

    ASSERT_TRUE(successful);
}

TEST(sudoku, checkCell_failure) {
    Sudoku puzzle{};

    sudoku_array test_data{{
                                   {0, 0, 0, 8, 4, 6, 5, 7, 3},
                                   {0, 8, 3, 5, 7, 1, 2, 9, 4},
                                   {0, 5, 7, 3, 2, 9, 1, 6, 8},
                                   {8, 2, 9, 6, 1, 3, 4, 5, 7},
                                   {1, 6, 4, 9, 5, 7, 8, 3, 2},
                                   {3, 7, 5, 1, 8, 4, 6, 0, 9},
                                   {7, 4, 6, 0, 9, 2, 3, 8, 5},
                                   {5, 9, 1, 4, 3, 8, 7, 2, 6},
                                   {2, 3, 8, 7, 6, 5, 9, 4, 1},
                           }
    };
    puzzle.setData(test_data);

    bool successful{true};
    for (int row = 0; row < ELEMENTS; ++row) {
        for (int column = 0; column < ELEMENTS; ++column) {
            successful = successful and puzzle.checkBlock(row, column);
        }
    }

    ASSERT_FALSE(successful);
}