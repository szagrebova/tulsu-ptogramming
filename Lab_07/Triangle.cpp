#include "Triangle.h"
#include <stdexcept>
#include <cmath>
#include <fstream> // Для генерации файла

using namespace std;

// --- Конструктор и служебные методы ---
Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3)
    : Polygon({ p1, p2, p3 })
{
    calculateSides();
    checkExist();
}

void Triangle::calculateSides() {
    a = vertices[1].distanceTo(vertices[2]);
    b = vertices[0].distanceTo(vertices[2]);
    c = vertices[0].distanceTo(vertices[1]);
}

void Triangle::checkExist() const {
    if (area() < 1e-9) {
        throw invalid_argument("Точки лежат на одной прямой! Треугольник не существует.");
    }
}

double Triangle::perimeter() const {
    return a + b + c;
}

double Triangle::area() const {
    double p = perimeter() / 2.0;
    double val = p * (p - a) * (p - b) * (p - c);
    return (val > 0) ? sqrt(val) : 0;
}

// --- Генерация картинки в браузере ---
void Triangle::draw() const {
    ofstream out("triangle.html");
    if (!out.is_open()) return;

    // Находим минимальные и максимальные координаты, чтобы отцентрировать
    double minX = min({ vertices[0].x, vertices[1].x, vertices[2].x });
    double maxX = max({ vertices[0].x, vertices[1].x, vertices[2].x });
    double minY = min({ vertices[0].y, vertices[1].y, vertices[2].y });
    double maxY = max({ vertices[0].y, vertices[1].y, vertices[2].y });

    // Центр треугольника
    double centerX = (minX + maxX) / 2.0;
    double centerY = (minY + maxY) / 2.0;

    // Масштаб (если треугольник маленький - увеличиваем, если большой - уменьшаем)
    double size = max(maxX - minX, maxY - minY);
    double scale = 1.0;
    if (size > 0) scale = 300.0 / size; // Вписываем в квадрат 300x300

    out << "<!DOCTYPE html>\n<html><head><meta charset='windows-1251'><title>Треугольник</title></head><body>\n";
    out << "<h2>Визуализация треугольника</h2>\n";
    out << "<svg width='600' height='600' style='border:1px solid black; background-color: #f0f0f0;'>\n";

    // Рисуем треугольник (с учетом масштаба и центрирования)
    out << "<polygon points='";
    for (int i = 0; i < 3; ++i) {
        double drawX = (vertices[i].x - centerX) * scale + 300;
        double drawY = -(vertices[i].y - centerY) * scale + 300;
        out << drawX << "," << drawY << " ";
    }
    out << "' fill='rgba(0, 150, 255, 0.3)' stroke='blue' stroke-width='3' />\n";

    // Рисуем маленькие точки на вершинах
    const char* colors[] = { "red", "green", "purple" };
    for (int i = 0; i < 3; ++i) {
        double drawX = (vertices[i].x - centerX) * scale + 300;
        double drawY = -(vertices[i].y - centerY) * scale + 300;
        out << "<circle cx='" << drawX << "' cy='" << drawY
            << "' r='4' fill='" << colors[i] << "' />\n";
    }

    out << "</svg>\n</body></html>";
    out.close();

    cout << "\nТреугольник успешно построен! Откройте файл 'triangle.html' в браузере.\n";
}

// --- Специфические методы ---
Point Triangle::centroid() const {
    double cx = (vertices[0].x + vertices[1].x + vertices[2].x) / 3.0;
    double cy = (vertices[0].y + vertices[1].y + vertices[2].y) / 3.0;
    return Point(cx, cy);
}

void Triangle::printMedians() const {
    double m_a = 0.5 * sqrt(2 * b * b + 2 * c * c - a * a);
    double m_b = 0.5 * sqrt(2 * a * a + 2 * c * c - b * b);
    double m_c = 0.5 * sqrt(2 * a * a + 2 * b * b - c * c);
    cout << "Длины медиан: m_a = " << m_a << ", m_b = " << m_b << ", m_c = " << m_c << "\n";
}

void Triangle::printBisectors() const {
    double l_a = sqrt(b * c * (1 - (a * a) / ((b + c) * (b + c))));
    double l_b = sqrt(a * c * (1 - (b * b) / ((a + c) * (a + c))));
    double l_c = sqrt(a * b * (1 - (c * c) / ((a + b) * (a + b))));
    cout << "Длины биссектрис: l_a = " << l_a << ", l_b = " << l_b << ", l_c = " << l_c << "\n";
}

Point Triangle::incenter() const {
    double ix = (a * vertices[0].x + b * vertices[1].x + c * vertices[2].x) / (a + b + c);
    double iy = (a * vertices[0].y + b * vertices[1].y + c * vertices[2].y) / (a + b + c);
    return Point(ix, iy);
}

// Исправленный ортоцентр (без NaN)
Point Triangle::orthocenter() const {
    double x1 = vertices[0].x, y1 = vertices[0].y;
    double x2 = vertices[1].x, y2 = vertices[1].y;
    double x3 = vertices[2].x, y3 = vertices[2].y;

    double d = 2.0 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    if (std::abs(d) < 1e-9) return Point(0, 0);

    double sq1 = x1 * x1 + y1 * y1;
    double sq2 = x2 * x2 + y2 * y2;
    double sq3 = x3 * x3 + y3 * y3;

    double hx = (sq1 * (y2 - y3) + sq2 * (y3 - y1) + sq3 * (y1 - y2)) / d;
    double hy = (sq1 * (x3 - x2) + sq2 * (x1 - x3) + sq3 * (x2 - x1)) / d;

    return Point(hx, hy);
}