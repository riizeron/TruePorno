// F.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

void Search(std::string str1, std::string str2) {
    int freq1[26] = {};
    int freq2[26] = {};
    for (size_t i = 0; i < str1.length(); i++) {
        if (str1[i] != ' ')
            freq1[str1[i] - 97]++;
    }
    for (size_t i = 0; i < str2.length(); i++) {
        if (str2[i] != ' ')
            freq2[str2[i] - 97]++;
    }
    bool flag = false;
    for (size_t i = 0; i < 26; i++) {
        if (freq1[i] == 0 && freq2[i] != 0 || freq2[i] == 0 && freq1[i] != 0) {
            std::cout << static_cast<char>(i + 97) << " ";
            flag = true;
        }
    }
    if (!flag)
        std::cout << "NONE";
}
int main() {
    std::string str1, str2;
    std::getline(std::cin, str1);
    std::getline(std::cin, str2);
    Search(str1, str2);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
