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
"dotted black bags contain no other bags.\n";

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

TEST(bag, solveInput) {
    // TODO: put this in a separate function

    aoc2020::Graph g;
    {
        // First pass, add nodes
        std::istringstream iss(input1);
        std::string line;
        while (std::getline(iss, line)) {
            Bag b(line);
            g.addNode(b.color, std::make_shared<Bag>(b));
        }
    }
    {
        // Second pass, add edges
        std::istringstream iss(input1);
        std::string line;
        while (std::getline(iss, line)) {
            Bag b(line);
            for (auto const &pair : b.contains) {
                std::string color = pair.first;
                int count = pair.second;
                g.addEdge(count, b.color, color);
            }
        }
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
