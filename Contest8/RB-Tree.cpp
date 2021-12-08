#include <iostream>

class Node {
public:
    int key;
    int num;
    Node *right;
    Node *left;
    bool isRed;

    explicit Node(int num, int key, bool isRed) {
        this->num = num;
        this->key = key;
        this->isRed = isRed;
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

    void insert(int num, int key, bool isRed) {
        root = doInsert(root, num, key, isRed);
    }

    int height(Node *tree) {
        if (tree == nullptr) {
            return 0;
        }
        return height(tree->left) > height(tree->right) ? height(tree->left) + 1
                                                        : height(tree->right) + 1;
    }

private:
    Node *doInsert(Node *node, int num, int key, bool isRed) {
        if (node == nullptr) {
            return new Node(num, key, isRed);
        }
        if (key < node->key) {
            node->left = doInsert(node->left, num, key, isRed);
        } else if (key > node->key) {
            node->right = doInsert(node->right, num, key, isRed);
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
    int N, rootNum;
    bool isRed = false;
    std::string color;
    int num, key, left, right;
    std::cin >> N >> rootNum;
    Node **nodes = new Node *[N];
    for (int i = 0; i < N; i++) {
        std::cin >> num >> key >> left >> right;
        std::cin >> color;
        if (color == "red") {
            isRed = true;
        }
        nodes[i] = new Node(num, key, isRed);
    }


    return 0;
}
