
#include <iostream>

template <class KeyType, class ValueType>
struct Node {
    KeyType key_;
    ValueType value_;
    Node *next_;

    Node(KeyType, ValueType);

    ~Node();

    void del();

    ValueType value(KeyType) const;
    bool fix(KeyType, ValueType);
};

template <class KeyType, class ValueType>
Node<KeyType, ValueType>::Node(KeyType key, ValueType value) {
    key_ = key;
    value_ = value;
    next_ = nullptr;
}

template <class KeyType, class ValueType>
Node<KeyType, ValueType>::~Node() {
    del();
}

template <class KeyType, class ValueType>
void Node<KeyType, ValueType>::del() {
    while (next_) {
        next_->del();
        delete next_;
    }
}

template <class KeyType, class ValueType>
ValueType Node<KeyType, ValueType>::value(KeyType key) const {
    if (key_ == key) {
        return &value_;
    }
    while (next_) {
        return next_->value(key);
    }
    return nullptr;
}

template <class KeyType, class ValueType>
bool Node<KeyType, ValueType>::fix(KeyType key, ValueType val) {
    if (key() == key) {
        value() = val;
        return false;
    } else {
        if (next_) {
            return next_->fix(key, val);
        } else {
            next_ = new Node(key, val);
            return true;
        }
    }
}

template <class KeyType, class ValueType, class Func = std::hash<KeyType>>
class HashTable {
public:
    HashTable();

    explicit HashTable(Func);

    HashTable(size_t, double, Func = std::hash<KeyType>());

    ~HashTable();

    void insert(KeyType, ValueType);

    ValueType *find(KeyType);

    void erase(KeyType);

    Node<KeyType, ValueType> &operator[](uint64_t);

    Node<KeyType, ValueType> at(uint64_t);

    [[nodiscard]] size_t size() const;

    void setSize(size_t);

    [[nodiscard]] size_t capacity() const;

    void setCapacity(size_t);

    [[nodiscard]] double filled() const;

    void setFilled(double);

    [[nodiscard]] bool isCodeCorrect(uint64_t code) const;

    Node<KeyType, ValueType> **tempo;
    Func hash;

private:
    size_t capacity_{};
    size_t size_{};
    double filled_{};
};

template <class KeyType, class ValueType, class Func>
HashTable<KeyType, ValueType, Func>::HashTable(Func func) {
    setCapacity(100);
    tempo = new Node<KeyType, ValueType> *[capacity()];
    for (int i = 0; i < capacity(); ++i) {
        tempo[i] = nullptr;
    }
    setSize(0);
    setFilled(0.5);
    this->hash = func;
}

template <class KeyType, class ValueType, class Func>
HashTable<KeyType, ValueType, Func>::HashTable() {
    setCapacity(100);
    tempo = new Node<KeyType, ValueType> *[capacity()];
    for (int i = 0; i < capacity(); ++i) {
        tempo[i] = nullptr;
    }
    setSize(0);
    setFilled(0.5);
    hash = Func();
}

template <class KeyType, class ValueType, class Func>
HashTable<KeyType, ValueType, Func>::HashTable(size_t capacity, double coeff, Func func) {
    hash = func;
    capacity_ = capacity;
    tempo = new Node<KeyType, ValueType> *[capacity];
    for (int i = 0; i < capacity; ++i) {
        tempo[i] = nullptr;
    }
    setSize(0);
    if (coeff <= 0 || coeff > 1) {
        setFilled(0.5);
    } else {
        setFilled(coeff);
    }
}

template <class KeyType, class ValueType, class Func>
size_t HashTable<KeyType, ValueType, Func>::size() const {
    return size_;
}

template <class KeyType, class ValueType, class Func>
size_t HashTable<KeyType, ValueType, Func>::capacity() const {
    return capacity_;
}

template <class KeyType, class ValueType, class Func>
double HashTable<KeyType, ValueType, Func>::filled() const {
    return filled_;
}

template <class KeyType, class ValueType, class Func>
Node<KeyType, ValueType> HashTable<KeyType, ValueType, Func>::at(uint64_t code) {
    if (!tempo[code]) {
        throw std::runtime_error("");
    }
    if (!isCodeCorrect()) {
        throw std::out_of_range("");
    }
    return *tempo[code];
}

template <class KeyType, class ValueType, class Func>
Node<KeyType, ValueType> &HashTable<KeyType, ValueType, Func>::operator[](uint64_t code) {
    if (!isCodeCorrect()) {
        throw std::out_of_range("");
    }
    if (!tempo[code]) {
        throw std::runtime_error("");
    }
    return *tempo[code];
}

template <class KeyType, class ValueType, class Func>
void HashTable<KeyType, ValueType, Func>::erase(KeyType key) {
    size_t code = hash(key) % capacity();
    if (tempo[code] != nullptr) {
        if (tempo[code]->key_ == key) {
            Node<KeyType, ValueType> *next_node = tempo[code]->next_;
            delete tempo[code];
            tempo[code] = next_node;
            setSize(size() - 1);
        } else {
            Node<KeyType, ValueType> *cur = tempo[code]->next_;
            Node<KeyType, ValueType> *par = tempo[code];
            while (cur) {
                if (cur->key_ == key) {
                    if (cur->next_) {
                        par->next_ = cur->next_;
                        delete cur;
                        setSize(size() - 1);
                        return;
                    } else {
                        par->next_ = nullptr;
                    }
                }
                par = cur;
                cur = cur->next_;
            }
        }
    }
}

template <class KeyType, class ValueType, class Func>
HashTable<KeyType, ValueType, Func>::~HashTable() {
    for (int i = 0; i < capacity(); ++i) {
        if (tempo[i] != nullptr) {
            delete tempo[i];
        }
    }
    delete[] tempo;
}

template <class KeyType, class ValueType, class Func>
ValueType *HashTable<KeyType, ValueType, Func>::find(KeyType key) {
    size_t code = hash(key) % capacity();
    if (tempo[code] == nullptr) {
        return nullptr;
    } else {
        return tempo[code]->value(*key);
    }
}

template <class KeyType, class ValueType, class Func>
void HashTable<KeyType, ValueType, Func>::insert(KeyType key, ValueType val) {
    size_t code = hash(key) % capacity();
    if (tempo[code] != nullptr) {
        if (tempo[code]->fix(key, val)) {
            setSize(size() + 1);
        }
    } else {
        tempo[code] = new Node<KeyType, ValueType>(key, val);
        setSize(size() + 1);
    }
}

template <class KeyType, class ValueType, class Func>
bool HashTable<KeyType, ValueType, Func>::isCodeCorrect(uint64_t code) const {
    return code >= 0 && code < capacity();
}

template <class KeyType, class ValueType, class Func>
void HashTable<KeyType, ValueType, Func>::setSize(size_t size) {
    size_ = size;
}

template <class KeyType, class ValueType, class Func>
void HashTable<KeyType, ValueType, Func>::setCapacity(size_t capa) {
    capacity_ = capa;
}

template <class KeyType, class ValueType, class Func>
void HashTable<KeyType, ValueType, Func>::setFilled(double coeff) {
    filled_ = coeff;
}


