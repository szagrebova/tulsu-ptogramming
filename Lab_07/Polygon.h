#pragma once
#include <vector>
#include <iostream>
#include "Point.h"

class Polygon {
protected:
    std::vector<Point> vertices; // Вершины

public:
    // Конструктор базового класса
    Polygon(const std::vector<Point>& v) : vertices(v) {}

    // Виртуальный деструктор
    virtual ~Polygon() = default;

    // Чисто виртуальные функции
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
    virtual void draw() const = 0;
};