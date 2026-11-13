#include "InputUtils.h"
#include <iostream>
#include <limits>

using namespace std;

void clearInput() {
    cin.clear();
    if (cin.rdbuf()->in_avail() > 0)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int readInt(const string& prompt) {
    int v;
    while (true) {
        cout << prompt;
        if (cin >> v) { clearInput(); return v; }
        cout << "Ошибка: введите целое число!\n";
        clearInput();
    }
}

int readIntInRange(const string& prompt, int lo, int hi) {
    while (true) {
        int v = readInt(prompt);
        if (v >= lo && v <= hi) return v;
        cout << "Ошибка: число должно быть от " << lo << " до " << hi << "!\n";
    }
}

int readNonZeroInt(const string& prompt) {
    while (true) {
        int v = readInt(prompt);
        if (v != 0) return v;
        cout << "Ошибка: знаменатель не может быть нулём!\n";
    }
}