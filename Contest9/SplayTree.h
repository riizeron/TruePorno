//
// Created by Вячеслав on 15.11.2021.
//

#ifndef CONTEST9_SPLAYTREE_H
#define CONTEST9_SPLAYTREE_H


struct Node {
public:
    int key;
    Node *parent;
    Node *right;
    Node *left;

    Node(int key, Node *parent) {
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = parent;
    }
};

class SplayTree {
public:
    SplayTree();

    ~SplayTree() {
        destroyNode(root_);
    }

    void insert(int);

    [[nodiscard]] Node *find(int) const;

    int splay(Node *);

    [[nodiscard]] int getHeight() const {
        return height(root_) - 1;
    }

private:
    Node *root_;

    Node *leftRotation(Node *node);

    Node *rightRotation(Node *node);

    Node *zigZag(Node *node);

    Node *zagZig(Node *node);

    Node *zigZig(Node *node);

    Node *zagZag(Node *node);

    static void destroyNode(Node *node) {
        if (node) {
            destroyNode(node->left);
            destroyNode(node->right);
            delete node;
        }
    }
    int height(Node *node) const;
};


#endif //CONTEST9_SPLAYTREE_H
