#include "IntStack.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

// --- КОНСТРУКТОРЫ И ДЕСТРУКТОР ---
IntStack::IntStack() : top(nullptr) {}

IntStack::IntStack(const IntStack& other) : top(nullptr) {
    if (other.top == nullptr) return;
    Node* otherCur = other.top;
    Node* thisCur = new Node(otherCur->data);
    top = thisCur;
    while (otherCur->next != nullptr) {
        otherCur = otherCur->next;
        thisCur->next = new Node(otherCur->data);
        thisCur = thisCur->next;
    }
}

IntStack& IntStack::operator=(const IntStack& other) {
    if (this != &other) {
        clear();
        if (other.top == nullptr) return *this;
        Node* otherCur = other.top;
        Node* thisCur = new Node(otherCur->data);
        top = thisCur;
        while (otherCur->next != nullptr) {
            otherCur = otherCur->next;
            thisCur->next = new Node(otherCur->data);
            thisCur = thisCur->next;
        }
    }
    return *this;
}

IntStack::~IntStack() { clear(); }

// --- ОСНОВНЫЕ МЕТОДЫ ---
bool IntStack::isEmpty() const { return top == nullptr; }

void IntStack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

int IntStack::pop() {
    if (isEmpty()) throw runtime_error("Стек пуст");
    int val = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return val;
}

int IntStack::peek() const {
    if (isEmpty()) throw runtime_error("Стек пуст");
    return top->data;
}

void IntStack::clear() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

// --- РАБОТА С ФАЙЛАМИ И ВЫВОД ---
void IntStack::print(const string& title) const {
    if (isEmpty()) {
        cout << title << " пуст.\n";
        return;
    }
    cout << title << " (от вершины): ";
    Node* cur = top;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

void IntStack::saveToFile(const string& filename) const {
    ofstream out(filename);
    if (!out.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << filename << " для записи.\n";
        return;
    }
    Node* cur = top;
    while (cur) {
        out << cur->data << "\n";
        cur = cur->next;
    }
    out.close();
    cout << "Стек сохранен в файл " << filename << "\n";
}

void IntStack::loadFromFile(const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << filename << " для чтения.\n";
        return;
    }
    clear(); // очищаем текущий стек
    int val;
    while (in >> val) {
        push(val);
    }
    in.close();
    cout << "Стек загружен из файла " << filename << "\n";
}