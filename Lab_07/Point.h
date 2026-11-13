#pragma once
#include <cmath>
#include <iostream>

// —труктура дл€ хранени€ координат точки
struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // ћетод дл€ вычислени€ рассто€ни€ до другой точки
    double distanceTo(const Point& other) const {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};