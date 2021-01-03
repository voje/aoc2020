#include <gtest/gtest.h>

#include "graph.hpp"

#include <vector>

using namespace aoc2020;

TEST(Graph, Create)
{
    Graph g;
    g.addNode("a");
    g.addNode("b");
    g.printNodes();

    g.addEdge(1, "a", "b");
    g.printNodes();
    g.printEdges();

    std::cout << g.toString("a", 0) << std::endl;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
