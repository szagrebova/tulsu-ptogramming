#include "Fraction.h"
#include "InputUtils.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>

using namespace std;

// Вспомогательная функция НОД (скрыта внутри этого файла)
static int gcd(int a, int b) {
    a = abs(a); b = abs(b);
    while (b) { int t = b; b = a % b; a = t; }
    return a ? a : 1;
}

void Fraction::reduce() {
    if (n < 0) { m = -m; n = -n; }
    int g = gcd(m, n);
    m /= g;
    n /= g;
}

// --- КОНСТРУКТОРЫ ---
Fraction::Fraction() : m(0), n(1) {}
Fraction::Fraction(int m_) : m(m_), n(1) {}

Fraction::Fraction(int m_, int n_) {
    if (n_ == 0) throw invalid_argument("Знаменатель = 0");
    m = m_; n = n_;
    reduce();
}

Fraction::Fraction(const Fraction& o) : m(o.m), n(o.n) {}

// --- SET ---
void Fraction::setM(int m_) { m = m_; reduce(); }
void Fraction::setN(int n_) {
    if (n_ == 0) throw invalid_argument("Знаменатель = 0");
    n = n_; reduce();
}
void Fraction::set(int m_, int n_) {
    if (n_ == 0) throw invalid_argument("Знаменатель = 0");
    m = m_; n = n_; reduce();
}
void Fraction::setFromInput() {
    m = readInt(" Числитель: ");
    n = readNonZeroInt(" Знаменатель: ");
    reduce();
}

// --- GET ---
int Fraction::getM() const { return m; }
int Fraction::getN() const { return n; }
double Fraction::getValue() const { return (double)m / n; }

// --- SHOW ---
void Fraction::show() const { cout << m << "/" << n; }
void Fraction::showValue() const { cout << m << "/" << n << " = " << getValue(); }

// --- АРИФМЕТИКА ---
Fraction Fraction::add(const Fraction& o) const { return Fraction(m * o.n + o.m * n, n * o.n); }
Fraction Fraction::sub(const Fraction& o) const { return Fraction(m * o.n - o.m * n, n * o.n); }
Fraction Fraction::mul(const Fraction& o) const { return Fraction(m * o.m, n * o.n); }
Fraction Fraction::div(const Fraction& o) const {
    if (o.m == 0) throw invalid_argument("Деление на 0");
    return Fraction(m * o.n, n * o.m);
}

// --- ПЕРЕГРУЗКА ---
Fraction Fraction::operator+(const Fraction& o) const { return add(o); }
Fraction Fraction::operator-(const Fraction& o) const { return sub(o); }
Fraction Fraction::operator*(const Fraction& o) const { return mul(o); }
Fraction Fraction::operator/(const Fraction& o) const { return div(o); }

Fraction& Fraction::operator=(const Fraction& o) {
    if (this != &o) { m = o.m; n = o.n; }
    return *this;
}

bool Fraction::operator==(const Fraction& o) const { return m * o.n == o.m * n; }
bool Fraction::operator!=(const Fraction& o) const { return !(*this == o); }
bool Fraction::operator< (const Fraction& o) const { return m * o.n < o.m * n; }
bool Fraction::operator> (const Fraction& o) const { return m * o.n > o.m * n; }
bool Fraction::operator<=(const Fraction& o) const { return !(*this > o); }
bool Fraction::operator>=(const Fraction& o) const { return !(*this < o); }