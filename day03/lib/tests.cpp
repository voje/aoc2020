#include <gtest/gtest.h>

#include "map.hpp"

using namespace aoc2020;

const std::vector<std::string> input {
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

const std::vector<std::string> input1 {
    "..#..",
    ".#...",
    "##...",
    ".#.#.",
    "..#..",
    ".#...",
    ".#.#.",
};

TEST(MapTest, testMapWithoutWrap)
{
    Map m(input[0].size(), input.size());

    for (size_t y = 0; y < input.size(); y++) {
        for (size_t x = 0; x < input.size(); x++) {
            m.Set(x, y, input[y][x]);
        }
    }
    // std::cout << m << std::endl;

    EXPECT_EQ('.', m.Get(0, 0));
    EXPECT_EQ('#', m.Get(0, 1));
    EXPECT_EQ('#', m.Get(2, 0));
    EXPECT_EQ('#', m.Get(2, 3));
}

TEST(MapTest, testWrap)
{
    Map m(input[0].size(), input.size());

    for (size_t y = 0; y < input.size(); y++) {
        for (size_t x = 0; x < input.size(); x++) {
            m.Set(x, y, input[y][x]);
        }
    }
    // std::cout << m << std::endl;

    // Wrap x
    EXPECT_EQ('.', m.Get(11, 0));
    EXPECT_EQ('#', m.Get(13, 0));

    // Wrap y
    EXPECT_EQ('.', m.Get(0, 11));
    EXPECT_EQ('#', m.Get(0, 12));
    EXPECT_EQ('.', m.Get(0, 13));
}

TEST(MapTest, testSetGet)
{
    Map m(5, 5);

    m.Set(11, 0, 'C');
    EXPECT_EQ('C', m.Get(11, 0));
}

TEST(MapTest, testTraverse)
{
    Map m(input[0].size(), input.size());

    for (size_t y = 0; y < input.size(); y++) {
        for (size_t x = 0; x < input.size(); x++) {
            m.Set(x, y, input[y][x]);
        }
    }

    std::cout << m << std::endl;
    uint32_t treeCount = m.Traverse();
    std::cout << m << std::endl;

    EXPECT_EQ(treeCount, 7);
}

TEST(MapTest, testTraverse1)
{
    Map m(input1[0].size(), input1.size());
    std::cout << m << std::endl;

    for (size_t y = 0; y < input1.size(); y++) {
        for (size_t x = 0; x < input1.size(); x++) {
            m.Set(x, y, input1[y][x]);
        }
    }

    std::cout << m << std::endl;
    uint32_t treeCount = m.Traverse();
    std::cout << m << std::endl;

    EXPECT_EQ(treeCount, 7);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
