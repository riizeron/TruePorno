// С.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

int main() {
    int len, item;
    std::cin >> len;
    int* arr = new int[len+1];
    arr[0] = 0;
    
    // std::cout << arr[0] << " ";
    for (int i = 1; i < len+1; i++) {
        arr[i] = arr[i - 1];
        std::cin >> item;
        arr[i] += (item == 0);
        // std::cout << arr[i] << " ";
    }
    int K;
    std::vector<int> vec;
    std::cin >> K;
    for (int i = 0; i < K; i++) {
        int first, second;
        std::cin >> first >> second;
        vec.push_back(arr[second] - arr[first - 1]);
    }
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
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
