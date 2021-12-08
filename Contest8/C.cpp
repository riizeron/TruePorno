#include <iostream>

class Node {
public:
    int data;
    int repeat_count = 0;
    Node *right;
    Node *left;

    explicit Node(int data) {
        this->data = data;
        repeat_count++;
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

    void insert(int data) {
        root = doInsert(root, data);
    }

    void printAscendingWithRepeats() {
        printAscendingWithRepeats(root);
    }

private:
    Node *doInsert(Node *node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = doInsert(node->left, data);
        } else if (data > node->data) {
            node->right = doInsert(node->right, data);
        } else {
            node->repeat_count++;
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

    void printAscendingWithRepeats(Node *tree) {
        if (tree == nullptr) {
            return;
        }
        printAscendingWithRepeats(tree->left);
        std::cout << tree->data << " " << tree->repeat_count << std::endl;
        printAscendingWithRepeats(tree->right);
    }
};

int main() {
    Tree *t = new Tree();
    int data;
    std::cin >> data;
    while (data != 0) {
        t->insert(data);
        std::cin >> data;
    }
    t->printAscendingWithRepeats();
    delete t;
    return 0;
}


