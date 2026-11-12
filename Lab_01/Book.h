#pragma once
#include <string>

struct Book {
    std::string udk;
    std::string author;
    std::string title;
    int year;
    int copies;
};

Book inputBook();
void printBook(const Book& b);