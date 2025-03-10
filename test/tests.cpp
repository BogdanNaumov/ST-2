#include "gtest/gtest.h"
#include "tasks.h"
#include "circle.h"
#include <cmath>




TEST(CircleTest, SetRadius) {
    Circle c;
    c.setRadius(1.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1.0);
    EXPECT_NEAR(c.getFerence(), 2 * 3.141592653589793, 1e-10); 
    EXPECT_NEAR(c.getArea(), 3.141592653589793, 1e-10);       
}


TEST(CircleTest, SetFerence) {
    Circle c;
    c.setFerence(2 * 3.141592653589793);
    EXPECT_NEAR(c.getRadius(), 1.0, 1e-10);
    EXPECT_NEAR(c.getArea(), 3.141592653589793, 1e-10);
}


TEST(CircleTest, SetArea) {
    Circle c;
    c.setArea(3.141592653589793);
    EXPECT_NEAR(c.getRadius(), 1.0, 1e-10);
    EXPECT_NEAR(c.getFerence(), 2 * 3.141592653589793, 1e-10);
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
    EXPECT_NEAR(c.getFerence(), 2000 * 3.141592653589793, 1e-10);
    EXPECT_NEAR(c.getArea(), 1000000 * 3.141592653589793, 1e-10);
}


TEST(CircleTest, Zd1) {
    double result = zd_1();
    EXPECT_NEAR(result, 2 * 3.141592653589793 * (6378.1 + 0.001), 1e-2);
}


TEST(CircleTest, Zd2) {
    double result = zd_2();
    double expectedTrackCost = (pow(3 + 1, 2) * 3.141592653589793 - 3.141592653589793 * 9) * 1000;
    double expectedBoundCost = 2 * 3.141592653589793 * (3 + 1) * 2000;
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
    EXPECT_NEAR(pool.getArea(), 9 * 3.141592653589793, 1e-10);
}


TEST(CircleTest, Zd2FerenceCheck) {
    Circle bound;
    bound.setRadius(4);
    EXPECT_NEAR(bound.getFerence(), 8 * 3.141592653589793, 1e-10);
}


TEST(CircleTest, Zd2TrackCost) {
    Circle pool;
    pool.setRadius(3);
    double trackArea = pow(4, 2) * 3.141592653589793 - pool.getArea();
    EXPECT_NEAR(trackArea, 7 * 3.141592653589793, 1e-10);
}


TEST(CircleTest, Zd2BoundCost) {
    Circle bound;
    bound.setRadius(4);
    double boundCost = bound.getFerence() * 2000;
    EXPECT_NEAR(boundCost, 8 * 3.141592653589793 * 2000, 1e-10);
}


TEST(CircleTest, Zd2TotalCost) {
    double result = zd_2();
    double expected = (7 * 3.141592653589793 * 1000) + (8 * 3.141592653589793 * 2000);
    EXPECT_NEAR(result, expected, 1e-2);
}
