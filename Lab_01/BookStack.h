#pragma once
#include "Book.h"

class BookStack {
private:
    struct Node {
        Book data;
        Node* next;
        Node(const Book& b) : data(b), next(nullptr) {}
    };
    Node* top;

public:
    BookStack();
    ~BookStack();
    bool isEmpty() const;
    void push(const Book& b);
    Book pop();
    const Book& peek() const;
    void print() const;
    void clear();
};