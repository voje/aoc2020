#include <gtest/gtest.h>

#include "graph.hpp"

#include <vector>

using namespace aoc2020;

TEST(Graph, addNode)
{
    Graph g;
    std::vector<std::string> nodeNames = {
        "test111", "test222", "test333"
    };

    for (auto &nn: nodeNames) {
        g.addNode(nn);
    }
    
    for (auto &nn: nodeNames) {
        std::shared_ptr<Node> n = g.getNode(nn);
        EXPECT_EQ(n->getName(), nn);
    }
}

TEST(Node, addEdge) {
    std::shared_ptr<Node> n1 = std::make_shared<Node>(Node("testNode1"));
    std::shared_ptr<Node> n2 = std::make_shared<Node>(Node("testNode2"));

    std::shared_ptr<Edge> e = std::make_shared<Edge>(Edge(1, n1, n2));
    EXPECT_EQ(e->from, n1);
    EXPECT_EQ(e->to, n2);

    n1->addEdge(e);
    n2->addEdge(e);


    EXPECT_EQ(n1->getFromEdges().size(), 1);
    EXPECT_EQ(n1->getToEdges().size(), 0);
    EXPECT_EQ(n2->getFromEdges().size(), 0);
    EXPECT_EQ(n2->getToEdges().size(), 1);

    // std::cout << e->toString() << std::endl;

    std::vector<std::shared_ptr<Edge>> fromEdges = n1->getFromEdges();
    EXPECT_EQ(fromEdges.size(), 1);
    std::vector<std::shared_ptr<Edge>> toEdges= n1->getFromEdges();
    EXPECT_EQ(toEdges.size(), 1);

    EXPECT_EQ(fromEdges[0]->from->getName(), "testNode1");
    EXPECT_EQ(toEdges[0]->to->getName(), "testNode2");
}

TEST(Graph, addEdge)
{
    Graph g;
    std::vector<std::string> nodeNames = {
        "test111", "test222"
    };

    for (auto &nn: nodeNames) {
        g.addNode(nn);
    }

    g.addEdge(1, "test111", "test222");
    // g.printEdges();
    // g.printNodes();

    std::shared_ptr<Node> n = g.getNode("test111");
    std::vector<std::shared_ptr<Edge>> ve = n->getFromEdges();
    /*
    for (auto &e: ve) {
        std::cout << e->toString() << std::endl;
    }
    */
}

TEST(Graph, Create)
{
    Graph g;
    g.addNode("a");
    g.addNode("b");
    // g.printNodes();

    g.addEdge(1, "a", "b");
    // g.printNodes();
    // g.printEdges();

    // std::cout << g.toString("a", 0) << std::endl;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
