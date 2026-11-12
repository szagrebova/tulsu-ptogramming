#include "BookStack.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

BookStack::BookStack() : top(nullptr) {}
BookStack::~BookStack() { clear(); }

bool BookStack::isEmpty() const { return top == nullptr; }

void BookStack::push(const Book& b) {
    Node* newBook = new Node(b);
    newBook->next = top;
    top = newBook;
}

Book BookStack::pop() {
    if (!top) throw runtime_error("Стек пуст");
    Book b = top->data;
    Node* delBook = top;
    top = top->next;
    delete delBook;
    return b;
}

const Book& BookStack::peek() const {
    if (!top) throw runtime_error("Стек пуст");
    return top->data;
}

void BookStack::print() const {
    if (isEmpty()) {
        cout << "Нет сведений о книгах в данной библиотеке.\n";
        return;
    }
    vector<Book> books;
    Node* cur = top;
    while (cur) {
        books.push_back(cur->data);
        cur = cur->next;
    }
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.year < b.year;
        });
    for (const Book& b : books) printBook(b);
}

void BookStack::clear() {
    while (top) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}