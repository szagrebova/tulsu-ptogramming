#include <iostream>
#include <clocale>
#define NOMINMAX
#include <windows.h>

#include "IntStack.h"
#include "InputUtils.h"

using namespace std;

// СЛИЯНИЕ ДВУХ СТЕКОВ В ТРЕТИЙ (ПО НЕУБЫВАНИЮ)
IntStack mergeStacks(IntStack s1, IntStack s2) {
    IntStack result;
    while (!s1.isEmpty() && !s2.isEmpty()) {
        if (s1.peek() > s2.peek()) {
            result.push(s1.pop());
        }
        else {
            result.push(s2.pop());
        }
    }
    while (!s1.isEmpty()) result.push(s1.pop());
    while (!s2.isEmpty()) result.push(s2.pop());
    return result;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    IntStack stack1;
    IntStack stack2;
    IntStack mergedStack;

    cout << "==================================================\n";
    cout << "         СТЕКИ И ИХ СЛИЯНИЕ (Вариант 2)\n";
    cout << "==================================================\n";

    int choice;
    do {
        cout << "\n==================================================\n";
        cout << "                    МЕНЮ\n";
        cout << "==================================================\n";
        cout << "1 - Заполнить Стек 1 (с клавиатуры)\n";
        cout << "2 - Заполнить Стек 2 (с клавиатуры)\n";
        cout << "3 - Загрузить Стек 1 из файла (input1.txt)\n";
        cout << "4 - Загрузить Стек 2 из файла (input2.txt)\n";
        cout << "5 - Выполнить слияние (в неуб. порядке)\n";
        cout << "6 - Показать все стеки\n";
        cout << "7 - Сохранить результат слияния в файл (output.txt)\n";
        cout << "0 - Выход\n";
        choice = readIntInRange("Ваш выбор: ", 0, 7);

        switch (choice) {
        case 1: {
            stack1.clear();
            int n = readIntInRange("Сколько чисел добавить в Стек 1? ", 1, 100);
            cout << "Вводите числа (они будут уложены в стек по порядку):\n";
            for (int i = 0; i < n; ++i) {
                int val = readInt("  Число: ");
                stack1.push(val);
            }
            cout << "Стек 1 сформирован.\n";
            break;
        }
        case 2: {
            stack2.clear();
            int n = readIntInRange("Сколько чисел добавить в Стек 2? ", 1, 100);
            cout << "Вводите числа (они будут уложены в стек по порядку):\n";
            for (int i = 0; i < n; ++i) {
                int val = readInt("  Число: ");
                stack2.push(val);
            }
            cout << "Стек 2 сформирован.\n";
            break;
        }
        case 3:
            stack1.loadFromFile("input1.txt");
            break;
        case 4:
            stack2.loadFromFile("input2.txt");
            break;
        case 5: {
            if (stack1.isEmpty() || stack2.isEmpty()) {
                cout << "Ошибка: сначала заполните оба стека!\n";
                break;
            }
            mergedStack = mergeStacks(stack1, stack2);
            cout << "Слияние выполнено успешно!\n";
            cout << "Результат в третьем стеке (при выводе от вершины будет неубывающая последовательность).\n";
            break;
        }
        case 6:
            cout << "\n--- Текущее состояние ---\n";
            stack1.print("Стек 1");
            stack2.print("Стек 2");
            mergedStack.print("Стек 3 (результат)");
            break;
        case 7:
            mergedStack.saveToFile("output.txt");
            break;
        case 0:
            cout << "Выход из программы.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}