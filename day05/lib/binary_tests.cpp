#include <gtest/gtest.h>

#include "binary.hpp"
#include <string>

using namespace aoc2020;



TEST(TestBinary, InitTest)
{
    EXPECT_EQ(1, Binary("1"));
    EXPECT_EQ(1, Binary("00001"));
    EXPECT_EQ(2, Binary("00010"));
    EXPECT_EQ(3, Binary("00011"));
    EXPECT_EQ(5, Binary("00101"));
    EXPECT_EQ(14, Binary("01110"));
    EXPECT_EQ(20, Binary("10100"));
    EXPECT_EQ(256, Binary("100000000"));
    EXPECT_EQ(257, Binary("0100000001"));
    EXPECT_EQ(1025, Binary("010000000001"));
}

TEST(TestBinary, TestGetID)
{
    EXPECT_EQ(567, GetID("BFFFBBFRRR"));
    EXPECT_EQ(119, GetID("FFFBBBFRRR"));
    EXPECT_EQ(820, GetID("BBFFBBFRLL"));

}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
