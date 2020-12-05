#define GENERATE_UNIT_TEST_MAIN
#include "CppUnitTestFramework.hpp"

struct MyFixture {
    constexpr int CommonData = 10;
};

TEST_CASE(MyFixture, Test1) {
    // MyFixture constructor called
    CHECK_EQUAL(CommonData, 10);
    // MyFixture destructor called
}
TEST_CASE(MyFixture, Test2) {
    // MyFixture constructor called
    CHECK_EQUAL(CommonData, 10);
    // MyFixture destructor called
}