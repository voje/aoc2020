#include <gtest/gtest.h>

#include "main.cpp"

TEST(SquareRootTest, PositiveNos) { 
    ASSERT_EQ(3, mysum(1, 2));
    // ASSERT_EQ(4, mysum(1, 2));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
