#pragma once
#include <string>

class IntStack {
private:
    // Внутренняя структура узла скрыта от внешнего мира!
    struct Node {
        int data;
        Node* next;
        Node(int d) : data(d), next(nullptr) {}
    };

    Node* top; // указатель на вершину стека

public:
    // --- КОНСТРУКТОРЫ И ДЕСТРУКТОР ---
    IntStack();
    IntStack(const IntStack& other);            // Конструктор копирования
    IntStack& operator=(const IntStack& other); // Оператор присваивания
    ~IntStack();                                // Деструктор

    // --- ОСНОВНЫЕ МЕТОДЫ ---
    bool isEmpty() const;
    void push(int value);
    int pop();
    int peek() const;
    void clear();

    // Вывод и работа с файлами
    void print(const std::string& title) const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};