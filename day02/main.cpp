#include <iostream>
#include <vector>
#include <string>
#include "readinput.hpp"
#include "pwrecord.hpp"

using namespace aoc2020;
using namespace std;

int main ()
{
    vector<string> input; 
    input = Input::Read("../input.txt");

    int nValid = 0;
    int nValidInSecondJob = 0;

    for (auto el: input)
    {
        PwRecord rec (el);
        if (rec.IsValid()) {
            nValid++;
        }
        if (rec.IsValidInSecondJob()) {
            nValidInSecondJob++;
        }
    }

    cout << "--------------------" << endl;
    cout << "N of all records: " << input.size() << endl;
    cout << "N of valid records: " << nValid << endl;
    cout << "N of valid records in second job: " << nValidInSecondJob << endl;
    cout << "--------------------" << endl;
}
