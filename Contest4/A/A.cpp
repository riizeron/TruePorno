// A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//1
//11
//21
//1211
//111221
//312211
//13112221
//1113213211

#include <iostream>
#include <string>

std::string N_string(std::string str, int len) {
    std::string newString = "";
    if (len == 1) {
        return "1" + str;
    }
    for (int j = 0; j < len; j++) {
        int counter = 1;
        if (j == len - 1) {
            // std::cout << "end" << std::endl;
            newString += std::to_string(counter);
            newString += str[j];
            break;
        }
        for (int i = j + 1; i < len; i++) {
            if (str[j] == str[i] && i == len - 1) {
                // std::cout << "zashel" << std::endl;
                counter++;
                newString += std::to_string(counter);
                newString += str[j];
                j = len;
                break;
            } else if (str[j] == str[i]) {
                counter++;
            } else if (str[i] != str[j]) {
                // std::cout << "nerav" << std::endl;
                newString += std::to_string(counter);
                newString += str[j];
                j = i-1;
                // std::cout << newString << " ";
                // std::cout << "j equal " << j << std::endl;
                break;
            } else {
                // std::cout << "tut" << std::endl;
                j = i-1;
                newString += std::to_string(counter);
                newString += str[i];
                break;
            }
        }
    }
    return newString;
}

int main() {
    std::string x0;
    std::string xn;
    int N;
    std::cin >> x0;
    std::cin >> N;

    for (int i = 0; i < N-1; i++) {
        // std::cout << x0 << std::endl;
        xn = N_string(x0, x0.length());
        x0 = xn;
    }
    std::cout << x0;
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
