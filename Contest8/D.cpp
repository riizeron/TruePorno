#include <iostream>

template <class T>


class Node {
    int key;
    int height;
    bool isRed = false;

    Node * left;
    Node * right;
    Node * parent;
    explicit Node(bool IS_RED = false) {
        this->left = this->right = nullptr;
        this->color = IS_RED;
    }
    explicit Node(int k, bool IS_RED = false) {
        this->key = k;
        this->left = this->right = nullptr;
        this->height = 1;
        this->color = IS_RED;
    }
    explicit Node(int k, Node * parent, bool IS_RED = false) {
        this->key = k;
        this->left = this->right = nullptr;
        this->height = 1;
        this->color = IS_RED;
    }
    int treeSize() {
        int szL = 0, szR = 0;
        if (left != nullptr)
            szL = left->treeSize();
        if (right != nullptr)
            szR = right->treeSize();
        return szL + szR + 1;
    }
    /*int maxLen() {
        int szL = 0, szR = 0;
        if (left != nullptr)
            szL = left->maxLen();
        if (right != nullptr)
            szR = right->maxLen();
        int sz = std::to_string(key).size();
        return std::max(sz, std::max(szL, szR));
    }*/
};


class RBTree {


};

