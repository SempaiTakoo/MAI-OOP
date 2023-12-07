#include "trapezoid.h"

Trapezoid::Trapezoid(const Point& newLeftUpAngle,
                     const Point& newRightUpAngle,
                     const Point& newLeftDownAngle,
                     const Point& newRightDownAngle)
    : leftUpAngle(newLeftUpAngle),
      leftDownAngle(newLeftDownAngle),
      rightDownAngle(newRightDownAngle),
      rightUpAngle(newRightUpAngle) {}

Trapezoid::~Trapezoid() {}

Point Trapezoid::getCenter() {
    double xCenter = (rightUpAngle.getX() + leftUpAngle.getX()) / 2;
    double yCenter = (rightUpAngle.getY() + rightDownAngle.getY()) / 2;
    Point center{xCenter, yCenter};
    return center;
}

std::ostream& operator<<(std::ostream& os, const Trapezoid& trapezoid) {
    return os << trapezoid.leftDownAngle << ' ' << trapezoid.leftUpAngle << ' '
              << trapezoid.rightDownAngle << ' ' << trapezoid.rightUpAngle;
}

std::istream& operator>>(std::istream& is, Trapezoid& trapezoid) {
    is >> trapezoid.leftDownAngle >> trapezoid.leftUpAngle
       >> trapezoid.rightDownAngle >> trapezoid.rightUpAngle;
    return is;
}

Trapezoid::operator double() {
    double h = leftUpAngle.getY() - leftDownAngle.getY();
    double a = rightUpAngle.getX() - leftUpAngle.getX();
    double b = rightDownAngle.getX() - leftDownAngle.getX();
    return h * (a + b) / 2;
}

int Trapezoid::operator==(const Trapezoid& other) const {
    if ((leftUpAngle == other.leftUpAngle)
        and (rightUpAngle == other.rightUpAngle)
        and (leftDownAngle == other.leftDownAngle)
        and (rightDownAngle == other.rightDownAngle)) {
        return 1;
    }
    return 0;
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (!(this == &other)) {
        leftUpAngle = other.leftUpAngle;
        rightUpAngle = other.rightUpAngle;
        leftDownAngle = other.leftDownAngle;
        rightDownAngle = other.rightDownAngle;
    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) {
    if (!(this == &other)) {
        leftUpAngle = other.leftUpAngle;
        leftDownAngle = other.leftDownAngle;
        rightDownAngle = other.rightDownAngle;
        rightUpAngle = other.rightUpAngle;
        other.leftDownAngle = Point(0.0, 0.0);
        other.leftUpAngle = Point(0.0, 0.0);
        other.rightDownAngle = Point(0.0, 0.0);
        other.rightUpAngle = Point(0.0, 0.0);
    }
    return *this;
}
