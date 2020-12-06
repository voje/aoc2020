#include <string>
#include <regex>

#include "pwrecord.hpp"

namespace aoc2020
{

    PwRecord::PwRecord(std::string str)
    {
        std::regex regExpr ("^(\\d*)-(\\d*)\\s(.):\\s(.*)$");
        std::regex_match(str, regExpr);
        std::smatch matches;

        std::regex_search(str, matches, regExpr);
        
        this->minCount = matches[0];
        this->maxCount = matches[1];
        this->chr = matches[2];
        this->password = matches[3];
    }

    bool PwRecord::IsValid() {
        return false;  // TODO
    }

}