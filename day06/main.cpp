#include "aoc/customs.hpp"
#include <fstream>
#include <exception>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <random>
#include <chrono>

using namespace aoc2020;

std::mt19937_64 eng{std::random_device{}()};
std::uniform_int_distribution<> dist{1, 2};

std::mutex mutex;
int sumParallel;

void getDeclCount(const Customs &c) {
    int sleep = dist(eng);
    // std::cout << "Sleeping for: " << sleep << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds{sleep});
    std::lock_guard<std::mutex> myLock(mutex);
    sumParallel += c.countDecls();
}

int main() {
    std::vector<Customs> cust;
    std::ifstream inFile("../input.txt");

    int sumNormal = 0;
    int sumMutual = 0;

    try {

        inFile.exceptions(std::ifstream::failbit);
        while (true) {
            Customs cc = Customs();
            inFile >> cc;

            if (cc.countDecls() == 0) {
                break;
            }
            std::cout << "---" << std::endl;
            std::cout << cc << std::endl;
            int cDecls = cc.countDecls();
            std::cout << cDecls << std::endl;
            sumNormal += cDecls;
            sumMutual += cc.countMutualDecls();
            cust.push_back(cc);
        }
    } catch (std::ios_base::failure& fail) {
        if(!inFile.eof()) {
            std::cout << "Failed to read from file." << std::endl;
            std::cout << fail.what() << std::endl;
        }
    }

    std::cout << "Stored " << cust.size() << " customs records." << std::endl;
    std::cout << "SumNormal:" << sumNormal << std::endl;
    std::cout << "SumMutual:" << sumMutual << std::endl;

    // Calculate everything in parallel.   
    for (const Customs &cc: cust) {
        std::thread thread_obj(getDeclCount, cc);
        thread_obj.join();
    }

    std::cout << "Sum: " << sumParallel << std::endl;
}