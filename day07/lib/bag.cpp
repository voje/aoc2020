// #define DEBUG

#include <regex>
#include <string>
#include <iostream>
#include <set>

#include "graph.hpp"

class Bag : public aoc2020::Node {
private:
    // Groups:                   m.str(1) m.str(2)                              
    std::regex reg = std::regex("(\\d+)? ?(\\w+ \\w+) bags?");
public:
    Bag(std::string line) {
        std::smatch m;
        std::regex_search(line, m, reg); 
        color = m.str(2);

        line = m.suffix();
        while (std::regex_search(line, m, reg)) {
            #ifdef DEBUG
            std::cout << m.str() << std::endl;
            std::cout << "cnt: " << m.str(1) << std::endl;
            std::cout << "color: " << m.str(2) << std::endl;
            #endif

            if (m.str(1).size() != 0) {
                int count = stoi(m.str(1));
                std::string color = m.str(2);
                contains[color] = count;
            }
            line = m.suffix();
        }

    };
    std::string color;
    std::map<std::string, int> contains;
};

// A bit day07 specific: find all unique nodes on a path to "shiny gold"
void _traverseToRoot(std::shared_ptr<aoc2020::Node> node, std::set<std::string> &uniq) {
    uniq.insert(node->getName());
    for (auto const &e : node->getToEdges()) {
        _traverseToRoot(e->from, uniq);
    }
}

int solveDay07(std::istream& input) {
    aoc2020::Graph g;
    {
        // First pass, add nodes
        std::string line;
        while (std::getline(input, line)) {
            Bag b(line);
            g.addNode(b.color, std::make_shared<Bag>(b));
        }
    }
    input.clear();  // reset the input stream
    input.seekg(0, input.beg);
    {
        // Second pass, add edges
        std::string line;
        while (std::getline(input, line)) {
            Bag b(line);
            for (auto const &pair : b.contains) {
                std::string color = pair.first;
                int count = pair.second;
                g.addEdge(count, b.color, color);
            }
        }
    }

    #ifdef DEBUG
    std::cout << g.toString() << std::endl;
    #endif

    // Start with "shiny gold" node and find all possible paths to root nodes.   
    // Result is the unique set of all nodes in the paths.   
    const std::string targetColor = "shiny gold";
    std::shared_ptr<aoc2020::Node> sg = g.getNode(targetColor);
    std::set<std::string> uniquePathNodes;
    _traverseToRoot(sg, uniquePathNodes);
    uniquePathNodes.erase(targetColor);
    #ifdef DEBUG
    for (auto const &c : uniquePathNodes) {
        std::cout << c << ", ";
    }
    #endif
    return uniquePathNodes.size();
}

// Recursively counts number of contained bags (omits self).   
int _countContainedBags(std::shared_ptr<aoc2020::Node> node) {
    int tmpCnt = 0;
    if (node->getFromEdges().size() == 0) {
        return 0;
    }
    for (auto const &e : node->getFromEdges()) {
        tmpCnt += e->weight * (1 + _countContainedBags(e->to));
    }
    return tmpCnt;
}

int solveDay07Pt2(std::istream &input) {
    aoc2020::Graph g;
    {
        // First pass, add nodes
        std::string line;
        while (std::getline(input, line)) {
            Bag b(line);
            g.addNode(b.color, std::make_shared<Bag>(b));
        }
    }
    input.clear();  // reset the input stream
    input.seekg(0, input.beg);
    {
        // Second pass, add edges
        std::string line;
        while (std::getline(input, line)) {
            Bag b(line);
            for (auto const &pair : b.contains) {
                std::string color = pair.first;
                int count = pair.second;
                g.addEdge(count, b.color, color);
            }
        }
    }

    std::shared_ptr<aoc2020::Node> sg = g.getNode("shiny gold");
    // Subtract the root bag from result.
    return _countContainedBags(sg);
}

std::ostream& operator<<(std::ostream& os, const Bag& b) {
    os << "Bag{ color: " << b.color << " }";
    return os;
}
