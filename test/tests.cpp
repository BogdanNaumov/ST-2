// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "tasks.h"
#include "circle.h"
#include <cmath>


const double PI = 3.141592653589793238462;

TEST(CircleTest, SetRadius)
{
    Circle c;
    c.setRadius(1.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1.0);
    EXPECT_NEAR(c.getFerence(), 2 * PI, 1e-6);
    EXPECT_NEAR(c.getArea(), PI, 1e-6);
}

TEST(CircleTest, SetFerence)
{
    Circle c;
    c.setFerence(2 * PI);
    EXPECT_NEAR(c.getRadius(), 1.0, 1e-6);
    EXPECT_NEAR(c.getArea(), PI, 1e-6);
}

TEST(CircleTest, SetArea)
{
    Circle c;
    c.setArea(PI);
    EXPECT_NEAR(c.getRadius(), 1.0, 1e-6);
    EXPECT_NEAR(c.getFerence(), 2 * PI, 1e-6);
}

TEST(CircleTest, RadiusZero)
{
    Circle c;
    c.setRadius(0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0);
}

TEST(CircleTest, LargeRadius)
{
    Circle c;
    c.setRadius(1000);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1000);
    EXPECT_NEAR(c.getFerence(), 2000 * PI, 1e-6);
    EXPECT_NEAR(c.getArea(), 1000000 * PI, 1e-6);
}

TEST(CircleTest, Zd1)
{
    double result = zd_1();
    EXPECT_NEAR(result, 2 * PI * (6378.1 + 0.001), 1e-2);
}

TEST(CircleTest, Zd2)
{
    double result = zd_2();
    double expectedTrackCost = (pow(3 + 1, 2) * PI - PI * 9) * 1000;
    double expectedBoundCost = 2 * PI * (3 + 1) * 2000;
    EXPECT_NEAR(result, expectedTrackCost + expectedBoundCost, 1e-2);
}

TEST(CircleTest, Zd2RadiusCheck)
{
    Circle pool;
    pool.setRadius(3);
    Circle bound;
    bound.setRadius(pool.getRadius() + 1);
    EXPECT_DOUBLE_EQ(bound.getRadius(), 4);
}

TEST(CircleTest, Zd2AreaCheck)
{
    Circle pool;
    pool.setRadius(3);
    EXPECT_NEAR(pool.getArea(), 9 * PI, 1e-6);
}

TEST(CircleTest, Zd2FerenceCheck)
{
    Circle bound;
    bound.setRadius(4);
    EXPECT_NEAR(bound.getFerence(), 8 * PI, 1e-6);
}

TEST(CircleTest, Zd2TrackCost)
{
    Circle pool;
    pool.setRadius(3);
    double trackArea = pow(4, 2) * PI - pool.getArea();
    EXPECT_NEAR(trackArea, 7 * PI, 1e-6);
}

TEST(CircleTest, Zd2BoundCost)
{
    Circle bound;
    bound.setRadius(4);
    double boundCost = bound.getFerence() * 2000;
    EXPECT_NEAR(boundCost, 8 * PI * 2000, 1e-6);
}

TEST(CircleTest, Zd2TotalCost)
{
    double result = zd_2();
    double expected = (7 * PI * 1000) + (8 * PI * 2000);
    EXPECT_NEAR(result, expected, 1e-2);
}
