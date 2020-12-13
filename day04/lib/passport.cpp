#include <iostream>
#include <string>
#include <vector>
#include <regex>

#include "passport.hpp"

namespace aoc2020
{
    std::string Passport::extractVal(std::string field) const {
        std::stringstream ss;
        ss << field << ":([^ \n]*)";
        std::regex r(ss.str());

        std::smatch sm;
        std::regex_search(this->rawInput, sm, r);
        if (sm.size() == 1) {
            return "";
        }
        return sm[1];
    }

    bool Passport::isValid() const {
        // Removed cid from required fields
        std::vector<std::string> requiredFields {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
        for (const std::string field: requiredFields) {
            if (this->extractVal(field) == "") {
                return false;
            }
        }

        return true;
    }

    bool Passport::isValidStrict() const {
        return this->isValid() &&
            validByr(this->extractVal("byr")) &&
            validIyr(this->extractVal("iyr")) &&
            validEyr(this->extractVal("eyr")) &&
            validHgt(this->extractVal("hgt")) &&
            validHcl(this->extractVal("hcl")) &&
            validEcl(this->extractVal("ecl")) &&
            validPid(this->extractVal("pid")) &&
            validCid(this->extractVal("cid"));
    }

    bool Passport::validByr(std::string sVal) {
        int iVal = std::stoi(sVal);
        return iVal >= 1920 && iVal <= 2002;
    }

    bool Passport::validIyr(std::string sVal) {
        int iVal = std::stoi(sVal);
        return iVal >= 2010 && iVal <= 2020;
    }

    bool Passport::validEyr(std::string sVal) {
        int iVal = std::stoi(sVal);
        return iVal >= 2020 && iVal <= 2030;
    }

    bool Passport::validHgt(std::string sVal) {
        std::regex r("([0-9]*)(.*)");
        std::smatch sm;
        std::regex_search(sVal, sm, r);

        if (sm.size() != 3) {
            return false;
        }

        int num = std::stoi(sm[1]);

        if (sm[2] == "cm") {
            return num >= 150 && num <= 193;
        }

        if (sm[2] == "in") {
            return num >= 59 && num <= 76;
        }

        // We should not be here
        return false;
    }

    bool Passport::validHcl(std::string sVal) {
        std::regex r("#[0-9a-f]{6}");
        return std::regex_match(sVal, r);
    }

    bool Passport::validEcl(std::string sVal) {
        std::vector<std::string> validEyeColors {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
        for (const std::string ec: validEyeColors) {
            if (sVal == ec) {
                return true;
            }
        }
        return false;
    }

    bool Passport::validPid(std::string sVal) {
        std::regex r("[0-9]{9}");
        return std::regex_match(sVal, r);
    }

    bool Passport::validCid(std::string sVal) {
        return true;
    }

    // cout << obj << "," << endl;
    std::ostream & operator << (std::ostream &out, const Passport &c)
    {
        return std::cout << c.rawInput;
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
