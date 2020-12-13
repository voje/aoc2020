#include <gtest/gtest.h>
#include <string>

#include "passport.hpp"

using namespace aoc2020;

const std::string input = 
"ecl:gry pid:860033327 eyr:2020 hcl:#fffffd\n"
"byr:1937 iyr:2017 cid:147 hgt:183cm\n"
"\n"
"iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884\n"
"hcl:#cfa07d byr:1929\n"
"\n"
"hcl:#ae17e1 iyr:2013\n"
"eyr:2024\n"
"ecl:brn pid:760753108 byr:1931\n"
"hgt:179cm\n"
"\n"
"hcl:#cfa07d eyr:2025 pid:166559648\n"
"iyr:2011 ecl:brn hgt:59in\n";

TEST(PassportTest, InitFromIstream)
{
    std::vector<Passport> passports; 
    std::istringstream inputIs(input);

    while (true) {
        Passport pp = Passport();
        inputIs >> pp;

        if (pp.rawInput.size() == 0) {
            break;
        }

        passports.push_back(pp);
    }

    EXPECT_EQ(passports[0].extractVal("ecl"), "gry");
    EXPECT_EQ(passports[1].extractVal("cid"), "350");
    EXPECT_EQ(passports[2].extractVal("hgt"), "179cm");
    EXPECT_EQ(passports[3].extractVal("hcl"), "#cfa07d");
}

TEST(PassportTest, isValid)
{
    std::vector<Passport> passports; 
    std::istringstream inputIs(input);

    while (true) {
        Passport pp = Passport();
        inputIs >> pp;

        if (pp.rawInput.size() == 0) {
            break;
        }

        passports.push_back(pp);
    }

    EXPECT_EQ(passports[0].isValid(), true);
    EXPECT_EQ(passports[1].isValid(), false);
    EXPECT_EQ(passports[2].isValid(), true);
    EXPECT_EQ(passports[3].isValid(), false);
}

TEST(PassportTest, validByr)
{
    EXPECT_EQ(Passport::validByr("2002"), true);
    EXPECT_EQ(Passport::validByr("2003"), false);
    EXPECT_EQ(Passport::validByr("1920"), true);
    EXPECT_EQ(Passport::validByr("1919"), false);
}

TEST(PassportTest, validIyr)
{
    EXPECT_EQ(Passport::validIyr("2010"), true);
    EXPECT_EQ(Passport::validIyr("2020"), true);
    EXPECT_EQ(Passport::validIyr("2009"), false);
    EXPECT_EQ(Passport::validIyr("2021"), false);
}

TEST(PassportTest, validHgt)
{
    EXPECT_EQ(Passport::validHgt("60in"), true);
    EXPECT_EQ(Passport::validHgt("190cm"), true);
    EXPECT_EQ(Passport::validHgt("190in"), false);
    EXPECT_EQ(Passport::validHgt("190"), false);
}

TEST(PassportTest, validHCl)
{
    EXPECT_EQ(Passport::validHcl("#123abc"), true);
    EXPECT_EQ(Passport::validHcl("#123abz"), false);
    EXPECT_EQ(Passport::validHcl("123abc"), false);
    EXPECT_EQ(Passport::validHcl("11#123abc"), false);
    EXPECT_EQ(Passport::validHcl("#123abc11"), false);
    EXPECT_EQ(Passport::validHcl("#121"), false);
}

TEST(PassportTest, validEcl)
{
    EXPECT_EQ(Passport::validEcl("brn"), true);
    EXPECT_EQ(Passport::validEcl("wat"), false);
    EXPECT_EQ(Passport::validEcl(""), false);
}

TEST(PassportTest, validPid)
{
    EXPECT_EQ(Passport::validPid("000000001"), true);
    EXPECT_EQ(Passport::validPid("0123456789"), false);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
