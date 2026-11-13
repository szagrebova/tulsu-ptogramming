#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdexcept>

using namespace std;

// ==========================================
// БАЗОВЫЙ КЛАСС 1: Человек
// ==========================================
class Human {
protected:
    string fullName;

public:
    Human(string name) : fullName(name) {}
    virtual ~Human() {}

    virtual void print() const = 0;
};

// ==========================================
// БАЗОВЫЙ КЛАСС 2: Данные для общежития
// ==========================================
class DormitoryData {
protected:
    double gpa;
    double income;

public:
    DormitoryData(double g, double inc) : gpa(g), income(inc) {
        if (gpa < 2.0 || gpa > 5.0) throw invalid_argument("Средний балл должен быть от 2.0 до 5.0!");
        if (income < 0) throw invalid_argument("Доход не может быть отрицательным!");
    }
    virtual ~DormitoryData() {}

    double getGpa() const { return gpa; }
    double getIncome() const { return income; }
};

// ==========================================
// ПРОИЗВОДНЫЙ КЛАСС: Студент (Множественное наследование)
// ==========================================
class Student : public Human, public DormitoryData {
private:
    string group;

public:
    Student(string name, string grp, double g, double inc)
        : Human(name), DormitoryData(g, inc), group(grp)
    {
    }

    ~Student() override {}

    void print() const override {
        cout << "ФИО: " << fullName << " | Группа: " << group
            << " | Балл: " << gpa << " | Доход: " << income << endl;
    }

    // Геттеры для вывода в интерфейс (ListBox)
    string getName() const { return fullName; }
    string getGroup() const { return group; }

    // Friend-функция
    friend void Run(vector<Student*>& students, const string& filename, double minSalary);
};

// ==========================================
// FRIEND-ФУНКЦИЯ Run()
// ==========================================
void Run(vector<Student*>& students, const string& filename, double minSalary) {
    sort(students.begin(), students.end(), [minSalary](Student* a, Student* b) {
        bool aPoor = a->getIncome() < (minSalary * 2);
        bool bPoor = b->getIncome() < (minSalary * 2);
        if (aPoor != bPoor) return aPoor > bPoor;
        return a->getGpa() > b->getGpa();
        });

    ofstream out(filename);
    if (!out.is_open()) throw runtime_error("Ошибка открытия файла!");

    cout << "\n=== ОЧЕРЕДЬ НА ОБЩЕЖИТИЕ ===\n";
    out << "=== ОЧЕРЕДЬ НА ОБЩЕЖИТИЕ ===\n";

    for (Student* s : students) {
        cout << s->fullName << " | Группа: " << s->group
            << " | Балл: " << s->gpa << " | Доход: " << s->income << "\n";
        out << s->fullName << " | Группа: " << s->group
            << " | Балл: " << s->gpa << " | Доход: " << s->income << "\n";
    }
    out.close();
}