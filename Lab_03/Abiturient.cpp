#include "Abiturient.h"
#include "InputUtils.h"

using namespace std;

Abiturient::Abiturient() {
    surname = name = patronymic = address = "";
    for (int i = 0; i < 4; ++i) grades[i] = 0;
}

void Abiturient::setSurname(const string& s) { surname = s; }
void Abiturient::setName(const string& s) { name = s; }
void Abiturient::setPatronymic(const string& s) { patronymic = s; }
void Abiturient::setAddress(const string& s) { address = s; }

void Abiturient::setGrade(int i, int g) {
    if (i >= 0 && i < 4 && g >= 2 && g <= 5) grades[i] = g;
}

void Abiturient::setAll() {
    surname = readLine("Фамилия: ");
    name = readLine("Имя: ");
    patronymic = readLine("Отчество: ");
    address = readLine("Адрес: ");
    cout << "Оценки (2..5) по 4 предметам:\n";
    for (int i = 0; i < 4; ++i) {
        grades[i] = readIntInRange(" Предмет " + to_string(i + 1) + ": ", 2, 5);
    }
}

string Abiturient::getSurname() const { return surname; }
string Abiturient::getName() const { return name; }
string Abiturient::getPatronymic() const { return patronymic; }
string Abiturient::getAddress() const { return address; }

int Abiturient::getGrade(int i) const {
    return (i >= 0 && i < 4) ? grades[i] : 0;
}

int Abiturient::getSum() const {
    int s = 0;
    for (int i = 0; i < 4; ++i) s += grades[i];
    return s;
}

bool Abiturient::hasBadGrades() const {
    for (int i = 0; i < 4; ++i)
        if (grades[i] < 3) return true;
    return false;
}

void Abiturient::show() const {
    cout << "ФИО: " << surname << " " << name << " " << patronymic << "\n"
        << "Адрес: " << address << "\n"
        << "Оценки: ";
    for (int i = 0; i < 4; ++i) cout << grades[i] << " ";
    cout << "| Сумма: " << getSum() << "\n";
}