#include "Utils.h"
#include <iostream>
#include <limits>

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int readInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            clearInput();
            return value;
        }
        cout << "Ошибка: введите целое число!\n";
        clearInput();
    }
}

int readPositiveInt(const string& prompt) {
    while (true) {
        int value = readInt(prompt);
        if (value > 0) return value;
        cout << "Ошибка: число должно быть больше нуля!\n";
    }
}

string readNonEmptyLine(const string& prompt) {
    string value;
    while (true) {
        cout << prompt;
        if (getline(cin, value) && !value.empty()) return value;
        cout << "Ошибка: строка не может быть пустой!\n";
        if (cin.fail()) clearInput();
    }
}

int readIntInRange(const string& prompt, int min, int max) {
    while (true) {
        int value = readInt(prompt);
        if (value >= min && value <= max) return value;
        cout << "Ошибка: число должно быть в диапазоне от " << min
            << " до " << max << "!\n";
    }
}