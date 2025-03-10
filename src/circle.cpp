// Copyright 2022 UNN-CS
#include <cstdint>
#include <cmath>
#include "circle.h"

void Circle::setRadius(double tmp)
{
    radius = tmp;
    ference = 2 * 3.14159 * radius;
    area = 3.14159 * radius * radius;
}

void Circle::setFerence(double tmp)
{
    ference = tmp;
    radius = ference / (2 * 3.14159);
    area = 3.14159 * radius * radius;
}

void Circle::setArea(double tmp)
{
    area = tmp;
    radius = sqrt(area / 3.14159);
    ference = 2 * 3.14159 * radius;
}

double Circle::getRadius()
{
    return radius;
}

double Circle::getFerence()
{
    return ference;
}

double Circle::getArea()
{
    return area;
}
