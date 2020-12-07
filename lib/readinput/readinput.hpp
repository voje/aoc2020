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
        static std::vector<std::string> ReadWithEmptyLines(const std::string& filepath);
    private:
        static std::vector<std::string> _read(const std::string& filepath, bool skipEmptyLines);
    };

}