#include <vector>
#include <string>
#include <fstream>

#include "readinput.hpp"

namespace aoc2020
{

    std::vector<std::string> Input::Read(const std::string& filepath)
    {
        std::string line;
        std::vector<std::string> lines;
        std::ifstream inputFile(filepath);

        if (inputFile.is_open())
        {
            while (std::getline(inputFile, line))
            {
                if (line.size() > 0)
                {
                    lines.push_back(line);
                }
            }     
        }
        return lines;
    }

}