#include <gtest/gtest.h>
#include "fact.h"

TEST(FactorialTest, PositiveNumbers) {
    vector<int> result = fact(5);
    vector<int> expected = { 1, 2, 6, 24, 120 };
    EXPECT_EQ(result, expected);
}

TEST(FactorialTest, Zero) {
    vector<int> result = fact(0);
    vector<int> expected = {};
    EXPECT_EQ(result, expected);
}

TEST(FactorialTest, One) {
    vector<int> result = fact(1);
    vector<int> expected = { 1 };
    EXPECT_EQ(result, expected);
}

TEST(FactorialTest, LargeNumber) {
    vector<int> result = fact(6);
    vector<int> expected = { 1, 2, 6, 24, 120, 720 };
    EXPECT_EQ(result, expected);
}

void testFactorial() {}