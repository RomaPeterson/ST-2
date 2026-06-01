// Copyright 2025 UNN-CS
#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double EPSILON = 1e-5;
const double PI = 3.14159265358979323846;

class CircleTest : public ::testing::Test {
 protected:
    void SetUp() override {
    }
};

TEST_F(CircleTest, ConstructorInitializesRadius) {
    Circle c(5.0);
    ASSERT_NEAR(5.0, c.getRadius(), EPSILON);
}

TEST_F(CircleTest, ConstructorCalculatesCircumference) {
    Circle c(3.0);
    double expected = 2.0 * PI * 3.0;
    ASSERT_NEAR(expected, c.getCircumference(), EPSILON);
}

TEST_F(CircleTest, ConstructorCalculatesArea) {
    Circle c(4.0);
    double expected = PI * 16.0;
    ASSERT_NEAR(expected, c.getArea(), EPSILON);
}

TEST_F(CircleTest, ZeroRadiusConstruction) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
    EXPECT_DOUBLE_EQ(0.0, c.getCircumference());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST_F(CircleTest, LargeRadiusConstruction) {
    Circle c(1000000.0);
    EXPECT_DOUBLE_EQ(1000000.0, c.getRadius());
}

TEST_F(CircleTest, SetRadiusUpdatesValue) {
    Circle c(1.0);
    c.setRadius(7.0);
    EXPECT_NEAR(7.0, c.getRadius(), EPSILON);
}

TEST_F(CircleTest, SetRadiusRecalculatesCircumference) {
    Circle c(1.0);
    c.setRadius(5.0);
    double expected = 2.0 * PI * 5.0;
    EXPECT_NEAR(expected, c.getCircumference(), EPSILON);
}

TEST_F(CircleTest, SetRadiusRecalculatesArea) {
    Circle c(1.0);
    c.setRadius(6.0);
    double expected = PI * 36.0;
    EXPECT_NEAR(expected, c.getArea(), EPSILON);
}

TEST_F(CircleTest, SetRadiusToZero) {
    Circle c(10.0);
    c.setRadius(0.0);
    EXPECT_NEAR(0.0, c.getRadius(), EPSILON);
    EXPECT_NEAR(0.0, c.getCircumference(), EPSILON);
    EXPECT_NEAR(0.0, c.getArea(), EPSILON);
}

TEST_F(CircleTest, SetCircumferenceUpdatesRadius) {
    Circle c(1.0);
    double circumference = 2.0 * PI * 8.0;
    c.setCircumference(circumference);
    EXPECT_NEAR(8.0, c.getRadius(), EPSILON);
}

TEST_F(CircleTest, SetCircumferenceUpdatesArea) {
    Circle c(1.0);
    double circumference = 2.0 * PI * 3.0;
    c.setCircumference(circumference);
    double expected = PI * 9.0;
    EXPECT_NEAR(expected, c.getArea(), EPSILON);
}

TEST_F(CircleTest, SetCircumferenceZero) {
    Circle c(5.0);
    c.setCircumference(0.0);
    EXPECT_NEAR(0.0, c.getRadius(), EPSILON);
    EXPECT_NEAR(0.0, c.getCircumference(), EPSILON);
}

TEST_F(CircleTest, SetSmallCircumference) {
    Circle c(10.0);
    double circumference = 2.0 * PI * 0.5;
    c.setCircumference(circumference);
    EXPECT_NEAR(0.5, c.getRadius(), EPSILON);
}

TEST_F(CircleTest, SetAreaUpdatesRadius) {
    Circle c(1.0);
    c.setArea(PI * 25.0);
    EXPECT_NEAR(5.0, c.getRadius(), EPSILON);
}

TEST_F(CircleTest, SetAreaUpdatesCircumference) {
    Circle c(1.0);
    c.setArea(PI * 49.0);
    double expected = 2.0 * PI * 7.0;
    EXPECT_NEAR(expected, c.getCircumference(), EPSILON);
}

TEST_F(CircleTest, SetAreaZero) {
    Circle c(10.0);
    c.setArea(0.0);
    EXPECT_NEAR(0.0, c.getRadius(), EPSILON);
    EXPECT_NEAR(0.0, c.getArea(), EPSILON);
}

TEST_F(CircleTest, SetSmallArea) {
    Circle c(100.0);
    c.setArea(PI * 0.01);
    EXPECT_NEAR(0.1, c.getRadius(), EPSILON);
}

TEST_F(CircleTest, MultipleRadiusChanges) {
    Circle c(2.0);
    c.setRadius(4.0);
    c.setRadius(8.0);
    EXPECT_NEAR(8.0, c.getRadius(), EPSILON);
    EXPECT_NEAR(2.0 * PI * 8.0, c.getCircumference(), EPSILON);
    EXPECT_NEAR(PI * 64.0, c.getArea(), EPSILON);
}

TEST_F(CircleTest, CircleParametersRelationship) {
    Circle c(10.0);
    double circ = c.getCircumference();
    double area = c.getArea();
    double radius = c.getRadius();

    EXPECT_NEAR(circ, 2.0 * PI * radius, EPSILON);
    EXPECT_NEAR(area, PI * radius * radius, EPSILON);
    EXPECT_NEAR(circ * circ, 4.0 * PI * area, EPSILON);
}

TEST_F(CircleTest, CycleSetRadiusToAreaToCircumferenceBack) {
    Circle c(6.0);
    double initialRadius = c.getRadius();

    c.setArea(c.getArea());
    EXPECT_NEAR(initialRadius, c.getRadius(), EPSILON);

    c.setCircumference(c.getCircumference());
    EXPECT_NEAR(initialRadius, c.getRadius(), EPSILON);
}

TEST(RopeGapTest, ResultIsPositive) {
    double gap = Tasks::calculateRopeGap();
    EXPECT_GT(gap, 0.0);
}

TEST(RopeGapTest, ResultApproximatelyCorrect) {
    double gap = Tasks::calculateRopeGap();
    EXPECT_NEAR(0.159155, gap, 0.001);
}

TEST(RopeGapTest, ResultIndependentOfEarthSize) {
    double gap = Tasks::calculateRopeGap();
    EXPECT_LT(gap, 1.0);
    EXPECT_GT(gap, 0.15);
}

TEST(RopeGapTest, Deterministic) {
    double gap1 = Tasks::calculateRopeGap();
    double gap2 = Tasks::calculateRopeGap();
    EXPECT_DOUBLE_EQ(gap1, gap2);
}

TEST(PoolCostTest, ResultIsPositive) {
    double cost = Tasks::calculatePoolCost();
    EXPECT_GT(cost, 0.0);
}

TEST(PoolCostTest, ResultInReasonableRange) {
    double cost = Tasks::calculatePoolCost();
    EXPECT_GT(cost, 50000.0);
    EXPECT_LT(cost, 100000.0);
}

TEST(PoolCostTest, BreakdownCalculation) {
    double cost = Tasks::calculatePoolCost();
    double expectedFenceCost = 2.0 * PI * 4.0 * 2000.0;
    double expectedWalkwayCost = 7.0 * PI * 1000.0;
    double expectedTotal = expectedFenceCost + expectedWalkwayCost;

    EXPECT_NEAR(expectedTotal, cost, 0.1);
}

TEST(PoolCostTest, Deterministic) {
    double cost1 = Tasks::calculatePoolCost();
    double cost2 = Tasks::calculatePoolCost();
    EXPECT_DOUBLE_EQ(cost1, cost2);
}

TEST(IntegrationTest, CircleWithTaskRope) {
    Circle earthCircle(6378100.0);
    double originalCirc = earthCircle.getCircumference();

    Circle newCircle(0.0);
    newCircle.setCircumference(originalCirc + 1.0);

    double gap = newCircle.getRadius() - 6378100.0;
    EXPECT_NEAR(0.159155, gap, 0.001);
}

TEST(IntegrationTest, CircleWithTaskPool) {
    Circle pool(3.0);
    Circle poolWithTrack(4.0);

    double walkwayArea = poolWithTrack.getArea() - pool.getArea();
    double expectedArea = 7.0 * PI;

    EXPECT_NEAR(expectedArea, walkwayArea, EPSILON);
}
