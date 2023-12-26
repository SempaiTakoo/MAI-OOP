#include <gtest/gtest.h>

#include "allocator.h"
#include "iterator.h"
#include "const_iterator.h"
#include "stack.h"

TEST(MapTest, MapKey) {
    std::map<int, int, std::less<int>, allocators::Allocator<std::pair<const int, int>, 10>> my_map;

    for (int i = 0; i < 10; ++i) {
        my_map[i] = i + 10;
    }

    EXPECT_EQ(my_map.size(), 10);

    int i = 0;
    int j = 10;
    for (const auto& pair : my_map) {
        EXPECT_EQ(pair.first, i);
        EXPECT_EQ(pair.second, j);
        ++i;
        ++j;
    }
}

TEST(Iterator, DereferenceOperator) {
    Stack<int, allocators::Allocator<std::pair<const int,int>, 10>> my_stack;

    my_stack.push(10);

    auto it = my_stack.begin();

    EXPECT_EQ(*it, 10);
}

TEST(Iterator, ArrowOperator) {
    Stack<std::pair<const int, int>, allocators::Allocator<std::pair<const int, int>, 10>> my_stack;
    my_stack.push(std::make_pair(1, 2));

    auto it = my_stack.begin();
    EXPECT_EQ(it->first, 1);
    EXPECT_EQ(it->second, 2);
}

TEST(Iterator, IncrementOperator) {
    Stack<int, allocators::Allocator<std::pair<const int,int>, 10>> my_stack;

    my_stack.push(1);
    my_stack.push(2);

    auto it = my_stack.begin();

    EXPECT_EQ(*it, 2);

    ++it;

    EXPECT_EQ(*it, 1);
}

TEST(Iterator, Equality) {

    Stack<int, allocators::Allocator<std::pair<const int,int>, 10>> my_stack;
    my_stack.push(1);

    auto it1 = my_stack.begin();
    auto it2 = my_stack.begin();

    EXPECT_TRUE(it1 == it2);

    ++it2;

    EXPECT_FALSE(it1 == it2);
}

TEST(Iterator, Inequality) {

    Stack<int, allocators::Allocator<std::pair<const int,int>, 10>> my_stack;
    my_stack.push(1);

    auto it1 = my_stack.begin();
    auto it2 = my_stack.begin();

    EXPECT_FALSE(it1 != it2);
}

TEST(StackFunctional, StackPush) {
    Stack<int, allocators::Allocator<std::pair<const int,int>, 10>> my_stack;

    for (int i = 0; i < 10; ++i) {
        my_stack.push(i);
    }

    EXPECT_EQ(my_stack.length(), 10);

    int i = 9;
    for (const auto& value : my_stack) {
        EXPECT_EQ(value, i--);
    }
}

TEST(StackFunctional, ConstBeginAndConstEnd) {
    Stack<int, allocators::Allocator<std::pair<const int,int>, 10>> my_stack;

    const auto& constStack = my_stack;
    auto itBegin = constStack.cbegin();
    auto itEnd = constStack.cend();

    EXPECT_EQ(itBegin, itEnd);
    my_stack.push(1);
    my_stack.push(2);

    itBegin = constStack.cbegin();
    itEnd = constStack.cend();

    EXPECT_NE(itBegin, itEnd);
    EXPECT_EQ(*itBegin, 2);
}

TEST(StackFunctional, Pop) {
    Stack<int, allocators::Allocator<std::pair<const int,int>, 10>> my_stack;

    my_stack.push(1);
    my_stack.push(2);
    my_stack.pop();

    EXPECT_EQ(my_stack.length(), 1);
    EXPECT_EQ(my_stack.peak(), 1);
}

TEST(StackFunctional, LengthAndEmpty) {
    Stack<int, allocators::Allocator<std::pair<const int,int>, 10>> my_stack;

    EXPECT_TRUE(my_stack.empty());
    EXPECT_EQ(my_stack.length(), 0);

    my_stack.push(1);
    EXPECT_FALSE(my_stack.empty());
    EXPECT_EQ(my_stack.length(), 1);
}

TEST(StackFunctional, Clear) {
    Stack<int, allocators::Allocator<std::pair<const int,int>, 10>> my_stack;

    my_stack.push(1);
    my_stack.push(2);
    my_stack.clear();

    EXPECT_EQ(my_stack.length(), 0);
    EXPECT_TRUE(my_stack.empty());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
