#pragma once

#include <vector>
#include <string>
#include <map>

namespace aoc2020 {

    class Node;

    class Edge {
    friend class Graph;
    friend class Node;
    public:
        Edge(int w, Node *fromNode, Node *toNode);
        std::string toString() const;
        int weight;
        Node *from;
        Node *to;
    };

    class Node {
    friend class Graph;
    public:
        Node() {};
        Node(std::string name);
        std::string getName() const;
        void addEdge(Edge*);
        std::vector<Edge*> getFromEdges();
        std::vector<Edge*> getToEdges();
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
        Node* getNode(std::string name);

        void addEdge(int weight, std::string from, std::string to);

        void printNodes();
        void printEdges();
        
        std::string toString(std::string startNode, int depth);
    private:
        std::map<std::string, Node*> nodes;
        std::vector<Edge*> edges;
    };

}