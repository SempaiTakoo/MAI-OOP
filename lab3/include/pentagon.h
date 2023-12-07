#pragma once

#include "figure.h"

class Pentagon : public Figure{
    friend std::ostream& operator << (std::ostream &os, const Pentagon& pentagon);
    friend std::istream& operator >> (std::istream& is, Pentagon& pentagon);
    Point leftUpAngle;
    Point rightUpAngle;
    Point leftDownAngle;
    Point rightDownAngle;
    Point upAngle;
public:
    Pentagon() = default;
    Pentagon(const Point& newUpAngle,
             const Point& newRightUpAngle,
             const Point& newRightDownAngle,
             const Point& newLeftDownAngle,
             const Point& newLeftUpAngle);
    ~Pentagon();
    virtual Point getCenter();
    virtual operator double();
    int operator==(const Pentagon& other) const;
    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other);
};
