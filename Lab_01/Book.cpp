#include "Book.h"
#include "Utils.h"
#include <iostream>

using namespace std;

Book inputBook() {
    Book b;
    b.udk = readNonEmptyLine("Номер УДК: "); // Используем строку!
    b.author = readNonEmptyLine("Автор (Фамилия И.О.): ");
    b.title = readNonEmptyLine("Название: ");
    b.year = readPositiveInt("Год издания: ");
    b.copies = readPositiveInt("Количество экземпляров: ");
    return b;
}

void printBook(const Book& b) {
    cout << "УДК: " << b.udk
        << " | Автор: " << b.author
        << " | Название: " << b.title
        << " | Год: " << b.year
        << " | Экз.: " << b.copies << '\n';
}