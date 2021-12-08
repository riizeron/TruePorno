//
// Created by Вячеслав on 16.11.2021.
//

#include "BTree.cpp"
#include <iostream>

int main() {
    auto *tr = new BTree(2);
    tr->insert(100);
    tr->insert(35);
    tr->insert(65);
    tr->insert(10);
    tr->insert(20);
    tr->insert(40);
    tr->insert(50);
    tr->insert(70);
    tr->insert(80);
    tr->insert(90);
    tr->insert(130);
    tr->insert(180);
    tr->insert(110);
    /*tr->insert(120);
    tr->insert(140);
    tr->insert(160);
*//*    tr->insert(190);
    tr->insert(240);
    tr->insert(260);*/
    std::cout<<tr->size()<<std::endl;
    std::cout<<tr->sum()<<std::endl;


    return 0;

}
