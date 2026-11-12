#include "BookQueue.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

BookQueue::BookQueue() : head(nullptr), tail(nullptr) {}
BookQueue::~BookQueue() { clear(); }

bool BookQueue::isEmpty() const { return head == nullptr; }

void BookQueue::pushBack(const Book& b) {
    Node* newNode = new Node(b);
    if (tail) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else {
        head = tail = newNode;
    }
}

Book BookQueue::popFront() {
    if (isEmpty()) throw runtime_error("Очередь пуста! Нечего удалять");
    Book b = head->data;
    Node* delBook = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete delBook;
    return b;
}

const Book& BookQueue::front() const {
    if (isEmpty()) throw runtime_error("Очередь пуста!");
    return head->data;
}

void BookQueue::print() const {
    if (isEmpty()) {
        cout << "Нет сведений о книгах в данной библиотеке.\n";
        return;
    }
    vector<Book> books;
    Node* cur = head;
    while (cur) {
        books.push_back(cur->data);
        cur = cur->next;
    }
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.year < b.year;
        });
    for (const Book& b : books) printBook(b);
}

void BookQueue::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}