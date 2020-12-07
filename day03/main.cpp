#include <iostream>
#include <numeric>

#include "map.hpp"
#include "readinput.hpp"

using namespace aoc2020;
using namespace std;

int main()
{
    vector<string> input;
    input = Input::Read("../input.txt");

    Map m(input);

    vector<uint32_t> res;

    res.push_back(m.Traverse(1, 1));
    cout << "1, 1: " << res.back() << endl;

    res.push_back(m.Traverse(3, 1));
    cout << "3, 1: " << res.back() << endl;

    res.push_back(m.Traverse(5, 1));
    cout << "5, 1: " << res.back() << endl;

    res.push_back(m.Traverse(7, 1));
    cout << "7, 1: " << res.back() << endl;

    res.push_back(m.Traverse(1, 2));
    cout << "1,2: " << res.back() << endl;

    double mul = 1;
    for (const uint32_t r: res) {
        mul *= r;
    }
    cout << "mul: " << to_string(mul) << endl;

    return 0;
}
