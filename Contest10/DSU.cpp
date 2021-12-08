//
// Created by Вячеслав on 23.11.2021.
//

#include "DSU.h"
#include <iostream>

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
        if (size[first] > size[second]) {
            std::swap(first, second);
        }
        next[roots[parents[first]]] = parents[second];
        roots[parents[first]] = roots[parents[second]];
        parents[parents[second]] = parents[first];
        parents[second] = first;

    }
}

DSU::~DSU() {
    delete parents;
    delete next;
    delete roots;
    delete size;
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
