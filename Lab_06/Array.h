#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <type_traits> // Для проверки типов на этапе компиляции

template <typename T>
class Array {
private:
    T* data;
    int size;

public:
    // ---------- КОНСТРУКТОРЫ И ДЕСТРУКТОР ----------
    Array(int n = 0) {
        size = n;
        data = (n > 0) ? new T[n] : nullptr;
    }

    Array(const Array& other) {
        size = other.size;
        data = (size > 0) ? new T[size] : nullptr;
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = (size > 0) ? new T[size] : nullptr;
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~Array() {
        delete[] data;
    }

    // ---------- ОСНОВНЫЕ МЕТОДЫ ----------
    int getSize() const { return size; }

    T& operator[](int index) {
        if (index < 0 || index >= size) throw std::out_of_range("Индекс вне границ массива");
        return data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) throw std::out_of_range("Индекс вне границ массива");
        return data[index];
    }

    // Заполнение с клавиатуры (с поддержкой строк с пробелами)
    void inputFromKeyboard() {
        for (int i = 0; i < size; ++i) {
            std::cout << "Элемент [" << i << "]: ";

            // Если T - это строка, используем getline
            if constexpr (std::is_same_v<T, std::string>) {
                // std::ws удаляет лишние пробелы/переносы строк из буфера перед чтением
                std::getline(std::cin >> std::ws, data[i]);
            }
            // Для чисел используем обычный cin >>
            else {
                std::cin >> data[i];
            }
        }

        // Очищаем буфер после ввода чисел (для строк getline уже все съел)
        if constexpr (!std::is_same_v<T, std::string>) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }

    // Вывод на экран (через точку с запятой)
    void print(const std::string& title) const {
        std::cout << title << ": ";
        if (size == 0) {
            std::cout << "(пусто)\n";
            return;
        }
        for (int i = 0; i < size; ++i) {
            std::cout << data[i];
            // Ставим точку с запятой, если это не последний элемент
            if (i < size - 1) {
                std::cout << "; ";
            }
        }
        std::cout << "\n";
    }

    // ---------- МЕТОДЫ СОРТИРОВКИ ----------
    void sortBubble() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }

    void sortSelection() {
        for (int i = 0; i < size - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < size; ++j) {
                if (data[j] < data[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                std::swap(data[i], data[minIndex]);
            }
        }
    }
};