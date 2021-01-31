#include <gtest/gtest.h>
#include <memory>

#include "bag.cpp"

const std::string input1 = 
"light red bags contain 1 bright white bag, 2 muted yellow bags.\n"
"dark orange bags contain 3 bright white bags, 4 muted yellow bags.\n"
"bright white bags contain 1 shiny gold bag.\n"
"muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.\n"
"shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.\n"
"dark olive bags contain 3 faded blue bags, 4 dotted black bags.\n"
"vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.\n"
"faded blue bags contain no other bags.\n"
"\n"
"dotted black bags contain no other bags.\n"
"\n";

const std::string input2 = 
"shiny gold bags contain 2 dark red bags.\n"
"dark red bags contain 2 dark orange bags.\n"
"dark orange bags contain 2 dark yellow bags.\n"
"dark yellow bags contain 2 dark green bags.\n"
"dark green bags contain 2 dark blue bags.\n"
"dark blue bags contain 2 dark violet bags.\n"
"dark violet bags contain no other bags.\n";

const std::string input3 = 
"shiny gold bags contain 2 dark red bags, 3 light red bags, 1 spotted red bag.\n"
"dark red bags contain 2 dark orange bags.\n"
"light red bags contain 1 light orange bag.\n"
"spotted red bags contain 3 spotted orange bags.\n"
"dark orange bags contain no other bags.\n"
"light orange bags contain no other bags.\n"
"spotted orange bags contain no other bags.\n";

const std::string input4 = 
"shiny gold bags contain 3 light red bags.\n"
"light red bags contain 4 light orange bags.\n"
"light orange bags contain 2 light purple bags.\n"
"light purple bags contain no other bags.\n";

const std::string input5 = 
"shiny gold bags contain 3 red bags.\n"
"red bags contain 2 orange bags, 2 green bags.\n"
"orange bags contain no other bags.\n"
"green bags contain no other bags.\n";

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

TEST(bag, addToGraph) {
    aoc2020::Graph g;
    Bag b("faded blue bags contain no other bags.");
    g.addNode(std::string("testNode"), std::make_shared<Bag>(b));
}

TEST(pt1, input1) {
    std::istringstream is(input1);
    int solution = solveDay07(is);
    EXPECT_EQ(solution, 4);
}

TEST(pt2, input2) {
    std::istringstream is(input2);
    int solution = solveDay07Pt2(is);
    EXPECT_EQ(solution, 126);
}

TEST(pt2, input3) {
    std::istringstream is(input3);
    int solution = solveDay07Pt2(is);
    EXPECT_EQ(solution, 16);
}

TEST(pt2, input4) {
    std::istringstream is(input4);
    int solution = solveDay07Pt2(is);
    EXPECT_EQ(solution, 39);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
