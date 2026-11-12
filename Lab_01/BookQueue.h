#pragma once
#include "Book.h"

class BookQueue {
private:
    struct Node {
        Book data;
        Node* next;
        Node* prev;
        Node(const Book& b) : data(b), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;

public:
    BookQueue();
    ~BookQueue();
    bool isEmpty() const;
    void pushBack(const Book& b);
    Book popFront();
    const Book& front() const;
    void print() const;
    void clear();
};