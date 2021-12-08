//
// Created by Вячеслав on 02.12.2021.
//

#ifndef CONTEST10_HASHTABLE_H
#define CONTEST10_HASHTABLE_H


#include <iostream>

template <class KeyType, class ValueType>
struct Node {
    KeyType key_;
    ValueType value_;
    Node *next_;

    Node(KeyType key, ValueType value) {
        key_ = key;
        value_ = value;
        next_ = nullptr;
    }

    void deleteNode() {
        if (next_ != nullptr) {
            next_->deleteNode();
            delete next_;
        }
    }

    bool fixCollision(KeyType key, ValueType value) {
        if (key_ == key) {
            value_ = value;
            return false;
        } else {
            if (next_) {
                return next_->fixCollision(key, value);
            } else {
                next_ = new Node(key, value);
                return true;
            }
        }
    }

    void setOldNode(Node *new_node) {
        if (next_ != nullptr) {
            next_->setOldNode(new_node);
        } else {
            next_ = new_node;
        }
    }

    ValueType *getValue(KeyType key) {
        if (key_ == key) {
            return &value_;
        }
        if (next_ != nullptr) {
            return next_->getValue(key);
        } else {
            return nullptr;
        }
    }
};

template <class KeyType, class ValueType, class Func = std::hash<KeyType>>
class HashTable {
public:
    HashTable() {
        capacity_ = 100;
        size_ = 0;
        full_coefficient_ = 0.5;
        hash_ = Func();
        hash_array_ = new Node<KeyType, ValueType> *[capacity_];
        for (size_t i = 0; i < capacity_; ++i) {
            hash_array_[i] = nullptr;
        }
    }

    explicit HashTable(Func hash) {
        capacity_ = 100;
        size_ = 0;
        full_coefficient_ = 0.5;
        hash_ = hash;
        hash_array_ = new Node<KeyType, ValueType> *[capacity_];
        for (size_t i = 0; i < capacity_; ++i) {
            hash_array_[i] = nullptr;
        }
    }

    HashTable(size_t capacity, double coefficient, Func func = std::hash<KeyType>()) {
        capacity_ = capacity;
        size_ = 0;
        if (coefficient <= 1 && coefficient > 0) {
            full_coefficient_ = coefficient;
        } else {
            full_coefficient_ = 0.5;
        }
        hash_ = func;
        hash_array_ = new Node<KeyType, ValueType> *[capacity_];
        for (size_t i = 0; i < capacity_; ++i) {
            hash_array_[i] = nullptr;
        }
    }

    ~HashTable() {
        for (size_t i = 0; i < capacity_; ++i) {
            if (hash_array_[i] != nullptr) {
                hash_array_[i]->deleteNode();
                delete hash_array_[i];
            }
        }
        delete[] hash_array_;
    }

    void insert(KeyType key, ValueType value) {
        size_t hash = hash_(key) % capacity_;
        if (hash_array_[hash] != nullptr) {
            if (hash_array_[hash]->fixCollision(key, value)) {
                ++size_;
            }
        } else {
            hash_array_[hash] = new Node<KeyType, ValueType>(key, value);
            ++size_;
        }
        if (full_coefficient_ < static_cast<double>(size_) / static_cast<double>(capacity_)) {
            rehashing();
        }
    }

    ValueType *find(KeyType key) {
        size_t hash = hash_(key) % capacity_;
        if (hash_array_[hash] == nullptr) {
            return nullptr;
        } else {
            return hash_array_[hash]->getValue(key);
        }
    }

    void erase(KeyType key) {
        size_t hash = hash_(key) % capacity_;
        if (hash_array_[hash] != nullptr) {
            if (hash_array_[hash]->key_ == key) {
                --size_;
                Node<KeyType, ValueType> *next_node = hash_array_[hash]->next_;
                delete hash_array_[hash];
                hash_array_[hash] = next_node;
            } else {
                Node<KeyType, ValueType> *current_node = hash_array_[hash]->next_;
                Node<KeyType, ValueType> *parent = hash_array_[hash];
                while (current_node != nullptr) {
                    if (current_node->key_ == key) {
                        if (current_node->next_ != nullptr) {
                            parent->next_ = current_node->next_;
                            delete current_node;
                            --size_;
                            return;
                        } else {
                            parent->next_ = nullptr;
                        }
                    }
                    parent = current_node;
                    current_node = current_node->next_;
                }
            }
        }
    }

    Node<KeyType, ValueType> &operator[](uint64_t hash_code) {
        if (hash_code < 0 || hash_code >= capacity_) {
            throw std::out_of_range("");
        }
        if (hash_array_[hash_code] == nullptr) {
            throw std::runtime_error("");
        }
        return *hash_array_[hash_code];
    }

    Node<KeyType, ValueType> at(uint64_t hash_code) {
        if (hash_code < 0 || hash_code >= capacity_) {
            throw std::out_of_range("");
        }
        if (hash_array_[hash_code] == nullptr) {
            throw std::runtime_error("");
        }
        return *hash_array_[hash_code];
    }

    size_t size() const {
        return size_;
    }

    size_t capacity() const {
        return capacity_;
    }

private:
    size_t size_;
    size_t capacity_;
    double full_coefficient_;
    Func hash_;
    Node<KeyType, ValueType> **hash_array_;

    void rehashing() {
        size_t old_capacity = capacity_;
        capacity_ <<= 1;
        auto **new_hash_array = new Node<KeyType, ValueType> *[capacity_];
        for (size_t i = 0; i < capacity_; ++i) {
            new_hash_array[i] = nullptr;
        }
        for (size_t index = 0; index < old_capacity; ++index) {
            if (hash_array_[index] != nullptr) {
                Node<KeyType, ValueType> *current_node = hash_array_[index];
                while (current_node != nullptr) {
                    size_t new_hash = hash_(current_node->key_) % capacity_;
                    if (new_hash_array[new_hash] != nullptr) {
                        new_hash_array[new_hash]->setOldNode(current_node);
                    } else {
                        new_hash_array[new_hash] = current_node;
                    }
                    Node<KeyType, ValueType> *tmp = current_node;
                    current_node = current_node->next_;
                    tmp->next_ = nullptr;
                }
            } else {
                continue;
            }
        }
        delete[] hash_array_;
        hash_array_ = new_hash_array;
    }
};



#endif //CONTEST10_HASHTABLE_H
