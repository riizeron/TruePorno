//
// Created by Вячеслав on 15.11.2021.
//

#include <algorithm>
#include "SplayTree.h"

Node *SplayTree::leftRotation(Node *node) {
    Node *tempest = node->right;
    if (tempest->left != nullptr) {
        tempest->left->parent = node;
    }
    node->right = tempest->left;
    tempest->left = node;
    if (node->parent != nullptr) {
        if (node->parent->right == node) {
            node->parent->right = tempest;
        } else if (node->parent->left) {
            node->parent->left = tempest;
        }
    } else {
        root_ = tempest;
    }
    tempest->parent = node->parent;
    node->parent = tempest;
    return tempest;
}

Node *SplayTree::rightRotation(Node *node) {
    Node *tempest = node->left;
    if (tempest->right != nullptr) {
        tempest->right->parent = node;
    }
    node->left = tempest->right;
    tempest->right = node;
    if (node->parent != nullptr) {
        if (node->parent->right == node) {
            node->parent->right = tempest;
        } else if (node->parent->left) {
            node->parent->left = tempest;
        }
    } else {
        root_ = tempest;
    }
    tempest->parent = node->parent;
    node->parent = tempest;
    return tempest;
}

void SplayTree::insert(int key) {
    Node **cur = &root_;
    Node *prev_node = nullptr;
    while (*cur) {
        Node &node = **cur;
        prev_node = &node;
        if (key < node.key) {
            cur = &node.left;
        } else if (key > node.key) {
            cur = &node.right;
        } else {
            return;
        }
    }
    *cur = new Node(key, prev_node);
}

Node *SplayTree::find(int key) const {
    Node *cur = root_;
    while (cur) {
        Node *node = cur;
        if (key < node->key) {
            cur = node->left;
        } else if (key > node->key) {
            cur = node->right;
        } else {
            return node;
        }
    }
    return nullptr;
}

SplayTree::SplayTree() {
    root_ = nullptr;
}

int SplayTree::height(Node *node) const {
    if (node == nullptr) {
        return 0;
    }
    return std::max(height(node->left), height(node->right)) + 1;
}

int SplayTree::splay(Node *n) {
    int counter = 0;
    while (n->parent != nullptr) {
        if (n == n->parent->left) {
            if (n->parent->parent == nullptr) {
                n = rightRotation(n->parent);
                counter++;
            } else if (n->parent == n->parent->parent->left) {
                n = zagZag(n);
                counter += 2;
            } else {
                n = zagZig(n);
                counter++;
            }
        } else {
            if (n->parent->parent == nullptr) {
                n = leftRotation(n->parent);
                counter++;
            } else if (n->parent == n->parent->parent->right) {
                n = zigZig(n);
                counter += 2;
            } else {
                n = zigZag(n);
                counter++;
            }
        }
    }
    return counter;
}

Node *SplayTree::zigZag(Node *node) {
    node = leftRotation(node->parent);
    node = rightRotation(node->parent);
    return node;
}

Node *SplayTree::zagZig(Node *node) {
    node = rightRotation(node->parent);
    node = leftRotation(node->parent);
    return node;
}

Node *SplayTree::zigZig(Node *node) {
    node->parent = leftRotation(node->parent->parent);
    node = leftRotation(node->parent);
    return node;
}

Node *SplayTree::zagZag(Node *node) {
    node->parent = rightRotation(node->parent->parent);
    node = rightRotation(node->parent);
    return node;
}
