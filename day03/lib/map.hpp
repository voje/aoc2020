#pragma once

#include <cstdint>
#include <stdexcept>
#include <vector>

namespace aoc2020 {

    class Map
    {
    public:
        uint32_t width;
        uint32_t height;
        char** rows;

        Map(const std::vector<std::string> &svec);
        ~Map();

        void Set(uint32_t x, uint32_t y, char);
        char Get(uint32_t x, uint32_t y) const;

        // Traverse the map, according to aoc puzzle 03, part one.
        uint32_t Traverse();

        friend std::ostream& operator<<(std::ostream&, const Map&);
    
    private:
        uint32_t wrapX(uint32_t x) const
        {
            return x % this->width;
        }

        uint32_t wrapY(uint32_t y) const
        {
            return y % this->height;
        }

    };

}