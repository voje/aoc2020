#pragma once

#include <vector>
#include <string>
#include <map>
#include <memory>

namespace aoc2020 {

    class Node;

    class Edge {
    friend class Graph;
    friend class Node;
    public:
        Edge(int w, std::shared_ptr<Node> fromNode, std::shared_ptr<Node> toNode);
        std::string toString() const;
        int weight;
        std::shared_ptr<Node> from;
        std::shared_ptr<Node> to;
    };

    class Node {
    friend class Graph;
    public:
        Node() {};
        Node(std::string name);
        std::string getName() const;
        void addEdge(std::shared_ptr<Edge>);
        std::vector<std::shared_ptr<Edge>> getFromEdges();
        std::vector<std::shared_ptr<Edge>> getToEdges();
        std::string toString() const;
    private:
        std::string name;
        std::vector<int> testVector;
        std::vector<std::shared_ptr<Edge>> edges;
    };

    class Graph {
    public:
        Graph() {};
        void addNode(std::string name);
        void addNode(std::string name, std::shared_ptr<Node> nodePtr);
        std::shared_ptr<Node> getNode(std::string name);

        void addEdge(int weight, std::string from, std::string to);

        void printNodes();
        void printEdges();
        
        std::string toString(std::string startNode, int depth);
    private:
        std::map<std::string, std::shared_ptr<Node>> nodes;
        std::vector<std::shared_ptr<Edge>> edges;
    };

}