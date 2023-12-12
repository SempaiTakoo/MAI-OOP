#include <gtest/gtest.h>

#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"
#include "list.h"

const double EPS = 0.0001;

TEST(trapezoid_center, test_01){
    Trapezoid<int> trapezoid{Point{2, 3},
                             Point{5, 3},
                             Point{0, 0},
                             Point{7, 0}};
    ASSERT_EQ(trapezoid.getCenter(), Point<int>(3.5, 1.5));
}

TEST(trapezoid_center, test_02){
    Trapezoid<int> trapezoid{Point{0, 13},
                             Point{3, 13},
                             Point{-2, 10},
                             Point{5, 10}};
    ASSERT_EQ(trapezoid.getCenter(), Point<int>(1.5, 11.5));
}

TEST(trapezoid_center, test_03){
    Trapezoid<int> trapezoid{Point{1, 4},
                             Point{6, 4},
                             Point{-1, -1},
                             Point{8, -1}};
    ASSERT_EQ(trapezoid.getCenter(), Point<int>(3.5, 1.5));
}

TEST(trapezoid_area, test_01){
    Trapezoid<int> trapezoid{Point{2, 3},
                             Point{5, 3},
                             Point{0, 0},
                             Point{7, 0}};
    ASSERT_EQ(double(trapezoid), 15);
}

TEST(trapezoid_area, test_02){
    Trapezoid<int> trapezoid{Point{0, 13},
                             Point{3, 13},
                             Point{-2, 10},
                             Point{5, 10}};
    ASSERT_EQ(double(trapezoid), 15);
}

TEST(rhombus_center, test_01){
    Rhombus<int> rhombus{Point{4, 3},
                         Point{7, 0},
                         Point{4, -3},
                         Point{1, 0}};
    ASSERT_EQ(rhombus.getCenter(), Point(4, 0));
}

TEST(rhombus_center, test_02){
    Rhombus<int> rhombus{Point{4, 4},
                         Point{8, 0},
                         Point{4, -4},
                         Point{0, 0}};
    ASSERT_EQ(rhombus.getCenter(), Point(4, 0));
}

TEST(rhombus_center, test_03){
    Rhombus<double> rhombus{Point<double>{-1.5, 100},
                            Point<double>{-24.1, 95},
                            Point<double>{-1.5, 90},
                            Point<double>{21.1, 95}};
    ASSERT_EQ(rhombus.getCenter(), Point<double>(-1.5, 95));
}

TEST(rhombus_area, test_01){
    Rhombus<int> rhombus{Point{4, 4},
                         Point{8, 0},
                         Point{4, -4},
                         Point{0, 0}};
    ASSERT_EQ(double(rhombus), 32);
}

TEST(rhombus_area, test_02){
    Rhombus<int> rhombus{Point{4, 3},
                         Point{7, 0},
                         Point{4, -3},
                         Point{1, 0}};
    ASSERT_EQ(double(rhombus), 18);
}

TEST(pentagon_center, test_01){
    Pentagon<double> pentagon{Point<double>{1, 0},
                              Point<double>{0.3090, 0.9511},
                              Point<double>{-0.8090, 0.5878},
                              Point<double>{-0.8090, -0.5878},
                              Point<double>{0.3090, -0.9511}};
    Point<double> cent = pentagon.getCenter();
    ASSERT_TRUE((fabs(cent.getX() - 1) < EPS) and (fabs(cent.getY() + 1) < EPS));
}

TEST(pentagon_area, test_01){
    Pentagon<double> pentagon{Point<double>{1, 0},
                              Point<double>{0.3090, 0.9511},
                              Point<double>{-0.8090, 0.5878},
                              Point<double>{-0.8090, -0.5878},
                              Point<double>{0.3090, -0.9511}};
    double s = double(pentagon);
    ASSERT_TRUE(s - 2.37784 < EPS);
}

TEST(array_get_total_area, test01) {
    Trapezoid<double> trapezoid{Point<double>{0, 13},
                                Point<double>{3, 13},
                                Point<double>{-2, 10},
                                Point<double>{5, 10}};
    Rhombus<double> rhombus{Point<double>{4, 3},
                            Point<double>{7, 0},
                            Point<double>{4, -3},
                            Point<double>{1, 0}};
    Pentagon<double> pentagon{Point<double>{1, 0},
                              Point<double>{0.3090, 0.9511},
                              Point<double>{-0.8090, 0.5878},
                              Point<double>{-0.8090, -0.5878},
                              Point<double>{0.3090, -0.9511}};
    ListFigure<std::shared_ptr<Figure<double>>, double> list = {
        std::make_shared<Trapezoid<double>>(trapezoid),
        std::make_shared<Rhombus<double>>(rhombus),
        std::make_shared<Pentagon<double>>(pentagon)
    };
    ASSERT_TRUE((double(list) - ((double) trapezoid + (double) rhombus + (double) pentagon)) <= EPS);
}

TEST(array_get_total_area, test02) {
    Rhombus<int> rhombus1{Point{4, 3},
                          Point{7, 0},
                          Point{4, -3},
                          Point{1, 0}};
    Rhombus<int> rhombus2{Point{4, 3},
                          Point{7, 0},
                          Point{4, -3},
                          Point{1, 0}};
    Rhombus<int> rhombus3{Point{4, 4},
                          Point{8, 0},
                          Point{4, -4},
                          Point{0, 0}};
    ListFigure<std::shared_ptr<Figure<int>>, int> list = {
        std::make_shared<Rhombus<int>>(rhombus1),
        std::make_shared<Rhombus<int>>(rhombus2),
        std::make_shared<Rhombus<int>>(rhombus3)
    };
    ASSERT_TRUE((double(list) - ((double) rhombus1 + (double) rhombus2 + (double) rhombus3)) <= EPS);
}

TEST(array_remove, test01) {
    Trapezoid<double> trapezoid{Point<double>{0, 13},
                                Point<double>{3, 13},
                                Point<double>{-2, 10},
                                Point<double>{5, 10}};
    Rhombus<double> rhombus{Point<double>{4, 3},
                            Point<double>{7, 0},
                            Point<double>{4, -3},
                            Point<double>{1, 0}};
    Pentagon<double> pentagon{Point<double>{1, 0},
                              Point<double>{0.3090, 0.9511},
                              Point<double>{-0.8090, 0.5878},
                              Point<double>{-0.8090, -0.5878},
                              Point<double>{0.3090, -0.9511}};
    ListFigure<std::shared_ptr<Figure<double>>, double> list = {
        std::make_shared<Trapezoid<double>>(trapezoid),
        std::make_shared<Rhombus<double>>(rhombus),
        std::make_shared<Pentagon<double>>(pentagon)
    };
    list.deleteFigure(0);
    ASSERT_TRUE((double(list) - ((double) rhombus + (double) pentagon)) <= EPS);
}

TEST(array_remove, test02) {
    Trapezoid<double> trapezoid{Point<double>{0, 13},
                                Point<double>{3, 13},
                                Point<double>{-2, 10},
                                Point<double>{5, 10}};
    Rhombus<double> rhombus{Point<double>{4, 3},
                            Point<double>{7, 0},
                            Point<double>{4, -3},
                            Point<double>{1, 0}};
    Pentagon<double> pentagon{Point<double>{1, 0},
                              Point<double>{0.3090, 0.9511},
                              Point<double>{-0.8090, 0.5878},
                              Point<double>{-0.8090, -0.5878},
                              Point<double>{0.3090, -0.9511}};
    ListFigure<std::shared_ptr<Figure<double>>, double> list = {
        std::make_shared<Trapezoid<double>>(trapezoid),
        std::make_shared<Rhombus<double>>(rhombus),
        std::make_shared<Pentagon<double>>(pentagon)
    };
    list.deleteFigure(0);
    list.deleteFigure(0);
    ASSERT_TRUE((double(list) - (double) pentagon) <= EPS);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
