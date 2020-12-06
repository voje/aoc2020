#include <iostream>
#include "map.hpp"

namespace aoc2020
{

    Map::Map(uint32_t width, uint32_t height)
    {
        this->height = height;
        this->width = width;

        this->rows = new char*[this->height]();
        for (size_t y = 0; y < this->height; y++) {
            this->rows[y] = new char[this->width]();
            for (size_t x = 0; x < this->width; x++) {
                rows[y][x] = '.';
            }
        }
    }

    Map::~Map()
    {
        for (size_t i = 0; i < this->height; i++) {
            delete this->rows[i];
        }
        delete this->rows;
    }

    char Map::Get(uint32_t x, uint32_t y)
    {
        return this->rows[this->wrapX(x)][this->wrapY(y)];
    }

    void Map::Set(uint32_t x, uint32_t y, char ch)
    {
        this->rows[this->wrapX(x)][this->wrapY(y)] = ch;
    }

    std::ostream& operator<<(std::ostream& ost, const Map& obj)
    {
        std::cout << "height: " << obj.height << std::endl;
        std::cout << "width : " << obj.width << std::endl;
        for (size_t y = 0; y < obj.height; y++) {
            for (size_t x = 0; x < obj.width; x++) {
                std::cout << obj.rows[y][x];
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

    uint32_t Map::Traverse()
    {
        uint32_t treeCount = 0;

        tobogan toby;
        while (toby.yPos < this->height) {
            if (this->Get(toby.xPos, toby.yPos) == '#') {
                this->Set(toby.xPos, toby.yPos, 'X');
                treeCount++;
            } else {
                this->Set(toby.xPos, toby.yPos, 'O');
            }

            // Move toby
            toby.xPos += toby.xSpeed;
            toby.yPos += toby.ySpeed;
        }
        return treeCount;
    }


}
