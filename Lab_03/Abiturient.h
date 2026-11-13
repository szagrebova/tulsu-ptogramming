#pragma once
#include <string>
#include <iostream>

class Abiturient {
private:
    std::string surname;
    std::string name;
    std::string patronymic;
    std::string address;
    int grades[4];

public:
    // Конструктор
    Abiturient();

    // set-методы
    void setSurname(const std::string& s);
    void setName(const std::string& s);
    void setPatronymic(const std::string& s);
    void setAddress(const std::string& s);
    void setGrade(int i, int g);
    void setAll(); // Ввод всех данных сразу

    // get-методы
    std::string getSurname() const;
    std::string getName() const;
    std::string getPatronymic() const;
    std::string getAddress() const;
    int getGrade(int i) const;
    int getSum() const;
    bool hasBadGrades() const;

    // Вывод
    void show() const;
};