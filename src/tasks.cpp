// Copyright 2025 UNN-CS Team
#include "tasks.h"
#include <cmath>

double zd_1()
{
    Circle tmp;

    double earth = 6378.1;
    tmp.setRadius(earth + 0.001);

    return tmp.getFerence();
}

double zd_2()
{
    Circle pool;
    Circle bound;

    pool.setRadius(3);
    double track_cost = (pow(pool.getRadius() + 1, 2) * PI - pool.getArea());

    bound.setRadius(pool.getRadius() + 1);
    double bound_cost = bound.getFerence() * 2000;

    return track_cost * 1000 + bound_cost;
}