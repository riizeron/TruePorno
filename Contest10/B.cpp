//
// Created by Вячеслав on 22.11.2021.
//

#include <iostream>
#include <utility>

class SNM {
private:
    void set(int key) const {
        parents[key] = key;
        size[key] = 1;
    }

public:
    explicit SNM(int cities_amount) {
        parents = new int[cities_amount];
        size = new int[cities_amount];
        for (int i = 0; i < cities_amount; ++i) {
            set(i);
        }
    }

    void unite(int key_first, int key_second) {
        key_first = find(key_first);
        key_second = find(key_second);
        if (key_first != key_second) {
            if (size[key_first] < size[key_second]) {
                std::swap(key_first, key_second);
            }
            parents[key_second] = key_first;
            size[key_first] += size[key_second];
        }
    }

    int *parents;
    int *size;

    ~SNM() {
        delete[] parents;
        delete[] size;
    }

    int find(int key) {
        if (parents[key] == key) {
            return parents[key];
        }
        return parents[key] = find(parents[key]);
    }
};

int main() {
    int cities_amount, bridge_amount;
    int key_first, key_second;
    std::cin >> cities_amount >> bridge_amount;
    if (cities_amount == 1) {
        std::cout << 0;
        return 0;
    }
    bool flag;
    SNM *snm = new SNM(cities_amount);
    int counter = 0;
    for (int iiiiii = 0; iiiiii < bridge_amount; ++iiiiii) {
        flag = true;
        counter = iiiiii;
        std::cin >> key_first >> key_second;
        if (key_first == key_second) {
            continue;
        }
        snm->unite(key_first, key_second);
        for (int j = 1; j < cities_amount; ++j) {
            if (snm->parents[j] == snm->parents[0]) {
                continue;
            }
            if (snm->find(j) != snm->find(0)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            std::cout << counter + 1;
            break;
        }
    }
    delete snm;
    return 0;
}
