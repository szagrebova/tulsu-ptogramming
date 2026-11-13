#pragma once
#include "Polygon.h"

class Triangle : public Polygon {
private:
    double a, b, c; // Длины сторон

    void calculateSides();
    void checkExist() const;

public:
    // Конструктор производного класса
    Triangle(const Point& p1, const Point& p2, const Point& p3);

    // Переопределение виртуальных методов
    double perimeter() const override;
    double area() const override;
    void draw() const override; // <--- Без параметров

    // Специфические методы
    Point centroid() const;
    void printMedians() const;
    void printBisectors() const;
    Point incenter() const;
    Point orthocenter() const;
};