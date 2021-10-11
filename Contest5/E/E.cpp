// E.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

std::string Unpacking(std::string str) {
    int leftBr;
    int rightBr;
    while ((leftBr = str.find_last_of('[')) != str.npos) {
        rightBr = str.find_first_of(']', leftBr);
        int value = 0;
        int i = 0;
        while (leftBr - i - 1 >= 0 && leftBr - i - 1 < str.size()
            && (str[leftBr - i - 1] >= '0' && str[leftBr - i - 1] <= '9')) {
            value += exp(i * log(10)) * (str[leftBr - i - 1] - '0');
            i++;
        }
        std::string newStr = str.substr(leftBr + 1, rightBr - leftBr - 1);
        str.erase(leftBr - i, rightBr - leftBr + i + 1);
        for (int j = 0; j < value; j++) {
            str.insert(leftBr - i, newStr);
        }
    }
    return str;
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << Unpacking(str) << std::endl;
    return 0;
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
