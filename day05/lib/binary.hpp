#pragma once

#include <string>

namespace aoc2020
{

    class Binary
    {
    public:
        Binary(std::string);
        operator int() const;
    private:
        int intRep;
    };

    int GetID(const std::string&);
}