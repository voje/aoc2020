#include <iostream>
#include <vector>
#include <exception>

#include "map.hpp"

namespace aoc2020
{

    Map::Map(const std::vector<std::string> &svec)
    {
        if (svec.size() == 0) {
            throw std::length_error("Trying to create a zero-length map");
        }

        this->height = svec.size();
        this->width = svec[0].size();

        this->rows = new char*[this->height];
        for (size_t y = 0; y < this->height; y++) {
            this->rows[y] = new char[this->width];
            for (size_t x = 0; x < this->width; x++) {
                this->Set(x, y, svec[y][x]);
            }
        }
    }

    char Map::Get(uint32_t x, uint32_t y) const
    {
        return this->rows[this->wrapY(y)][this->wrapX(x)];
    }

    void Map::Set(uint32_t x, uint32_t y, char ch)
    {
        this->rows[this->wrapY(y)][this->wrapX(x)] = ch;
    }

    std::ostream& operator<<(std::ostream& ost, const Map& obj)
    {
        std::cout << "height: " << obj.height << std::endl;
        std::cout << "width : " << obj.width << std::endl;
        for (size_t y = 0; y < obj.height; y++) {
            for (size_t x = 0; x < obj.width; x++) {
                std::cout << obj.Get(x, y);
            }
            std::cout << std::endl;
        }
        return ost;
    }             

    struct tobogan {
        const uint32_t xSpeed = 3;
        const uint32_t ySpeed = 1;

        uint32_t xPos = 0;
        uint32_t yPos = 0;

    };

    uint32_t Map::Traverse(uint32_t xSpeed, uint32_t ySpeed)
    {
        uint32_t treeCount = 0;

        tobogan toby {
            xSpeed: xSpeed,
            ySpeed: ySpeed,
            xPos: 0,
            yPos: 0,
        };

        while (toby.yPos < this->height) {
            if (this->Get(toby.xPos, toby.yPos) == '#') {
                // this->Set(toby.xPos, toby.yPos, 'X');
                treeCount++;
            } else {
                // this->Set(toby.xPos, toby.yPos, 'O');
            }

            // Move toby
            toby.xPos += toby.xSpeed;
            toby.yPos += toby.ySpeed;
        }
        return treeCount;
    }


}
