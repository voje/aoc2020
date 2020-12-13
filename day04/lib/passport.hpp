#pragma once

#include <iostream>
#include <string>

namespace aoc2020
{

    class Passport
    {
    public:
        friend std::ostream & operator << (std::ostream &out, const Passport &c); 
        friend std::istream & operator >> (std::istream &in,  Passport &c); 
        std::string rawInput;
        std::string extractVal(std::string field) const;

        bool isValid() const;
        bool isValidStrict() const;

        static bool validByr(std::string);
        static bool validIyr(std::string);
        static bool validEyr(std::string);
        static bool validHgt(std::string);
        static bool validHcl(std::string);
        static bool validEcl(std::string);
        static bool validPid(std::string);
        static bool validCid(std::string);
    };


}