#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <istream>

#include "customs.hpp"

using namespace aoc2020;

std::string input = 
"abc\n"
"\n"
"a\n"
"b\n"
"c\n"
"\n"
"ab\n"
"ac\n"
"\n"
"a\n"
"a\n"
"a\n"
"a\n"
"\n"
"b\n"
"\n";

TEST(TestCustoms, ReadInput)
{
    std::vector<Customs> cust; 
    std::istringstream inputIs(input);

    while (true) {
        Customs cc = Customs();
        inputIs >> cc;

        if (cc.countDecls() == 0) {
            break;
        }
        cust.push_back(cc);
    }

    EXPECT_EQ(5, cust.size());

    int sum = 0;
    for (Customs const &c: cust) {
        // std::cout << c << std::endl;
        int cDecls = c.countDecls();
        // std::cout << cDecls << std::endl;
        sum += cDecls;
    }
    EXPECT_EQ(sum, 11);
}

TEST(TestCustoms, ReadInput2)
{
    std::vector<Customs> cust; 
    std::istringstream inputIs(input);

    while (true) {
        Customs cc = Customs();
        inputIs >> cc;

        if (cc.countDecls() == 0) {
            break;
        }
        cust.push_back(cc);
    }

    EXPECT_EQ(5, cust.size());

    int sum = 0;
    for (Customs const &c: cust) {
        // std::cout << c << std::endl;
        int cDecls = c.countMutualDecls();
        // std::cout << cDecls << std::endl;
        sum += cDecls;
    }
    EXPECT_EQ(sum, 6);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
