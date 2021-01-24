#include <gtest/gtest.h>

#include "bag.cpp"

const std::string input1 = 
"light red bags contain 1 bright white bag, 2 muted yellow bags."
"dark orange bags contain 3 bright white bags, 4 muted yellow bags."
"bright white bags contain 1 shiny gold bag."
"muted yellow bags contain 2 shiny gold bags, 9 faded blue bags."
"shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags."
"dark olive bags contain 3 faded blue bags, 4 dotted black bags."
"vibrant plum bags contain 5 faded blue bags, 6 dotted black bags."
"faded blue bags contain no other bags."
"dotted black bags contain no other bags.";

TEST(bag, twoInside) {
    std::string bagStr("light red bags contain 1 bright white bag, 2 muted yellow bags.");
    Bag b(bagStr);
    EXPECT_EQ(b.color, "light red");
    EXPECT_EQ(b.contains.size(), 2);
}

TEST(bag, oneInside) {
    std::string bagStr("bright white bags contain 1 shiny gold bag.");
    Bag b(bagStr);
    EXPECT_EQ(b.color, "bright white");
    EXPECT_EQ(b.contains.size(), 1);
}

TEST(bag, emptyBag) {
    std::string bagStr("faded blue bags contain no other bags.");
    Bag b(bagStr);
    EXPECT_EQ(b.color, "faded blue");
    EXPECT_EQ(b.contains.size(), 0);
}

TEST(bag, readInput1) {
    std::istringstream f(input1);
    std::string line;    
    while (std::getline(f, line)) {
        EXPECT_NO_THROW(Bag b(line));
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
