#pragma once

#include <vector>
#include <map>
#include <iostream>
#include <string>

#include <fstream>
#include <exception>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <random>
#include <chrono>


namespace aoc2020
{
    class Customs
    {
    private:
        std::string rawInput;
        friend std::ostream & operator << (std::ostream &out, const Customs &c); 
        friend std::istream & operator >> (std::istream &in, Customs &c); 
    public:
        Customs();
        int countDecls() const;
        int countMutualDecls() const;
    };
}