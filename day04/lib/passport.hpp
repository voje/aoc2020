#pragma once

#include <iostream>

namespace aoc2020
{

    class Passport
    {
    public:
        Passport() {};
        friend std::ostream & operator << (std::ostream &out, const Passport &c); 
        friend std::istream & operator >> (std::istream &in,  Passport &c); 
        std::string rawInput;
    };

}