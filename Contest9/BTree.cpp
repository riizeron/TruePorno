//
// Created by Вячеслав on 16.11.2021.
//

#include <cstdint>
#include "BTree.h"

struct Node { ;
    bool isLeaf;
    int t;
    bool is_full_of_keys;
    bool is_full_of_children;
    int keys_amount;
    int children_amount;
    int *keys;
    Node **children;

    explicit Node(int t, bool isLeaf) {
        this->t = t;
        this->keys = new int[2 * t - 1];
        children = new Node *[2 * t];
        this->isLeaf = isLeaf;
        is_full_of_children = false;
        is_full_of_keys = false;
        keys_amount = 0;
        children_amount = 0;
    }

    void addKey(int key);

    void split(int i, Node *child);

    void insertN(int key);

    void addChild(Node *child);

    int sumCounter(int counter) const;

    int sizeCounter(int counter) const;

    void deleteNode() const;
};

void Node::addChild(Node *child) {
    if (!is_full_of_children) {
        children[children_amount++] = child;
        if (children_amount == 2 * t) {
            is_full_of_children = true;
        }
        this->isLeaf = false;
    }
}

void Node::split(int i, Node *child) {
    Node *pNode = new Node(child->t, child->isLeaf);

    for (int j = 0; j < t - 1; j++) {
        pNode->keys[j] = child->keys[j + t];
        pNode->keys_amount++;
    }

    if (!child->isLeaf) {
        for (int j = 0; j < t; j++) {
            pNode->children[j] = child->children[j + t];
            pNode->children_amount++;
        }
    }

    child->children_amount = t - 1;

    for (int j = children_amount; j >= i + 1; j--) {
        children[j + 1] = children[j];
    }

    children[i + 1] = pNode;

    for (int j = children_amount - 1; j >= i; j--) {
        keys[j + 1] = keys[j];
    }
    keys[i] = child->keys[t - 1];
    children_amount++;
}

void Node::deleteNode() const {
    int i;
    for (i = 0; i < keys_amount; i++) {
        if (!isLeaf) {
            children[i]->deleteNode();
        }
        delete children[i];
    }
    if (!isLeaf) {
        children[i]->deleteNode();
    }
}

int Node::sumCounter(int counter) const {
    int i;
    for (i = 0; i < keys_amount; i++) {
        if (!isLeaf) {
            children[i]->sumCounter(counter);
        }
        for (int j = 0; j < keys_amount; j++) {
            counter += keys[j];
        }
    }
    if (!isLeaf) {
        children[i]->sumCounter(counter);
    }
    return counter;
}

int Node::sizeCounter(int counter) const {
    int i;
    for (i = 0; i < keys_amount; i++) {
        if (!isLeaf) {
            children[i]->sizeCounter(counter);
        }
        counter++;
    }
    if (!isLeaf) {
        children[i]->sizeCounter(counter);
    }
    return counter;
}

void Node::insertN(int key) {
    int right_index = keys_amount - 1;
    if (isLeaf) {
        while (right_index >= 0 && keys[right_index] > key) {
            keys[right_index + 1] = keys[right_index];
            right_index--;
        }

        keys[right_index + 1] = key;
        keys_amount++;
    } else {
        while (right_index >= 0 && keys[right_index] > key)
            right_index--;

        if (children[right_index + 1]->children_amount == 2 * t - 1) {
            split(right_index + 1, children[right_index + 1]);

            if (keys[right_index + 1] < key)
                right_index++;
        }
        children[right_index + 1]->insertN(key);
    }
}

void Node::addKey(int key) {
    if (!is_full_of_keys) {
        keys[keys_amount] = key;
        keys_amount++;
        if (keys_amount == 2 * t - 1) {
            is_full_of_keys = true;
        }
    }
}

class BTree {
public:
    explicit BTree(int);

    ~BTree();

    void insert(int);

    [[nodiscard]] size_t size() const;

    [[nodiscard]] int64_t sum() const;

    int t;

private:
    Node *root_;
};

BTree::BTree(int exp) {
    this->t = exp;
    root_ = nullptr;
}

BTree::~BTree() {
    root_->deleteNode();
}

void BTree::insert(int key) {
    if (!root_) {
        root_ = new Node(t, true);
        root_->addKey(key);
        return;
    }
    if (root_->is_full_of_keys) {
        Node *newNode = new Node(t, false);
        newNode->addChild(root_);
        newNode->split(0, root_);
        int i = 0;
        if (newNode->keys[0] < key) {
            i++;
        }
        newNode->children[i]->insertN(key);
        root_ = newNode;
        return;
    }
    root_->insertN(key);
}

size_t BTree::size() const {
    return root_->sizeCounter(0);
}

int64_t BTree::sum() const {
    return root_->sumCounter(0);
}

