//
// Created by Вячеслав on 22.11.2021.
//

#include <iostream>
#include <utility>

class DSU {
public:
    explicit DSU(int);

    int *parents;
    int *size;
    int *roots;
    int *next;

    void unite(int, int);

    ~DSU();

    int find(int);

private:
    void set(int) const;
};

DSU::DSU(int amount) {
    parents = new int[amount];
    size = new int[amount];
    roots = new int[amount];
    next = new int[amount];

    for (int i = 0; i < amount; ++i) {
        set(i);
    }
}

void DSU::unite(int first, int second) {
    first = find(first);
    second = find(second);
    if (first != second) {
        if (size[first] < size[second]) {
            std::swap(first, second);
        }
        next[roots[parents[first]]] = parents[second];
        roots[parents[first]] = roots[parents[second]];
        parents[parents[second]] = parents[first];
        parents[second] = first;
        size[first] += size[second];
    }
}

DSU::~DSU() {
    delete[] parents;
    delete[] next;
    delete[] roots;
    delete[] size;
}

void DSU::set(int key) const {
    roots[key] = next[key] = parents[key] = key;
    size[key] = 1;
}

int DSU::find(int key) {
    if (parents[key] == key) {
        return parents[key];
    }
    return find(parents[key]);
}

int main() {
    int cats_amount;
    int first, second;
    std::cin >> cats_amount;
    DSU *dsu = new DSU(cats_amount);
    for (int i = 0; i < cats_amount - 1; ++i) {
        std::cin >> first >> second;
        dsu->unite(first - 1, second - 1);
    }
    int start = dsu->find(1);
    while (dsu->next[start] != start) {
        std::cout << start + 1 << " ";
        start = dsu->next[start];
    }
    std::cout << start + 1 << std::endl;

    delete dsu;
    return 0;
}
