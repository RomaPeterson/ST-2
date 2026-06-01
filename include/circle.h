// Copyright 2025 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
private:
    double rad;
    double circ;
    double sq;
    
    void recalculateAll();
    void updateFromRadius();
    void updateFromCircumference();
    void updateFromArea();

public:
    Circle(double initialRadius);
    
    void setRadius(double r);
    void setCircumference(double c);
    void setArea(double a);
    
    double getRadius() const;
    double getCircumference() const;
    double getArea() const;
};

#endif // INCLUDE_CIRCLE_H_
