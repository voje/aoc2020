#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "readinput.hpp"

using namespace aoc2020;

TEST(ReadFileTest, abc)
{
    std::vector<std::string> input;
    input = Input::Read("../testdata/input1.txt");

    std::vector<std::string> expected {"a", "b", "c"};

    ASSERT_EQ(input.size(), expected.size());

    for (int i=0; i<expected.size(); i++)
    {
        EXPECT_EQ(input[i], expected[i]);
    }
}

TEST(ReadFileTest, SkipLines)
{
    std::vector<std::string> input;
    input = Input::Read("../testdata/skip_lines.txt");

    std::vector<std::string> expected {"giraffe", "lion", "zebra"};

    ASSERT_EQ(input.size(), expected.size());

    for (int i=0; i<expected.size(); i++)
    {
        EXPECT_EQ(input[i], expected[i]);
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
