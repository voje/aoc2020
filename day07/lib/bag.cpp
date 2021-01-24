// #define DEBUG

#include <regex>
#include <string>
#include <iostream>

#include "graph/graph.hpp"

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
