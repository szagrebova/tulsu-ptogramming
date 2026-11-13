#pragma once
#include <iostream>
#include <iomanip> // Для setw

// Узел AVL-дерева
struct Node {
    int key;
    int value;
    int height;
    Node* left;
    Node* right;

    Node(int k, int v)
        : key(k), value(v), height(1), left(nullptr), right(nullptr) {
    }
};

// Класс AVL-дерева
class AVLTree {
private:
    Node* root;

    // Вспомогательные методы (скрыты от пользователя)
    int height(Node* p);
    int balanceFactor(Node* p);
    void fixHeight(Node* p);
    Node* rotateRight(Node* p);
    Node* rotateLeft(Node* q);
    Node* balance(Node* p);
    Node* insert(Node* p, int k, int v);
    void printInOrder(Node* p);
    void printTree(Node* p, int indent = 0);
    int countLevel(Node* p, int target, int current = 1);

public:
    // Конструктор
    AVLTree();

    // Публичный интерфейс
    void insert(int k, int v);
    void printInOrder();
    void printTree();
    int countLevel(int level);
};