#include <sstream>
#include <iostream>

#include "graph.hpp"

namespace aoc2020 {

    void Graph::addNode(std::string name) {
        std::shared_ptr<Node> np = std::make_shared<Node>(Node(name));
        nodes[name] = np;
    }

    void Graph::addNode(std::string name, std::shared_ptr<Node> nodePtr) {
        nodePtr -> name = name;
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
        ss << " weight: " << weight;
        ss << " ptr: " << this;
        ss << " from: " << from->getName();
        ss << " to: " << to->getName();
        ss << "}";
        return ss.str();
    }

    void Graph::addEdge(int weight, std::string from, std::string to) {
        std::shared_ptr<Node> pFrom = nodes[from];
        std::shared_ptr<Node> pTo = nodes[to];
        std::shared_ptr<Edge> edg = std::make_shared<Edge>(Edge(weight, pFrom, pTo));
        this->edges.push_back(edg);
        pFrom->edges.push_back(edg);
        pTo->edges.push_back(edg);
    }

    // Return nodes with no inbound edeges
    std::vector<std::string> Graph::getRootNodes() {
        std::vector<std::string> rootNodes;
        for (auto const &n : nodes) {
            if (n.second->getToEdges().size() == 0) {
                rootNodes.push_back(n.first);
            }
        }
        return rootNodes;
    }

    // toString finds all root nodes and prints out trees beginning in those nodes.   
    // Does not handle cycles.   
    std::string Graph::toString() {
        std::vector<std::string> rootNodes = getRootNodes();

        std::stringstream ss;
        ss << "root nodes: ";
        for (auto const &rn : rootNodes) {
            ss << rn << ", ";
        }
        ss << std::endl;

        for (auto const &rn : rootNodes) {
            ss << toString(rn, 0);
        }
        return ss.str();
    }

    // Init with depth = 0
    std::string Graph::toString(std::string startNode, int depth) {
        std::stringstream ss;
        std::shared_ptr<Node> sn = nodes[startNode];

        if (depth == 0) {
            ss << std::endl << "Root node: " << startNode << std::endl;
        }
        ss << std::string(depth*2, '-') << sn->name << std::endl;

        for (auto &e: sn->getFromEdges()) {
            ss << toString(e->to->name, depth + 1);
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