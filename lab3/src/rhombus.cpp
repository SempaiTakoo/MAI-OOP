#include "rhombus.h"

Rhombus::Rhombus(const Point& newUpAngle,
                 const Point& newRightAngle,
                 const Point& newDownAngle,
                 const Point& newLeftAngle)
    : upAngle(newUpAngle),
      rightAngle(newRightAngle),
      leftAngle(newLeftAngle),
      downAngle(newDownAngle) {}

Rhombus::~Rhombus() {}

Point Rhombus::getCenter() {
    double x = upAngle.getX();
    double y = leftAngle.getY();
    return Point{x, y};
}

Rhombus::operator double() {
    double diag1 = upAngle.getY() - downAngle.getY();
    double diag2 = rightAngle.getX() - leftAngle.getX();
    return diag1 * diag2 / 2;
}

std::ostream& operator<<(std::ostream& os, const Rhombus& rhombus) {
    os << rhombus.downAngle << ' ' << rhombus.leftAngle << ' '
       << rhombus.rightAngle << ' ' << rhombus.upAngle;
    return os;
}

std::istream& operator>>(std::istream& is, Rhombus& rhombus) {
    is >> rhombus.downAngle >> rhombus.leftAngle
       >> rhombus.rightAngle >> rhombus.upAngle;
    return is;
}

int Rhombus::operator==(const Rhombus& other) const {
    if ((upAngle == other.upAngle)
        and (rightAngle == other.rightAngle)
        and (leftAngle == other.leftAngle)
        and (downAngle == other.downAngle)) {
        return 1;
    }
    return 0;
}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (!(this == &other)) {
        upAngle = other.upAngle;
        rightAngle = other.rightAngle;
        leftAngle = other.leftAngle;
        downAngle = other.downAngle;
    }
    return *this;
}

Rhombus& Rhombus::operator=(Rhombus&& other) {
    if (!(this == &other)) {
        upAngle = other.upAngle;
        rightAngle = other.rightAngle;
        leftAngle = other.leftAngle;
        downAngle = other.downAngle;
        other.leftAngle = Point(0.0, 0.0);
        other.upAngle = Point(0.0, 0.0);
        other.downAngle = Point(0.0, 0.0);
        other.rightAngle = Point(0.0, 0.0);
    }
    return *this;
}
