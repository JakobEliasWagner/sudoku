#include "gtest/gtest.h"

#include <vector>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(tests, assert_eq) {
    ASSERT_EQ(0, 0);
}