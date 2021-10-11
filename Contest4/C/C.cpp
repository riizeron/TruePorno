// C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector<std::string> Split(std::string str) {
    size_t pos = 0;
    std::vector<std::string> str_vector;
    while ((pos = str.find(' ')) != std::string::npos) {
        str_vector.push_back(str.substr(0, pos));
        str.erase(0, pos + 1);
    }
    str_vector.push_back(str);
    return str_vector;
}

int main() {
    std::string pupils;
    std::string counting;
    getline(std::cin, counting);
    getline(std::cin, pupils);
    int words_amount = Split(counting).size();
    std::vector<std::string> pupils_vec = Split(pupils);
    int child_amount = pupils_vec.size();
    std::cout << pupils_vec[child_amount >= words_amount ? words_amount - 1 :
        words_amount % child_amount == 0 ? child_amount - 1 : words_amount % child_amount - 1];
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
