#include "AVLTree.h"

using namespace std;

// Конструктор
AVLTree::AVLTree() : root(nullptr) {}

// Высота узла (nullptr = 0)
int AVLTree::height(Node* p) {
    return p ? p->height : 0;
}

// Разность высот правого и левого поддеревьев
int AVLTree::balanceFactor(Node* p) {
    return height(p->right) - height(p->left);
}

// Пересчёт высоты узла
void AVLTree::fixHeight(Node* p) {
    int hl = height(p->left);
    int hr = height(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
}

// Малый правый поворот
Node* AVLTree::rotateRight(Node* p) {
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixHeight(p);
    fixHeight(q);
    return q;
}

// Малый левый поворот
Node* AVLTree::rotateLeft(Node* q) {
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixHeight(q);
    fixHeight(p);
    return p;
}

// Балансировка узла
Node* AVLTree::balance(Node* p) {
    fixHeight(p);

    // Перевес справа
    if (balanceFactor(p) == 2) {
        if (balanceFactor(p->right) < 0)
            p->right = rotateRight(p->right);
        return rotateLeft(p);
    }

    // Перевес слева
    if (balanceFactor(p) == -2) {
        if (balanceFactor(p->left) > 0)
            p->left = rotateLeft(p->left);
        return rotateRight(p);
    }

    return p; // узел сбалансирован
}

// Рекурсивная вставка
Node* AVLTree::insert(Node* p, int k, int v) {
    if (!p) return new Node(k, v);

    if (k < p->key)
        p->left = insert(p->left, k, v);
    else if (k > p->key)
        p->right = insert(p->right, k, v);
    else
        return p; // дубликат не добавляем

    return balance(p);
}

// Симметричный обход
void AVLTree::printInOrder(Node* p) {
    if (!p) return;
    printInOrder(p->left);
    cout << "(" << p->key << ":" << p->value << ")\n";
    printInOrder(p->right);
}

// Вывод структуры дерева (повёрнуто на 90°)
void AVLTree::printTree(Node* p, int indent) {
    if (!p) return;
    printTree(p->right, indent + 4);
    if (indent) cout << setw(indent) << ' ';
    cout << p->key << ":" << p->value << "\n";
    printTree(p->left, indent + 4);
}

// Подсчёт узлов на заданном уровне
int AVLTree::countLevel(Node* p, int target, int current) {
    if (!p) return 0;
    if (current == target) return 1;
    if (current > target) return 0;
    return countLevel(p->left, target, current + 1) +
        countLevel(p->right, target, current + 1);
}

// --- Обертки для публичных методов ---

void AVLTree::insert(int k, int v) {
    root = insert(root, k, v);
}

void AVLTree::printInOrder() {
    printInOrder(root);
    cout << '\n';
}

void AVLTree::printTree() {
    printTree(root);
}

int AVLTree::countLevel(int level) {
    return countLevel(root, level, 1);
}