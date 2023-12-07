#include "pentagon.h"

Pentagon::Pentagon(const Point& newUpAngle,
                   const Point& newRightUpAngle,
                   const Point& newRightDownAngle,
                   const Point& newLeftDownAngle,
                   const Point& newLeftUpAngle)
    : leftUpAngle(newLeftUpAngle),
      leftDownAngle(newLeftDownAngle),
      rightDownAngle(newRightDownAngle),
      rightUpAngle(newRightUpAngle),
      upAngle(newUpAngle) {}

Pentagon::~Pentagon() {}

Point Pentagon::getCenter() {
    double a = sqrt(
        (upAngle.getX() - leftUpAngle.getX())
        * (upAngle.getX() - leftUpAngle.getX())
        + (upAngle.getY() - leftUpAngle.getY())
        * (upAngle.getY() - leftUpAngle.getY())
    );
    double R = a / (2 * sin(M_PI / 5));
    return Point{upAngle.getX(), (upAngle.getY() - R)};
}

std::ostream& operator<<(std::ostream& os, const Pentagon& pentagon) {
    return os << pentagon.leftDownAngle << ' ' << pentagon.leftUpAngle << ' '
              << pentagon.rightDownAngle << ' ' << pentagon.rightUpAngle << ' '
              << pentagon.upAngle;
}

std::istream& operator>>(std::istream& is, Pentagon& pentagon) {
    is >> pentagon.leftDownAngle >> pentagon.leftUpAngle
       >> pentagon.rightDownAngle >> pentagon.rightUpAngle
       >> pentagon.upAngle;
    return is;
}

Pentagon::operator double() {
    double a = sqrt(
        (upAngle.getX() - leftUpAngle.getX())
        * (upAngle.getX() - leftUpAngle.getX())
        + (upAngle.getY() - leftUpAngle.getY())
        * (upAngle.getY() - leftUpAngle.getY())
    );
    double s = 5 * a * a / (tan(M_PI / 5) * 4);
    return s;
}

int Pentagon::operator==(const Pentagon& other) const {
    if ((leftUpAngle == other.leftUpAngle)
        and (rightUpAngle == other.rightUpAngle)
        and (leftDownAngle == other.leftDownAngle)
        and (rightDownAngle == other.rightDownAngle)
        and (upAngle == other.upAngle)) {
        return 1;
    }
    return 0;
}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (!(this == &other)) {
        leftUpAngle = other.leftUpAngle;
        rightUpAngle = other.rightUpAngle;
        leftDownAngle = other.leftDownAngle;
        rightDownAngle = other.rightDownAngle;
        upAngle = other.upAngle;
    }
    return *this;
}

Pentagon& Pentagon::operator=(Pentagon&& other) {
    if (!(this == &other)) {
        leftUpAngle = other.leftUpAngle;
        leftDownAngle = other.leftDownAngle;
        rightDownAngle = other.rightDownAngle;
        rightUpAngle = other.rightUpAngle;
        upAngle = other.upAngle;
        other.leftDownAngle = Point(0.0, 0.0);
        other.leftUpAngle = Point(0.0, 0.0);
        other.rightDownAngle = Point(0.0, 0.0);
        other.rightUpAngle = Point(0.0, 0.0);
        upAngle = Point(0.0, 0.0);
    }
    return *this;
}
