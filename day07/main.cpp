#include <fstream>

#include "lib/bag.cpp"

int main() {

    std::ifstream ifs("../input.txt");

    int solution = solveDay07(ifs);
    std::cout << "We can reach the 'shiny gold' bag from " << solution << " different bags." << std::endl;

    ifs.clear();
    ifs.seekg(0, ifs.beg);

    int solutionPt2 = solveDay07Pt2(ifs);
    std::cout << "A shiny gold bag can contain a maximum of " << solutionPt2 << " bags." << std::endl;

    return 0;
}