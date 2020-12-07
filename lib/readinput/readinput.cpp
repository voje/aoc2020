#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "readinput.hpp"

namespace aoc2020
{
    std::vector<std::string> Input::Read(const std::string& filepath)
    {
        return Input::_read(filepath, true);
    }

    std::vector<std::string> Input::ReadWithEmptyLines(const std::string& filepath)
    {
        return Input::_read(filepath, true);
    }

    std::vector<std::string> Input::_read(const std::string& filepath, bool skipEmptyLines)
    {
        std::string line;
        std::vector<std::string> lines;
        std::ifstream inputFile(filepath);

        if (inputFile.is_open()) {
            while (std::getline(inputFile, line)) {
                if (line.size() == 0 && skipEmptyLines) {
                    continue;
                }
                lines.push_back(line);
            }     
        }
        return lines;
    }

}