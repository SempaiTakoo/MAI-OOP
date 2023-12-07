#include "point.h"

Point::Point(double newX, double newY) : x(newX), y(newY) {}

Point::~Point() {}

Point::Point(const Point& other) {
    x = other.x;
    y = other.y;
}

double Point::getX() { return x; }

double Point::getY() { return y; }

std::ostream& operator<<(std::ostream& os, const Point& point) {
    return os << point.x << ' ' << point.y;
}

std::istream& operator>>(std::istream& is, Point& point) {
    is >> point.x;
    is >> point.y;
    return is;
}

int Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

Point& Point::operator=(const Point& other) {
    x = other.x;
    y = other.y;
    return *this;
}
