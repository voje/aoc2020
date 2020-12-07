#include <gtest/gtest.h>

#include "map.hpp"

using namespace aoc2020;

const std::vector<std::string> input1 {
    "..##.......",
    "#...#...#..",
    ".#....#..#.",
    "..#.#...#.#",
    ".#...##..#.",
    "..#.##.....",
    ".#.#.#....#",
    ".#........#",
    "#.##...#...",
    "#...##....#",
    ".#..#...#.#",
};

const std::vector<std::string> input2 {
    "..#..",
    ".#...",
    "##...",
    ".#.#.",
    "#...#",
    ".....",
    "...#.",
    "...##",
    "#..##",
};

TEST(MapTest, testConstructor1)
{
    Map m(input1);

    // std::cout << m << std::endl;

    EXPECT_EQ('.', m.Get(0, 0));
    EXPECT_EQ('#', m.Get(7, 8));
    EXPECT_EQ('#', m.Get(5, 4));
    EXPECT_EQ('#', m.Get(10, 10));

}

TEST(MapTest, testConstructor2)
{
    Map m(input2);

    // std::cout << m << std::endl;

    EXPECT_EQ('.', m.Get(0, 0));
    EXPECT_EQ('#', m.Get(0, 2));
    EXPECT_EQ('.', m.Get(1, 8));
    EXPECT_EQ('#', m.Get(3, 7));
}

TEST(MapTest, testWrap)
{
    Map m(input2);

    // std::cout << m << std::endl;

    // Wrap x
    EXPECT_EQ('.', m.Get(11, 0));
    EXPECT_EQ('#', m.Get(12, 0));

    // Wrap y
    EXPECT_EQ('#', m.Get(0, 11));
    EXPECT_EQ('.', m.Get(0, 12));
    EXPECT_EQ('#', m.Get(0, 13));
}

TEST(MapTest, testTraverse1)
{
    Map m(input1);

    std::cout << m << std::endl;
    uint32_t treeCount = m.Traverse();
    std::cout << m << std::endl;

    EXPECT_EQ(treeCount, 7);
}

TEST(MapTest, testTraverse2)
{
    Map m(input2);

    std::cout << m << std::endl;
    uint32_t treeCount = m.Traverse();
    std::cout << m << std::endl;

    EXPECT_EQ(treeCount, 3);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
