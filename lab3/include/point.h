#pragma once

#include <cmath>
#include <iostream>
#include <string>

class Point {
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    friend std::istream& operator>>(std::istream& is, Point& point);
    double x;
    double y;

   public:
    Point() = default;
    Point(double newX, double newY);
    Point(const Point& other);
    ~Point();
    double getX();
    double getY();
    int operator==(const Point& other) const;
    Point& operator=(const Point& other);
};
