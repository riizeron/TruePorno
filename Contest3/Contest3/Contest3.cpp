// Contest3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

bool CheckUnique(int* arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int HemmingCount(int a[], int b[], int length) {
    int dist = 0;

    for (size_t i = 0; i < length; i++) {
#pragma omp parallel for reduction(+:disti)
        dist += (a[i] != b[i]);
    }
    return dist;
}

bool Eq(int* a, int* b, int length) {
    for (int i = 0; i < length; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int* Gre(int* a, int length) {
    int* outVector = new int[length + 1];
    int last = a[length - 1];
    for (int i = length - 1; i >= 0; i--) {
        outVector[i] = a[i] = a[i - 1];
    }
    a[0] = outVector[0] = last;
    return outVector;
}
int main() {
    int length;
    std::cin >> length;
    std::vector<int*> res;
    int** mat = new int* [length];
    int* numbers = new int[length];
    int* constNums = new int[length+1];
    int number;
    for (int i = 0; i < length; i++) {
        std::cin >> number;
        numbers[i] = constNums[i] = number;
    }
    mat[0] = constNums;
    if (length == 1) {
        std::cout << 0 << "\n";
        std::cout << number << "; " << 0;
        return 0;
    }
    for (int i = 1; i < length ; i++) {
        mat[i] = Gre(numbers, length);
    }
    delete[] numbers;

    int counter = 0;
    for (int i = 0; i < length; i++) {
        int flag = HemmingCount(constNums, mat[i], length);
        if (flag > counter) {
            counter = flag;
            res.clear();
            mat[i][length] = i;
            res.push_back(mat[i]);
        } else if (flag == counter) {
            if (res.size() == 0) {
                mat[i][length] = i;
                res.push_back(mat[i]);
            } else if (!Eq(res[res.size() - 1], mat[i], length)) {
                mat[i][length] = i;
                res.push_back(mat[i]);
            }
        }
    }
    delete[] constNums;
    delete[] mat;
    std::cout << counter << std::endl;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < length - 1; j++) {
            std::cout << res[i][j] << " ";
        }
        std::cout << res[i][length - 1];
        std::cout << "; ";
        std::cout << res[i][length];
        std::cout << std::endl;
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
