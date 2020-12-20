#include "customs.hpp"

namespace aoc2020
{
    Customs::Customs()
    {};

    int Customs::countDecls() const {
        std::map<char, bool> decls;
        for (const char ch: this->rawInput) {
            // Only accept ascii
            if (ch >= 'a' && ch <= 'z') {
                decls[ch] = true; 
            }
        }
        return decls.size();
    }

    int Customs::countMutualDecls() const {
        // A declaration is mutual if the number of affirmations is equal to the
        // number of participants.   
        std::map<char, int> decls;
        int nParticipants = 1;

        for (const char ch: this->rawInput) {
            // Only accept ascii
            if (ch == ' ') {
                nParticipants++;
            }
            if (ch >= 'a' && ch <= 'z') {
                if (decls.find(ch) == decls.end()) {
                    decls[ch] = 0;
                }
                decls[ch]++;
            }
        }
        int mutual = 0;
        for (const auto &dcl: decls) {
            if (std::get<1>(dcl) == nParticipants) {
                mutual++;
            }
        }
        return mutual;
    }

    std::ostream & operator << (std::ostream &out, const Customs &c)
    {
        std::cout << c.rawInput;
    }

    std::istream & operator >> (std::istream &in, Customs &c)
    {
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