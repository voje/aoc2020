#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "pwrecord.hpp"

using namespace aoc2020;

const std::vector<std::string> inputs {
    "1-3 a: abcde",
    "1-3 b: cdefg",
    "2-9 c: ccccccccc",
};

TEST(PwRecordTest, partOne)
{
    const std::vector<bool> outputs {
        true,
        false,
        true,
    };

    for (size_t i = 0; i<inputs.size(); i++)
    {
        PwRecord rec (inputs[i]);
        // std::cout << rec << std::endl;
        EXPECT_EQ(rec.IsValid(), outputs[i]);
    }
}

TEST(PwRecordTest, partTwo)
{
    const std::vector<bool> outputs {
        true,
        false,
        false,
    };

    for (size_t i = 0; i<inputs.size(); i++)
    {
        PwRecord rec (inputs[i]);
        // std::cout << rec << std::endl;
        EXPECT_EQ(rec.IsValidInSecondJob(), outputs[i]);
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
