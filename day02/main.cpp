#include <iostream>
#include <vector>
#include <string>
#include "readinput.hpp"

using namespace aoc2020;
using namespace std;

int main ()
{
    vector<string> input; 
    input = Input::Read("../input.txt");

    for (auto el: input)
    {
        cout << el << endl;
    }
}
