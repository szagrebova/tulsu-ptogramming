#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <clocale>
#define NOMINMAX
#include <windows.h>

#include "AVLTree.h" // Подключаем наше дерево

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    srand(time(0)); // инициализация генератора случайных чисел
    AVLTree tree;
    set<int> usedKeys; // для уникальности ключей

    const int N = 25; // не менее 20 узлов
    cout << "Генерация " << N << " случайных узлов:\n";

    for (int i = 0; i < N; ++i) {
        int key;
        // Генерируем уникальный ключ от 1 до 100
        do {
            key = rand() % 100 + 1;
        } while (usedKeys.count(key));
        usedKeys.insert(key);

        int value = rand() % 1000; // значение поля данных
        cout << "key=" << key << ", value=" << value << endl;
        tree.insert(key, value);
    }

    cout << "\nДерево (симметричный обход):\n";
    tree.printInOrder();

    cout << "\nСтруктура дерева (повёрнуто на 90°):\n";
    tree.printTree();

    int level = 4;
    int count = tree.countLevel(level);
    cout << "\nКоличество узлов на " << level
        << "-м уровне (корень = 1): " << count << endl;

    return 0;
}