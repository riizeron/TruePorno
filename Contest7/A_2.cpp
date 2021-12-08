#include <iostream>

class MyNode {
public:
    explicit MyNode(int key) {
        this->key = key;
    }

    int key;
    MyNode *left = nullptr;
    MyNode *right = nullptr;
};

class MyTree {
public:
    MyTree() : root(nullptr) {
    }

    MyNode *root;

    ~MyTree() {
        destroyNode(root);
    }

    int height() {
        height(root);
        /*if (root == nullptr) {
            return 0;
        }
        return height(root->left) > height(root->right) ? height(root->left) + 1
                                                        : height(root->right) + 1;*/
    }

    void insert(int x) {
        MyNode **cur = &root;
        while (*cur) {
            MyNode &node = **cur;
            if (x < node.key) {
                cur = &node.left;
            } else if (x > node.key) {
                cur = &node.right;
            } else {
                return;
            }
        }
        *cur = new MyNode(x);
    }

private:
    static void destroyNode(MyNode *node) {
        if (node) {
            destroyNode(node->left);
            destroyNode(node->right);
            delete node;
        }
    }

    int height(const MyNode *item) {
        int l, r, h = 0;
        if (item != nullptr) {
            l = height(item->left);
            r = height(item->right);
            h = ((l > r) ? l : r) + 1;
        }
        return h;
    }
};

int main() {
    auto *t = new MyTree();
    int n;
    std::cin >> n;
    while (n != 0) {
        t->insert(n);
        std::cin >> n;
    }
    std::cout << t->height();
    delete t;
    return 0;
}


