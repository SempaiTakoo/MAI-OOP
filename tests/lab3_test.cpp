#include <gtest/gtest.h>

#include "pentagon.h"
#include "rhombus.h"
#include "trapezoid.h"

const double EPS = 0.0001;

TEST(trapezoidcenter, test_01) {
    Trapezoid trapezoid{Point{2, 3},
                        Point{5, 3},
                        Point{0, 0},
                        Point{7, 0}};
    ASSERT_EQ(trapezoid.getCenter(), Point(3.5, 1.5));
}

TEST(trapezoidcenter, test_02) {
    Trapezoid trapezoid{Point{0, 13},
                        Point{3, 13},
                        Point{-2, 10},
                        Point{5, 10}};
    ASSERT_EQ(trapezoid.getCenter(), Point(1.5, 11.5));
}

TEST(trapezoidarea, test_01) {
    Trapezoid trapezoid{Point{2, 3},
                        Point{5, 3},
                        Point{0, 0},
                        Point{7, 0}};
    ASSERT_EQ(double(trapezoid), 15);
}

TEST(trapezoidarea, test_02) {
    Trapezoid trapezoid{Point{0, 13},
                        Point{3, 13},
                        Point{-2, 10},
                        Point{5, 10}};
    ASSERT_EQ(double(trapezoid), 15);
}

TEST(rhombus_center, test_01) {
    Rhombus rhombus{Point{4, 3},
                    Point{7, 0},
                    Point{4, -3},
                    Point{1, 0}};
    ASSERT_EQ(rhombus.getCenter(), Point(4, 0));
}

TEST(rhombus_center, test_02) {
    Rhombus rhombus{Point{4, 4},
                    Point{8, 0},
                    Point{4, -4},
                    Point{0, 0}};
    ASSERT_EQ(rhombus.getCenter(), Point(4, 0));
}

TEST(rhombus_area, test_01) {
    Rhombus rhombus{Point{4, 4},
                    Point{8, 0},
                    Point{4, -4},
                    Point{0, 0}};
    ASSERT_EQ(double(rhombus), 32);
}

TEST(rhombus_area, test_02) {
    Rhombus rhombus{Point{4, 3},
                    Point{7, 0},
                    Point{4, -3},
                    Point{1, 0}};
    ASSERT_EQ(double(rhombus), 18);
}

TEST(pentagon_center, test_01) {
    Pentagon pentagon{Point{1, 0},
                      Point{0.3090, 0.9511},
                      Point{-0.8090, 0.5878},
                      Point{-0.8090, -0.5878},
                      Point{0.3090, -0.9511}};
    Point cent = pentagon.getCenter();
    ASSERT_TRUE((fabs(cent.getX() - 1) < EPS)
                and (fabs(cent.getY() + 1) < EPS));
}

TEST(pentagon_area, test_01) {
    Pentagon pentagon{Point{1, 0},
                      Point{0.3090, 0.9511},
                      Point{-0.8090, 0.5878},
                      Point{-0.8090, -0.5878},
                      Point{0.3090, -0.9511}};
    double s = double(pentagon);
    ASSERT_TRUE(s - 2.37784 < EPS);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
