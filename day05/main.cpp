#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "readinput.hpp"
#include "binary.hpp"

using namespace aoc2020;
using namespace std;

int main()
{
    vector<string> input;
    input = Input::Read("../input.txt");

    vector<int> ids;

    int max = 0;
    for (const string &inp: input) {
        int id = GetID(inp);
        ids.push_back(id);
        if (id > max) {
            max = id;
        }
    }

    cout << "Max ID: " << max << endl;

    sort(ids.begin(), ids.end());
    for (int i = 1; i < ids.size() - 1; i++) {
        if ((ids[i - 1] != ids[i] - 1) || (ids[i + 1] != ids[i] + 1)) {
            cout << ids[i] << endl;
        }
    }

    return 0;
}
