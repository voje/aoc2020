#pragma once

#include <vector>
#include <string>
#include <map>

namespace aoc2020 {

    class Node;

    class Edge {
    friend class Graph;
    public:
        Edge(int w, Node *fromNode, Node *toNode);
        std::string toString() const;
    private:
        int weight;
        Node *from;
        Node *to;
    };

    class Node {
    friend class Graph;
    public:
        Node() {};
        Node(std::string name);
        std::string toString() const;
    private:
        std::string name;
        std::vector<int> testVector;
        std::vector<Edge*> edges;
    };

    class Graph {
    public:
        Graph() {};
        void addNode(std::string name);
        void addEdge(int weight, std::string from, std::string to);

        void printNodes();
        void printEdges();
        
        std::string toString(std::string startNode, int depth);
    private:
        std::map<std::string, Node> nodes;
        std::vector<Edge> edges;
    };

}