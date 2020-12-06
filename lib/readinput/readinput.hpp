#pragma once

#include <vector>
#include <string>

namespace aoc2020
{
    class Input
    {
    public:
        // Reads input.txt into a strings vector
        // Ignores empty lines
        static std::vector<std::string> Read(const std::string& filepath);
    };

}