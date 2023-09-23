#include <gtest/gtest.h>

#include "task.h"

TEST(TestTask, Zero) {
    std::string s = "00000000000000000000000000000000";
    ASSERT_EQ(IntToBinaryString(0ULL), s);
}

TEST(TestTask, Number1) {
    std::string s = "00000000000000000000000000000001";
    ASSERT_EQ(IntToBinaryString(1ULL), s);
}

TEST(TestTask, Number7) {
    std::string s = "00000000000000000000000000000111";
    ASSERT_EQ(IntToBinaryString(7ULL), s);
}

TEST(TestTask, Number13) {
    std::string s = "00000000000000000000000000001101";
    ASSERT_EQ(IntToBinaryString(13ULL), s);
}

TEST(TestTask, MaxValue) {
    std::string s = "11111111111111111111111111111111";
    ASSERT_EQ(IntToBinaryString(4294967295ULL), s);
}

TEST(TestTask, TooBigNumber) {
    ASSERT_EQ(IntToBinaryString(4294967296ULL), "Error: too big number");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}