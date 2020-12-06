#include <iostream>

#include "map.hpp"
#include "readinput.hpp"

using namespace aoc2020;
using namespace std;

int main()
{
    vector<string> input;
    input = Input::Read("../input.txt");

    Map m(input[0].size(), input.size());

    for (size_t y = 0; y < input.size(); y++) {
        for (size_t x = 0; x < input.size(); x++) {
            m.Set(x, y, input[y][x]);
        }
    }

    uint32_t treeCount = m.Traverse();

    cout << "We hit this many trees: " << treeCount << endl;

    return 0;
}
