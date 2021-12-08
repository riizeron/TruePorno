#include <iostream>

class Node {
public:
    int data;
    Node *right;
    Node *left;

    explicit Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Tree {
public:
    Node *root;

    Tree() {
        root = nullptr;
    }

    ~Tree() {
        destroyNode(root);
    }

    void insert(int x) {
        root = doInsert(root, x);
    }

    int height(Node *tree) {
        if (tree == nullptr) {
            return 0;
        }
        return height(tree->left) > height(tree->right) ? height(tree->left) + 1
                                                        : height(tree->right) + 1;
    }

private:
    Node *doInsert(Node *node, int x) {
        if (node == nullptr) {
            return new Node(x);
        }
        if (x < node->data) {
            node->left = doInsert(node->left, x);
        } else if (x > node->data) {
            node->right = doInsert(node->right, x);
        }
        return node;
    }

    void destroyNode(Node *node) {
        if (node) {
            destroyNode(node->left);
            destroyNode(node->right);
            delete node;
        }
    }
};

int main() {
    Tree *t = new Tree();
    int n;
    std::cin >> n;
    while (n != 0) {
        t->insert(n);
        std::cin >> n;
    }
    std::cout << t->height(t->root);
    delete t;
    return 0;
}

