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

    static Node *secondLargest(Node node) {
        Node *prev_node = nullptr;
        Node *curr_node = &node;
        if (curr_node == nullptr) {
            return prev_node;
        }
        while (curr_node->right != nullptr) {
            prev_node = curr_node;
            curr_node = curr_node->right;
        }
        if (curr_node->left != nullptr) {
            curr_node = curr_node->left;
            while (curr_node->right != nullptr) {
                curr_node = curr_node->right;
            }
            prev_node = curr_node;
        }
        return prev_node;
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
    std::cout << Tree::secondLargest(*t->root)->data;
    delete t;
    return 0;
}
