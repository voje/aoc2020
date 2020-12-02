#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int targetVal = 2020;

int findTwo(vector<int> &vec) {
    // two for-loops, find the sum
    int sum = 0;
    for (std::vector<int>::iterator it = vec.begin() ; it != vec.end(); ++it)
    {
        for (std::vector<int>::iterator it1 = it + 1; it1 != vec.end(); ++it1)
        {
            if (*it + *it1 == targetVal) {
                return *it * *it1;
            }
        }
    }
}

int findThree(vector<int> &vec) {
    // three for-loops, find the sum
    for (std::vector<int>::iterator it = vec.begin() ; it != vec.end(); ++it)
    {
        for (std::vector<int>::iterator it1 = it + 1; it1 != vec.end(); ++it1)
        {
            for (std::vector<int>::iterator it2 = it1 + 1; it2 != vec.end(); ++it2) {
                {
                    if (*it + *it1 + *it2 == 2020) {
                        return *it * *it1 * *it2;
                    }
                }
            }
        }
    }
}

int main() {
    // read input.txt into a vector
    string line;
    vector<int> lines;
    ifstream inputFile("input.txt");

    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            int tmp = stoi(line);
            lines.push_back(tmp);
        }     
    }

    cout << "2: " << findTwo(lines) << endl;
    cout << "3: " << findThree(lines) << endl;

    return 0;
}