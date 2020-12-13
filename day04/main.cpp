#include <fstream>
#include <iostream>
#include <vector>

#include "passport.hpp"

using namespace aoc2020;

int main()
{
    std::fstream input;
    input.open("../input.txt");

    int validCount = 0;
    int strictValidCount = 0;

    while (true) {
        Passport pp = Passport();
        input >> pp;

        if (pp.rawInput.size() == 0) {
            break;
        }

        // passports.push_back(pp);
        if (pp.isValid()) {
            validCount++;
        }
        if (pp.isValidStrict()) {
            strictValidCount++;
        }
    }

    std::cout << "Valid passports: " << validCount << std::endl;
    std::cout << "Strict valid passports: " << strictValidCount << std::endl;

}