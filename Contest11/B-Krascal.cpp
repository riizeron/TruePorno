//
// Created by Вячеслав on 06.12.2021.
//

#include <iostream>
#include <utility>

class Rib {
public:
    int mass;
    int first;
    int second;

    Rib(int first, int second, int mass) {
        this->first = first;
        this->second = second;
        this->mass = mass;
    }
};

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

void shellSort(Rib **arr, int size) {
    for (int s = size / 2; s > 0; s /= 2) {
        for (int i = s; i < size; ++i) {
            for (int j = i - s; j >= 0 && arr[j]->mass > arr[j + s]->mass; j -= s) {
                Rib *temp = arr[j];
                arr[j] = arr[j + s];
                arr[j + s] = temp;
            }
        }
    }
}

int findOstov(Rib **arr, int rib_amount, int knot_amount, SNM *snm, int *rib_indexes,
              int skip = -10) {
    int counter = 0;
    int cur_amount_of_ribs = 1;
    int index = 0;
    for (int iterator = 0; iterator < rib_amount; ++iterator) {
        if (iterator == skip) {
            continue;
        }
        if (arr[iterator]->first == arr[iterator]->second) {
            continue;
        }
        if (snm->find(arr[iterator]->first - 1) != snm->find(arr[iterator]->second - 1)) {
            snm->unite(arr[iterator]->first - 1, arr[iterator]->second - 1);
            counter += arr[iterator]->mass;
            cur_amount_of_ribs++;
            if (skip == -10) {
                rib_indexes[index] = iterator;
                index++;
            }
            if (cur_amount_of_ribs == knot_amount) {
                return counter;
            }
        }
    }
    return 0;
}

int main() {
    int knot_amount, rib_amount;
    int key_first, key_second, mass;
    std::cin >> knot_amount >> rib_amount;
    Rib *elem;
    Rib **arr = new Rib *[rib_amount];
    int *rib_indexes = new int[knot_amount - 1];
    // Filling rib array;
    for (int i = 0; i < rib_amount; ++i) {
        std::cin >> key_first >> key_second >> mass;
        elem = new Rib(key_first, key_second, mass);
        arr[i] = elem;
    }
    shellSort(arr, rib_amount);
    SNM *snm = new SNM(knot_amount);
    int counter_first = findOstov(arr, rib_amount, knot_amount, snm, rib_indexes);
    delete snm;
    int counter;
    int counter_second = 1000000000;
    for (int isckl = 0; isckl < knot_amount - 1; ++isckl) {
        snm = new SNM(knot_amount);
        counter = findOstov(arr, rib_amount, knot_amount, snm, rib_indexes, rib_indexes[isckl]);
        if (counter < counter_second && counter != 0) {
            counter_second = counter;
        }
        delete snm;
    }
    std::cout << counter_first << " ";
    std::cout << counter_second;
    for (int i = 0; i < rib_amount; ++i) {
        delete arr[i];
    }
    delete[] arr;
    delete[] rib_indexes;
    return 0;
}
