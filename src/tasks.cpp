// Copyright 2025 UNN-CS
#include "tasks.h"
#include "circle.h"
#include <cmath>

namespace Tasks {

double calculateRopeGap() {
    const double EARTH_RADIUS_M = 6378100.0;
    
    Circle earthCircle(EARTH_RADIUS_M);
    double originalCircumference = earthCircle.getCircumference();
    
    double newCircumference = originalCircumference + 1.0;
    
    Circle newCircle(0.0);
    newCircle.setCircumference(newCircumference);
    
    double gap = newCircle.getRadius() - EARTH_RADIUS_M;
    
    return gap;
}

double calculatePoolCost() {
    const double POOL_RADIUS = 3.0;
    const double WALKWAY_WIDTH = 1.0;
    const double CONCRETE_PRICE = 1000.0;
    const double FENCE_PRICE = 2000.0;
    
    Circle poolCircle(POOL_RADIUS);
    Circle outerCircle(POOL_RADIUS + WALKWAY_WIDTH);
    
    double fenceCost = outerCircle.getCircumference() * FENCE_PRICE;
    
    double walkwayArea = outerCircle.getArea() - poolCircle.getArea();
    double concreteСost = walkwayArea * CONCRETE_PRICE;
    
    double totalCost = fenceCost + concreteСost;
    
    return totalCost;
}

} // namespace Tasks
