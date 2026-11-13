#include <iostream>
#include <clocale>
#define NOMINMAX
#include <windows.h>
#include "Triangle.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    cout << "==================================================\n";
    cout << "     НАСЛЕДОВАНИЕ: МНОГОУГОЛЬНИК И ТРЕУГОЛЬНИК\n";
    cout << "==================================================\n";

    double x1, y1, x2, y2, x3, y3;

    cout << "Введите координаты вершины A (x y): ";
    cin >> x1 >> y1;
    cout << "Введите координаты вершины B (x y): ";
    cin >> x2 >> y2;
    cout << "Введите координаты вершины C (x y): ";
    cin >> x3 >> y3;

    try {
        Triangle tr(Point(x1, y1), Point(x2, y2), Point(x3, y3));

        cout << "\n--- Результаты расчетов ---\n";
        cout << "Периметр: " << tr.perimeter() << "\n";
        cout << "Площадь:  " << tr.area() << "\n\n";

        tr.printMedians();
        tr.printBisectors();
        cout << "\n";

        Point c = tr.centroid();
        cout << "Точка пересечения медиан (Центроид): (" << c.x << ", " << c.y << ")\n";

        Point i = tr.incenter();
        cout << "Точка пересечения биссектрис (Инцентр): (" << i.x << ", " << i.y << ")\n";

        Point h = tr.orthocenter();
        cout << "Точка пересечения высот (Ортоцентр): (" << h.x << ", " << h.y << ")\n";

        // ВЫЗОВ РИСОВАНИЯ (создаст файл triangle.html)
        tr.draw();

    }
    catch (const exception& e) {
        cout << "\n[ОШИБКА] " << e.what() << "\n";
    }

    return 0;
}