#include <iostream>

class Node {
public:
    int data;
    Node *right;
    Node *left;

    explicit Node(int data) {
        this->data = data;
        left = right = nullptr;
    }

    bool isEmpty() {
        return (right == nullptr && left == nullptr);
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
    bool isBalanced(Node *tree) {
        return tree==nullptr || isBalanced(tree->left) && isBalanced(tree->right) &&
                                      height(tree->left) - height(tree->right) <= 1 &&
                                      height(tree->left) - height(tree->right) >= -1;
    }

    int height(Node *tree) {
        if (tree == nullptr) {
            return 0;
        }
        return height(tree->left) > height(tree->right) ? height(tree->left) + 1
                                                        : height(tree->right) + 1;
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

/*int main() {
    Tree *t = new Tree();
    int data;
    std::cin >> data;
    while (data != 0) {
        t->insert(data);
        std::cin >> data;
    }
    if(t->isBalanced(t->root)){
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    delete t;
    return 0;
}*/
