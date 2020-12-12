#include <iostream>

#include "passport.hpp"

namespace aoc2020
{
/*
    byr (Birth Year)
    iyr (Issue Year)
    eyr (Expiration Year)
    hgt (Height)
    hcl (Hair Color)
    ecl (Eye Color)
    pid (Passport ID)
    cid (Country ID)
*/

    // cout << obj << "," << endl;
    std::ostream & operator << (std::ostream &out, const Passport &c)
    {
        return std::cout << c.rawInput << std::endl;
    }

    std::istream & operator >> (std::istream &in,  Passport &c)
    {
        c.rawInput = "";

        std::string line;

        while (std::getline(in, line)) {
            if (line.size() == 0) {
                return in;
            }
            if (c.rawInput.size() != 0) {
                c.rawInput.append(" ");
            }
            c.rawInput.append(line);
        }

        return in; 
    }

}
