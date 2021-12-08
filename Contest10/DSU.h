//
// Created by Вячеслав on 23.11.2021.
//

#ifndef CONTEST10_DSU_H
#define CONTEST10_DSU_H


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


#endif //CONTEST10_DSU_H
