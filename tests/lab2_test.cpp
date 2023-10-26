#include <gtest/gtest.h>
#include <string>
#include "money.h"

TEST(TestConstructors, FillConstructorTest) {
    Money num1("111");
    Money num2(3, '1');
    ASSERT_EQ(num1, num2);
}

TEST(TestConstructors, InitializerListConstructorTest) {
    Money num1("001");
    Money num2({'0', '0', '1'});
    ASSERT_TRUE(num1 == num2);
    ASSERT_EQ(num1, num2);
}

TEST(TestConstructors, CopyStringConstructorTest) {
    Money money1("001");
    std::string str_001 = "001";
    Money money2(str_001);
    ASSERT_EQ(money1, money2);
}

TEST(TestConstructors, CopyConstructorTest) {
    Money money1("001");
    Money money2(money1);
    ASSERT_EQ(money1, money2);
}

TEST(TestConstructors, MoveConstructorTest) {
    Money money1("001");
    Money money2 = money1;
    ASSERT_EQ(money1, money2);
}


TEST(TestOperators, AssignmentTest) {
    Money money1("001");
    Money money2 = money1;
    ASSERT_EQ(money1, money2);
}

TEST(TestOperators, AddittionTest) {
    Money money1("001");
    Money money2("001");
    ASSERT_TRUE((money1 + money2) == Money("002"));
}

TEST(TestOperators, SubstractionTest) {
    Money money1("002");
    Money money2("001");
    ASSERT_TRUE((money1 - money2) == Money("001"));
}

TEST(TestOperators, EqTest1) {
    Money money1("001");
    Money money2("001");
    ASSERT_TRUE(money1 == money2);
}

TEST(TestOperators, EqTest2) {
    Money money1("001");
    Money money2("002");
    ASSERT_FALSE(money1 == money2);
}

TEST(TestOperators, NotEqTest1) {
    Money money1("001");
    Money money2("001");
    ASSERT_FALSE(money1 != money2);
}

TEST(TestOperators, NotEqTest2) {
    Money money1("001");
    Money money2("002");
    ASSERT_TRUE(money1 != money2);
}

TEST(TestOperators, LessTest) {
    Money money1("001");
    Money money2("002");
    ASSERT_TRUE(money1 < money2);
}

TEST(TestOperators, MoreTest) {
    Money money1("001");
    Money money2("002");
    ASSERT_TRUE(money2 > money1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
