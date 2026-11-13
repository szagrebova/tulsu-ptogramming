#include <iostream>
#include <clocale>
#define NOMINMAX
#include <windows.h>

#include "Fraction.h"
#include "InputUtils.h"

using namespace std;

// ФУНКЦИЯ ОБРАБОТКИ МАССИВА
void processEvenIndices(Fraction* arr, int size) {
    for (int i = 0; i < size - 1; i += 2) {
        arr[i] = arr[i] + arr[i + 1];
    }
}

// ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ ДЛЯ МЕНЮ
Fraction inputFraction() {
    Fraction f;
    f.setFromInput();
    return f;
}

void printArray(Fraction* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << " [" << i << "] ";
        arr[i].showValue();
        cout << "\n";
    }
}

// ГЛАВНАЯ ФУНКЦИЯ
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    cout << "==================================================\n";
    cout << "                   ДРОБИ\n";
    cout << "==================================================\n";

    // --- ВВОД МАССИВА ---
    int n = readIntInRange("Введите количество дробей: ", 1, 100);
    Fraction* arr = new Fraction[n];

    for (int i = 0; i < n; ++i) {
        cout << "\n--- Дробь №" << (i + 1) << " ---\n";
        try {
            arr[i].setFromInput();
        }
        catch (const exception& e) {
            cout << "Ошибка: " << e.what() << " Повторите ввод.\n";
            --i;
        }
    }

    // --- МЕНЮ ---
    int choice;
    do {
        cout << "\n==================================================\n";
        cout << "                    МЕНЮ\n";
        cout << "==================================================\n";
        cout << "1 - Показать все дроби\n";
        cout << "2 - Сложить все дроби\n";
        cout << "3 - Перемножить все дроби\n";
        cout << "4 - Обработать массив (изменить чётные индексы)\n";
        cout << "5 - Операции с двумя дробями (+, -, *, /, сравнение)\n";
        cout << "0 - Выход\n";
        choice = readIntInRange("Ваш выбор: ", 0, 5);

        switch (choice) {
        case 1:
            cout << "\n=== Все дроби ===\n";
            printArray(arr, n);
            break;

        case 2: {
            Fraction s(0, 1);
            for (int i = 0; i < n; ++i) s = s + arr[i];
            cout << "\nСумма всех дробей: ";
            s.showValue();
            cout << "\n";
            break;
        }

        case 3: {
            Fraction p(1, 1);
            for (int i = 0; i < n; ++i) p = p * arr[i];
            cout << "\nПроизведение всех дробей: ";
            p.showValue();
            cout << "\n";
            break;
        }

        case 4: {
            cout << "\nБыло:\n";
            printArray(arr, n);
            processEvenIndices(arr, n);
            cout << "\nСтало (чётные индексы = arr[i] + arr[i+1]):\n";
            printArray(arr, n);
            break;
        }

        case 5: {
            cout << "\n--- Дробь A ---\n";
            Fraction a = inputFraction();
            cout << "--- Дробь B ---\n";
            Fraction b = inputFraction();

            int op;
            do {
                cout << "\n==================================================\n";
                cout << "         ОПЕРАЦИИ С ДРОБЯМИ\n";
                cout << "==================================================\n";
                cout << "A = "; a.show();
                cout << ", B = "; b.show();
                cout << "\n--------------------------------------------------\n";
                cout << "1 - Сложение (A + B)\n";
                cout << "2 - Вычитание (A - B)\n";
                cout << "3 - Умножение (A * B)\n";
                cout << "4 - Деление (A / B)\n";
                cout << "5 - Сравнение (==, <, >)\n";
                cout << "6 - Задать дроби заново\n";
                cout << "0 - Назад в главное меню\n";

                op = readIntInRange("Ваш выбор: ", 0, 6);

                switch (op) {
                case 1: cout << "\nA + B = "; (a + b).showValue(); cout << "\n"; break;
                case 2: cout << "\nA - B = "; (a - b).showValue(); cout << "\n"; break;
                case 3: cout << "\nA * B = "; (a * b).showValue(); cout << "\n"; break;
                case 4:
                    try {
                        cout << "\nA / B = "; (a / b).showValue(); cout << "\n";
                    }
                    catch (const exception& e) {
                        cout << "\nОшибка: " << e.what() << "\n";
                    }
                    break;
                case 5:
                    cout << "\nСравнение:\n";
                    cout << "  A == B ? " << (a == b ? "да" : "нет") << "\n";
                    cout << "  A <  B ? " << (a < b ? "да" : "нет") << "\n";
                    cout << "  A >  B ? " << (a > b ? "да" : "нет") << "\n";
                    cout << "  A <= B ? " << (a <= b ? "да" : "нет") << "\n";
                    cout << "  A >= B ? " << (a >= b ? "да" : "нет") << "\n";
                    break;
                case 6:
                    cout << "\n--- Дробь A заново ---\n"; a = inputFraction();
                    cout << "--- Дробь B заново ---\n"; b = inputFraction();
                    break;
                case 0:
                    cout << "Возврат в главное меню.\n";
                    break;
                }
            } while (op != 0);
            break;
        }

        case 0:
            cout << "Выход из программы.\n";
            break;
        }
    } while (choice != 0);

    delete[] arr;
    cout << "\nПрограмма завершена.\n";
    return 0;
}