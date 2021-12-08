//
// Created by Вячеслав on 24.11.2021.
//
#include <iostream>
#include <fstream>

int main() {
    std::ofstream ifst("hack.txt");
    std::srand(time(nullptr));
    for (int i = 0; i < 15000; i++) {
        ifst << std::rand() << std::endl;
    }
}

