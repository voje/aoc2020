#include <string>
#include <iostream>
#include <regex>

#include "pwrecord.hpp"

namespace aoc2020
{

    PwRecord::PwRecord(std::string str)
    {
        std::regex regExpr ("^(\\d*)-(\\d*)\\s(.):\\s(.*)$");
        std::regex_match(str, regExpr);
        std::smatch matches;

        // match 0 is the whole string...
        std::regex_search(str, matches, regExpr);

        this->minCount = std::stoi(matches[1]);
        this->maxCount = std::stoi(matches[2]);

        std::string tmpChr = matches[3];
        this->chr = tmpChr.c_str()[0];
        this->password = matches[4];
    }

    bool PwRecord::IsValid() {
        int count = 0;
        for (char const &c: this->password) {
            if (c == this->chr) {
                count++;
            }
        }
        if (count < this->minCount || count > this->maxCount) {
            return false;
        }
        return true;
    }

    // Expect EXACTLY one occurrence of character on predefined locations
    bool PwRecord::IsValidInSecondJob() {
        int count = 0;
        // std::cout << "at min: " << this->password.at(this->minCount - 1) << std::endl;
        if (this->password.at(this->minCount - 1) == this->chr) {
            count++;
        }
        // std::cout << "at max: " << this->password.at(this->maxCount - 1) << std::endl;
        if (this->password.at(this->maxCount - 1) == this->chr) {
            count++;
        }
        return count == 1;
    }

    std::ostream& operator<<(std::ostream& ost, const PwRecord& obj) {
        ost << "min:" << std::to_string(obj.minCount) << std::endl;
        ost << "max:" << std::to_string(obj.maxCount) << std::endl;
        ost << "chr:" << obj.chr << std::endl;
        ost << "pas:" << obj.password << std::endl;
        return ost;
    }             

}