#include <sstream>
#include <iostream>

#include "graph.hpp"

namespace aoc2020 {

    void Graph::addNode(std::string name) {
        std::shared_ptr<Node> np = std::make_shared<Node>(Node(name));
        nodes[name] = np;
    }

    void Graph::addNode(std::string name, std::shared_ptr<Node> nodePtr) {
        nodes[name] = nodePtr;
    }

    std::shared_ptr<Node> Graph::getNode(std::string name) {
        return nodes[name];
    }

    Node::Node(std::string nname) {
        name = nname;
    }

    std::vector<std::shared_ptr<Edge>> Node::getFromEdges() {
        std::vector<std::shared_ptr<Edge>> res;
        for (auto &e: edges) {
            #ifdef DEBUG
            std::cout << e->from << std::endl;
            #endif

            if (e->from->name == name) {
                res.push_back(e);
            }
        }
        return res;
    }

    std::vector<std::shared_ptr<Edge>> Node::getToEdges() {
        std::vector<std::shared_ptr<Edge>> res;
        for (auto &e: edges) {
            if (e->to.get() == this) {
                res.push_back(e);
            }
        }
        return res;
    }

    std::string Node::getName() const {
        return name;
    }

    void Node::addEdge(std::shared_ptr<Edge> e) {
        edges.push_back(e);
    };

    std::string Node::toString() const {
        std::stringstream ss;
        ss << "Node{ ";
        ss << " name: " << name;
        ss << " ptr: " << this;
        ss << " edges: [";
        for (auto const &edge: edges) {
            ss << edge->toString() << ", ";
        }
        ss << "]";
        ss << "}";
        return ss.str();
    }

    Edge::Edge(int w, std::shared_ptr<Node> fromNode, std::shared_ptr<Node> toNode) {
        weight = w;
        from = fromNode;
        to = toNode;
    }

    std::string Edge::toString() const {
        std::stringstream ss;
        ss << "Edge{ ";
        ss << " ptr: " << this;
        ss << " from: " << from;
        ss << " to: " << to;
        ss << "}";
        return ss.str();
    }

    void Graph::addEdge(int weight, std::string from, std::string to) {
        std::shared_ptr<Node> pFrom = nodes[from];
        std::shared_ptr<Node> pTo = nodes[to];
        std::shared_ptr<Edge> edg = std::make_shared<Edge>(Edge(1, pFrom, pTo));
        this->edges.push_back(edg);
        pFrom->edges.push_back(edg);
        pTo->edges.push_back(edg);
    }

    // Init with depth = 0
    std::string Graph::toString(std::string startNode, int depth) {
        std::stringstream ss;
        std::shared_ptr<Node> sn = nodes[startNode];

        std::cout << sn->name << std::endl;

        ss << "(" << sn->name << ")";

        for (auto &e: sn->edges) {
            std::shared_ptr<Node> n = e->from;

            std::cout << n << std::endl;

            if (e->from->name == sn->name) {
                std::cout << e->from->name << std::endl;
                std::cout << e->to->name << std::endl;

                ss << std::string(depth, '-');
                ss << toString(e->to->name, depth++);
            }
        }
        return ss.str();
    }

    void Graph::printNodes() {
        std::cout << "Nodes:" << std::endl;

        for (auto const &n: nodes) {
            std::cout << n.first << ": ";
            std::cout << (n.second)->toString() << std::endl;
        }
    }

    void Graph::printEdges() {
        std::cout << "Edges:" << std::endl;
        for (auto const &e: edges) {
            std::cout << "from: " << e->from << std::endl;
            std::cout << "to: " << e->to << std::endl;
        }
    }

}