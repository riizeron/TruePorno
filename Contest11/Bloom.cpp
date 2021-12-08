#include <iostream>
#include <string>

// основной класс фильтра
class BloomFilter {
public:
    BloomFilter(size_t hashes, size_t bits) {
        this->hashes_ = hashes;
        this->bits_ = bits;
    }

    ~BloomFilter() {
        bits_ = 0;
        hashes_ = 0;
    }

    // вставка информации об объекте
    void add(const std::string &obj) {
    }

    // проверка принадлежности объекта
    bool verify(const std::string &obj) {
        return true;
    }

    // считаем относительную величину false positive rate по запросам тестирования
    // принадлежности
    double getFPRate() const {
        return 0;
    }

    size_t numberOfHashFunctions() const {
        return hashes_;
    }

    size_t numberOfBits() const {
        return bits_;
    }

private:
    size_t hashes_;
    size_t bits_;
};
