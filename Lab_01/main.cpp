#include <iostream>
#include <clocale>
#define NOMINMAX
#include <windows.h>

#include "Utils.h"
#include "BookStack.h"
#include "BookQueue.h"

using namespace std;

void runStackMode() {
    BookStack stack;
    int choice;
    do {
        cout << "\n========= МЕНЮ (СТЕК, LIFO) =========\n";
        cout << "1. Начальное формирование данных\n";
        cout << "2. Добавить книгу (в начало)\n";
        cout << "3. Удалить книгу (из начала)\n";
        cout << "4. Вывести книги (упорядочены по году издания)\n";
        cout << "5. Очистить стек\n";
        cout << "0. Выход\n";
        choice = readIntInRange("Ваш выбор: ", 0, 5);

        switch (choice) {
        case 1: {
            int n = readPositiveInt("Сколько книг добавить? ");
            for (int i = 0; i < n; ++i) {
                cout << "\n--- Книга №" << (i + 1) << " ---\n";
                Book b = inputBook();
                stack.push(b);
            }
            cout << "Стек сформирован.\n";
            break;
        }
        case 2: {
            Book b = inputBook();
            stack.push(b);
            cout << "Книга добавлена на вершину стека.\n";
            break;
        }
        case 3: {
            try {
                Book b = stack.pop();
                cout << "Удалена книга: " << b.title << endl;
            }
            catch (const exception& e) {
                cout << "Ошибка: " << e.what() << endl;
            }
            break;
        }
        case 4: stack.print(); break;
        case 5: stack.clear(); cout << "Стек очищен.\n"; break;
        case 0: cout << "Выход из режима стека.\n"; break;
        }
    } while (choice != 0);
}

void runQueueMode() {
    BookQueue queue;
    int choice;
    do {
        cout << "\n========= МЕНЮ (ОЧЕРЕДЬ, FIFO) =========\n";
        cout << "1. Начальное формирование данных\n";
        cout << "2. Добавить книгу (в конец)\n";
        cout << "3. Удалить книгу (из начала)\n";
        cout << "4. Вывести книги (упорядочены по году издания)\n";
        cout << "5. Очистить очередь\n";
        cout << "0. Выход\n";
        choice = readIntInRange("Ваш выбор: ", 0, 5);

        switch (choice) {
        case 1: {
            int n = readPositiveInt("Сколько книг добавить? ");
            for (int i = 0; i < n; ++i) {
                cout << "\n--- Книга №" << (i + 1) << " ---\n";
                Book b = inputBook();
                queue.pushBack(b);
            }
            cout << "Очередь сформирована.\n";
            break;
        }
        case 2: {
            Book b = inputBook();
            queue.pushBack(b);
            cout << "Книга добавлена в конец очереди.\n";
            break;
        }
        case 3: {
            try {
                Book b = queue.popFront();
                cout << "Удалена книга: " << b.title << endl;
            }
            catch (const exception& e) {
                cout << "Ошибка: " << e.what() << endl;
            }
            break;
        }
        case 4: queue.print(); break;
        case 5: queue.clear(); cout << "Очередь очищена.\n"; break;
        case 0: cout << "Выход из режима очереди.\n"; break;
        }
    } while (choice != 0);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    cout << "==================================================\n";
    cout << "                 БИБЛИОТЕКА\n";
    cout << "==================================================\n";

    while (true) {
        cout << "\nВыберите структуру данных:\n";
        cout << "  1 - Стек (LIFO)\n";
        cout << "  2 - Очередь (FIFO)\n";
        cout << "  0 - завершение работы\n";
        int mode = readIntInRange("Ваш выбор: ", 0, 2);

        if (mode == 0) break;
        else if (mode == 1) runStackMode();
        else if (mode == 2) runQueueMode();
    }
    return 0;
}