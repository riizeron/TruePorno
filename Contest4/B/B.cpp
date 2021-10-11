// B.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

int SumElem(int* arr, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }
    return sum;
}
std::string Row(int* items1, int len1, int* items2, int len2) {
    std::string separator = "+";
    if (SumElem(items1, len1) > SumElem(items2, len2)
        || SumElem(items1, len1) == SumElem(items2, len2) && len1 >= len2) {
        for (int i = 0; i < len1; i++) {
            // if (items1[i] != 0) {
                separator.append(items1[i], '-');
                separator += '+';
            // }
        }
        int index = 0;
        for (int j = 0; j < len2; j++) {
            // if (items1[j] != 0) {
                index += items2[j] + 1;
                separator[index] = '+';
            // }
        }
    } else if (SumElem(items1, len1) < SumElem(items2, len2)
        || SumElem(items1, len1) == SumElem(items2, len2) && len1 < len2) {
        for (int i = 0; i < len2; i++) {
            // if (items2[i] != 0) {
                separator.append(items2[i], '-');
                separator += '+';
            // }
        }
        int index = 0;
        for (int j = 0; j < len1; j++) {
            // if (items2[j] != 0) {
                index += items1[j] + 1;
                separator[index] = '+';
            // }
        }
    }

    separator += '\n';
    std::string row = "|";
    for (int i = 0; i < len2; i++) {
        // if (items2[i] != 0) {
            row.append(items2[i], ' ');
            row += "|";
        // }
    }
    row += '\n';
    return separator + row;
}

int main() {
    int N;
    int wide1 = 0;
    int wide2 = 0;
    std::string result = "";
    int* items1 = new int[0];
    int* items2 = new int[0];
    std::cin >> N;
    if (N == 0) {
        return 0;
    }
    std::cin >> wide1;
    items1 = new int[wide1];
    for (int i = 0; i < wide1; i++) {
        std::cin >> items1[i];
    }
    result += Row(new int[0], 0, items1, wide1);
    for (int i = 1; i < N; i++) {
        std::cin >> wide2;
        items2 = new int[wide2];
        for (int j = 0; j < wide2; j++) {
            std::cin >> items2[j];
        }
        result += Row(items1, wide1, items2, wide2);
        items1 = items2;
        wide1 = wide2;
    }
    result += '+';
    for (int i = 0; i < wide1; i++) {
        // if (items1[i] != 0) {
            result.append(items1[i], '-');
            result += '+';
        // }
    }
    std::cout << result;
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
