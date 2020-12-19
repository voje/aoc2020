#include "binary.hpp"
#include <iostream>
#include <string>
#include <algorithm>

namespace aoc2020
{
    Binary::Binary(std::string inStr)
    {
        size_t strLen = inStr.size();
        int builder = 0;
        for (int i = 0; i < strLen; i++) {
            builder = builder << 1;
            if (inStr.at(i) == '1') {
                builder = builder | 1;
            }
        }
        this->intRep = builder;
    }

    Binary::operator int() const
    {
        return this->intRep;
    }

    int GetID(const std::string &inStr)
    {
        std::string ret = inStr;
        std::replace(ret.begin(), ret.end(), 'B', '1');
        std::replace(ret.begin(), ret.end(), 'F', '0');
        std::replace(ret.begin(), ret.end(), 'R', '1');
        std::replace(ret.begin(), ret.end(), 'L', '0');
        return int(Binary(ret));
    }
}
