#include <iostream>

#include "map.hpp"
#include "readinput.hpp"

using namespace aoc2020;
using namespace std;

int main()
{
    vector<string> input;
    input = Input::Read("../input.txt");

    Map m(input);

    uint32_t treeCount = m.Traverse();

    cout << "We hit this many trees: " << treeCount << endl;

    return 0;
}
