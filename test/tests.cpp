// Copyright 2023 Your Name or Organization

#include <cmath>
#include "gtest/gtest.h"

#include "tasks.h"
#include "circle.h"



const double PI = 3.141592653589793;

TEST(CircleTest, SetRadius) {
    Circle c;
    c.setRadius(1.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1.0);
    EXPECT_NEAR(c.getFerence(), 2 * PI, 1e-10);
    EXPECT_NEAR(c.getArea(), PI, 1e-10);
}

TEST(CircleTest, SetFerence) {
    Circle c;
    c.setFerence(2 * PI);
    EXPECT_NEAR(c.getRadius(), 1.0, 1e-10);
    EXPECT_NEAR(c.getArea(), PI, 1e-10);
}

TEST(CircleTest, SetArea) {
    Circle c;
    c.setArea(PI);
    EXPECT_NEAR(c.getRadius(), 1.0, 1e-10);
    EXPECT_NEAR(c.getFerence(), 2 * PI, 1e-10);
}

TEST(CircleTest, RadiusZero) {
    Circle c;
    c.setRadius(0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0);
}

TEST(CircleTest, LargeRadius) {
    Circle c;
    c.setRadius(1000);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1000);
    EXPECT_NEAR(c.getFerence(), 2000 * PI, 1e-10);
    EXPECT_NEAR(c.getArea(), 1000000 * PI, 1e-10);
}

TEST(CircleTest, Zd1) {
    double result = zd_1();
    EXPECT_NEAR(result, 2 * PI * (6378.1 + 0.001), 1e-2);
}

TEST(CircleTest, Zd2) {
    double result = zd_2();
    double expectedTrackCost = (pow(3 + 1, 2) * PI
     - PI * 9) * 1000;
    double expectedBoundCost = 2 * PI * (3 + 1) * 2000;
    EXPECT_NEAR(result, expectedTrackCost + expectedBoundCost, 1e-2);
}

TEST(CircleTest, Zd2RadiusCheck) {
    Circle pool;
    pool.setRadius(3);
    Circle bound;
    bound.setRadius(pool.getRadius() + 1);
    EXPECT_DOUBLE_EQ(bound.getRadius(), 4);
}

TEST(CircleTest, Zd2AreaCheck) {
    Circle pool;
    pool.setRadius(3);
    EXPECT_NEAR(pool.getArea(), 9 * PI, 1e-10);
}

TEST(CircleTest, Zd2FerenceCheck) {
    Circle bound;
    bound.setRadius(4);
    EXPECT_NEAR(bound.getFerence(), 8 * PI, 1e-10);
}

TEST(CircleTest, Zd2TrackCost) {
    Circle pool;
    pool.setRadius(3);
    double trackArea = pow(4, 2) * PI - pool.getArea();
    EXPECT_NEAR(trackArea, 7 * PI, 1e-10);
}

TEST(CircleTest, Zd2BoundCost) {
    Circle bound;
    bound.setRadius(4);
    double boundCost = bound.getFerence() * 2000;
    EXPECT_NEAR(boundCost, 8 * PI * 2000, 1e-10);
}

TEST(CircleTest, Zd2TotalCost) {
    double result = zd_2();
    double expected = (7 * PI * 1000) + (8 * PI * 2000);
    EXPECT_NEAR(result, expected, 1e-2);
}

TEST(CircleTest, NegativeRadius) {
    Circle c;
    c.setRadius(-5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), -5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), -10 * PI);
    EXPECT_DOUBLE_EQ(c.getArea(), -25 * PI);
}

TEST(CircleTest, NegativeFerence) {
    Circle c;
    c.setFerence(-10 * PI);
    EXPECT_DOUBLE_EQ(c.getRadius(), -5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), -25 * PI);
}

TEST(CircleTest, NegativeArea) {
    Circle c;
    c.setArea(-25 * PI);
    EXPECT_TRUE(std::isnan(c.getRadius()));
    EXPECT_TRUE(std::isnan(c.getFerence()));
}

TEST(CircleTest, TinyRadius) {
    Circle c;
    c.setRadius(1e-100);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1e-100);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 1e-100);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 1e-200);
}

TEST(CircleTest, HugeRadius) {
    Circle c;
    c.setRadius(1e100);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1e100);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 1e100);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 1e200);
}

TEST(CircleTest, SequentialUpdates) {
    Circle c;
    
    c.setRadius(2.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 4 * PI);
    EXPECT_DOUBLE_EQ(c.getArea(), 4 * PI);
    
    c.setFerence(6 * PI);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 9 * PI);
    
    c.setArea(16 * PI);
    EXPECT_DOUBLE_EQ(c.getRadius(), 4.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 8 * PI);
}

TEST(CircleTest, ZeroArea) {
    Circle c;
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleTest, DoubleUpdate) {
    Circle c;
    c.setRadius(10.0);
    c.setFerence(20 * PI); 
    
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 20 * PI);
    EXPECT_DOUBLE_EQ(c.getArea(), 100 * PI);
}

TEST(CircleTest, Zd1Negative) {
    Circle tmp;
    tmp.setRadius(-6378.1);
    double result = 2 * PI * (-6378.1);
    EXPECT_DOUBLE_EQ(tmp.getFerence(), result);
}

TEST(CircleTest, Zd2ZeroRadius) {
    Circle pool;
    pool.setRadius(0);
    
    Circle bound;
    bound.setRadius(pool.getRadius() + 1);
    
    double track_cost = pow(1, 2) * PI * 1000;
    double bound_cost = bound.getFerence() * 2000;
    
    EXPECT_DOUBLE_EQ(track_cost + bound_cost, 1000*PI + 4000*PI);
}