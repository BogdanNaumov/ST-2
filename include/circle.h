// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>

const double PI = 3.141592653589793238462;

class Circle
{
private:
    double radius;
    double ference;
    double area;

public:
    void setRadius(double tmp);
    void setFerence(double tmp);
    void setArea(double tmp);
    double getRadius();
    double getFerence();
    double getArea();
}

#endif // INCLUDE_CIRCLE_H_
