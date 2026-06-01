// Copyright 2025 UNN-CS
#include "circle.h"
#include <cmath>
#include <stdexcept>

const double PI = 3.14159265358979323846;

Circle::Circle(double initialRadius) : rad(initialRadius) {
    if (rad < 0) {
        throw std::invalid_argument("Radius cannot be negative");
    }
    updateFromRadius();
}

void Circle::updateFromRadius() {
    circ = 2.0 * PI * rad;
    sq = PI * rad * rad;
}

void Circle::updateFromCircumference() {
    rad = circ / (2.0 * PI);
    sq = (circ * circ) / (4.0 * PI);
}

void Circle::updateFromArea() {
    rad = std::sqrt(sq / PI);
    circ = 2.0 * PI * rad;
}

void Circle::setRadius(double r) {
    if (r < 0) {
        throw std::invalid_argument("Radius cannot be negative");
    }
    rad = r;
    updateFromRadius();
}

void Circle::setCircumference(double c) {
    if (c < 0) {
        throw std::invalid_argument("Circumference cannot be negative");
    }
    circ = c;
    updateFromCircumference();
}

void Circle::setArea(double a) {
    if (a < 0) {
        throw std::invalid_argument("Area cannot be negative");
    }
    sq = a;
    updateFromArea();
}

double Circle::getRadius() const {
    return rad;
}

double Circle::getCircumference() const {
    return circ;
}

double Circle::getArea() const {
    return sq;
}
