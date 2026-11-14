#include <iostream>
#include <string>
#include <clocale>
#define NOMINMAX
#include <windows.h>

#include "Array.h"
#include "InputUtils.h"

using namespace std;

// Функция для тестирования массива любого типа
template <typename T>
void testArray(const string& typeName) {
    cout << "\n=== ТЕСТИРОВАНИЕ МАССИВА ТИПА: " << typeName << " ===\n";
    int n = readIntInRange("Введите размер массива: ", 1, 20);

    Array<T> arr(n);
    cout << "Введите элементы массива:\n";
    arr.inputFromKeyboard();

    arr.print("Исходный массив");

    cout << "\nВыберите метод сортировки:\n";
    cout << "1 - Метод пузырька\n";
    cout << "2 - Метод выбора\n";
    int choice = readIntInRange("Ваш выбор: ", 1, 2);

    if (choice == 1) {
        arr.sortBubble();
        cout << "Массив отсортирован методом пузырька.\n";
    }
    else {
        arr.sortSelection();
        cout << "Массив отсортирован методом выбора.\n";
    }

    arr.print("Отсортированный массив");
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    cout << "==================================================\n";
    cout << "       ШАБЛОНЫ КЛАССОВ: ОДНОМЕРНЫЙ МАССИВ\n";
    cout << "==================================================\n";

    int choice;
    do {
        cout << "\n==================================================\n";
        cout << "                    МЕНЮ\n";
        cout << "==================================================\n";
        cout << "1 - Тест массива целых чисел (int)\n";
        cout << "2 - Тест массива дробных чисел (double)\n";
        cout << "3 - Тест массива строк (string)\n";
        cout << "0 - Выход\n";

        choice = readIntInRange("Ваш выбор: ", 0, 3);

        switch (choice) {
        case 1: testArray<int>("ЦЕЛЫЕ ЧИСЛА (int)"); break;
        case 2: testArray<double>("ДРОБНЫЕ ЧИСЛА (double)"); break;
        case 3: testArray<string>("СТРОКИ (string)"); break;
        case 0: cout << "Выход из программы.\n"; break;
        }
    } while (choice != 0);

    return 0;
}