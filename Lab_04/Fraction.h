#pragma once

class Fraction {
private:
    int m;   // числитель
    int n;   // знаменатель (не 0)

    // Приватный метод сокращения
    void reduce();

public:
    // --- КОНСТРУКТОРЫ ---
    Fraction();
    Fraction(int m_);
    Fraction(int m_, int n_);
    Fraction(const Fraction& o);

    // --- SET ---
    void setM(int m_);
    void setN(int n_);
    void set(int m_, int n_);
    void setFromInput();

    // --- GET ---
    int getM() const;
    int getN() const;
    double getValue() const;

    // --- SHOW ---
    void show() const;
    void showValue() const;

    // --- АРИФМЕТИКА ---
    Fraction add(const Fraction& o) const;
    Fraction sub(const Fraction& o) const;
    Fraction mul(const Fraction& o) const;
    Fraction div(const Fraction& o) const;

    // --- ПЕРЕГРУЗКА ОПЕРАЦИЙ ---
    Fraction operator+(const Fraction& o) const;
    Fraction operator-(const Fraction& o) const;
    Fraction operator*(const Fraction& o) const;
    Fraction operator/(const Fraction& o) const;

    Fraction& operator=(const Fraction& o);

    // Операции отношения
    bool operator==(const Fraction& o) const;
    bool operator!=(const Fraction& o) const;
    bool operator< (const Fraction& o) const;
    bool operator> (const Fraction& o) const;
    bool operator<=(const Fraction& o) const;
    bool operator>=(const Fraction& o) const;
};