#include <gtest/gtest.h>
#include "delete_duplicates.h"

TEST(DeleteDuplicatesTest, BasicTest) {
    vector<int> input = { 4, 65, 44, 4, 1, 8, 5, 1 };
    vector<int> result = deleteDuplicates(input);
    vector<int> expected = { 4, 65, 44, 1, 8, 5 };
    EXPECT_EQ(result, expected);
}

TEST(DeleteDuplicatesTest, EmptyVector) {
    vector<int> input = {};
    vector<int> result = deleteDuplicates(input);
    vector<int> expected = {};
    EXPECT_EQ(result, expected);
}

TEST(DeleteDuplicatesTest, NoDuplicates) {
    vector<int> input = { 1, 2, 3 };
    vector<int> result = deleteDuplicates(input);
    vector<int> expected = { 1, 2, 3 };
    EXPECT_EQ(result, expected);
}

TEST(DeleteDuplicatesTest, AllDuplicates) {
    vector<int> input = { 5, 5, 5, 5 };
    vector<int> result = deleteDuplicates(input);
    vector<int> expected = { 5 };
    EXPECT_EQ(result, expected);
}