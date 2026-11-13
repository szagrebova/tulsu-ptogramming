#include <iostream>
#include <clocale>
#define NOMINMAX
#include <windows.h>

#include "Abiturient.h"
#include "InputUtils.h"

using namespace std;

// а) абитуриенты с неудовлетворительными оценками
void printBadGrades(Abiturient* arr, int n) {
    cout << "\n=== а) Абитуриенты с неудовлетворительными оценками ===\n";
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (arr[i].hasBadGrades()) {
            arr[i].show();
            cout << "---\n";
            found = true;
        }
    }
    if (!found) cout << "Таких абитуриентов нет.\n";
}

// б) абитуриенты с суммой баллов >= заданной
void printBySum(Abiturient* arr, int n, int minSum) {
    cout << "\n=== б) Абитуриенты с суммой баллов >= " << minSum << " ===\n";
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (arr[i].getSum() >= minSum) {
            arr[i].show();
            cout << "---\n";
            found = true;
        }
    }
    if (!found) cout << "Таких абитуриентов нет.\n";
}

// в) N лучших по сумме + абитуриенты с полупроходным баллом
void printTopNAndHalfPass(Abiturient* arr, int n, int N) {
    cout << "\n=== в) Топ-" << N << " абитуриентов по сумме баллов ===\n";

    // Делаем копию массива указателей для сортировки
    Abiturient** ptrs = new Abiturient * [n];
    for (int i = 0; i < n; ++i) ptrs[i] = &arr[i];

    // Сортировка по убыванию суммы (простая сортировка выбором)
    for (int i = 0; i < n - 1; ++i) {
        int maxIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (ptrs[j]->getSum() > ptrs[maxIdx]->getSum())
                maxIdx = j;
        }
        Abiturient* t = ptrs[i];
        ptrs[i] = ptrs[maxIdx];
        ptrs[maxIdx] = t;
    }

    // Вывод первых N
    int toShow = (N < n) ? N : n;
    for (int i = 0; i < toShow; ++i) {
        ptrs[i]->show();
        cout << "---\n";
    }

    // Полупроходной балл — сумма у последнего из первых N
    if (toShow > 0) {
        int halfPass = ptrs[toShow - 1]->getSum();
        cout << "\nПолупроходной балл: " << halfPass << "\n";
        cout << "Абитуриенты с полупроходным баллом (все, у кого сумма = "
            << halfPass << "):\n";
        for (int i = 0; i < n; ++i) {
            if (arr[i].getSum() == halfPass) {
                arr[i].show();
                cout << "---\n";
            }
        }
    }

    // Исправление мелкого бага оригинала: удаление массива ptrs 
    // должно быть вне блока if (toShow > 0), иначе утечка памяти!
    delete[] ptrs;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    cout << "==========================================================\n";
    cout << " АБИТУРИЕНТЫ\n";
    cout << "==========================================================\n";

    int n = readIntInRange("Введите количество абитуриентов: ", 1, 100);
    Abiturient* arr = new Abiturient[n];

    for (int i = 0; i < n; ++i) {
        cout << "\n--- Абитуриент №" << (i + 1) << " ---\n";
        arr[i].setAll();
    }

    int choice;
    do {
        cout << "\n==========================================================\n";
        cout << " МЕНЮ\n";
        cout << "==========================================================\n";
        cout << "1 - а) Абитуриенты с неудовлетворительными оценками\n";
        cout << "2 - б) Абитуриенты с суммой баллов не меньше заданной\n";
        cout << "3 - в) Топ-N лучших + полупроходной балл\n";
        cout << "4 - Вывести полный список абитуриентов\n";
        cout << "0 - Выход\n";

        choice = readIntInRange("Ваш выбор: ", 0, 4);

        switch (choice) {
        case 1:
            printBadGrades(arr, n);
            break;
        case 2: {
            int minSum = readIntInRange("Введите минимальную сумму баллов (от 8 до 20): ", 8, 20);
            printBySum(arr, n, minSum);
            break;
        }
        case 3: {
            int N = readIntInRange("Сколько лучших абитуриентов вывести (N)? ", 1, n);
            printTopNAndHalfPass(arr, n, N);
            break;
        }
        case 4:
            cout << "\n=== Полный список абитуриентов ===\n";
            for (int i = 0; i < n; ++i) {
                arr[i].show();
                cout << "---\n";
            }
            break;
        case 0:
            cout << "Выход из программы.\n";
            break;
        }
    } while (choice != 0);

    delete[] arr;
    cout << "\nПрограмма завершена.\n";
    return 0;
}