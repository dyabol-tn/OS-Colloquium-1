#include <gtest/gtest.h>
#include "reverse_list.h"

void expectListEquals(MyList* head, const std::vector<int>& expected) {
    MyList* current = head;
    for (size_t i = 0; i < expected.size(); i++) {
        ASSERT_NE(current, nullptr) << "List is shorter than expected at position " << i;
        EXPECT_EQ(current->value, expected[i]);
        current = current->next;
    }
    EXPECT_EQ(current, nullptr) << "List is longer than expected";
}

TEST(ReverseListTest, BasicTest) {
    MyList* list = createList({ 1, 2, 3, 4, 5 });
    MyList* reversed = reverseList(list);

    std::vector<int> expected = { 5, 4, 3, 2, 1 };
    expectListEquals(reversed, expected);

    deleteList(reversed);
}

TEST(ReverseListTest, SingleElement) {
    MyList* list = createList({ 42 });
    MyList* reversed = reverseList(list);

    EXPECT_EQ(reversed->value, 42);
    EXPECT_EQ(reversed->next, nullptr);

    deleteList(reversed);
}

TEST(ReverseListTest, EmptyList) {
    MyList* list = nullptr;
    MyList* reversed = reverseList(list);

    EXPECT_EQ(reversed, nullptr);
}

TEST(ReverseListTest, TwoElements) {
    MyList* list = createList({ 1, 2 });
    MyList* reversed = reverseList(list);

    std::vector<int> expected = { 2, 1 };
    expectListEquals(reversed, expected);

    deleteList(reversed);
}

void testReverseList() {
}