#pragma once

#include "figure.h"

class Rhombus : public Figure {
    friend std::ostream& operator<<(std::ostream& os, const Rhombus& rhombus);
    friend std::istream& operator>>(std::istream& is, Rhombus& rhombus);
    Point upAngle;
    Point rightAngle;
    Point downAngle;
    Point leftAngle;

   public:
    Rhombus() = default;
    Rhombus(const Point& newUpAngle, const Point& newRightAngle,
            const Point& newDownAngle, const Point& newLeftAngle);
    ~Rhombus();
    virtual Point getCenter();
    virtual operator double();
    int operator==(const Rhombus& other) const;
    Rhombus& operator=(const Rhombus& other);
    Rhombus& operator=(Rhombus&& other);
};
