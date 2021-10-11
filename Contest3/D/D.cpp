// D.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int>F, S;

void Move(const std::vector< int > seq, int k, int n) {
    /*F.resize(n);
    S.resize(n);
    F.front() = seq.front();
    S.back() = seq.back();
    k--;
    for (int i1(1), i2(n - 2); i1 < n; i1++, i2--) {
        F[i1] = (i1 % k) ? std::min(seq[i1], F[i1 - 1]) : seq[i1];
        S[i2] = ((i2 + 1) % k) ? std::min(seq[i2], S[i2 + 1]) : seq[i2];
    }*/
    F.resize(n);
    S.resize(n);
;   for (int i = 0; i < n; i++) {
        if (i % k) {
            F[i] = std::min(seq[i], F[i - 1]);
        }
        else {
            F[i] = seq[i];
        }
    }
    S.back() = seq.back();
    for (int i = n - 2; i >= 0; i--) {
        if ((i + 1) % k) {
            S[i] = std::min(seq[i], S[i + 1]);
        }
        else {
            S[i] = seq[i];
        }
    }
}

int ReturnMin(int l, int k) {
    return std::min(S[l], F[l + k - 1]);
}

int main() {
    int N, K, item;
    std::cin >> N >> K;
    std::vector<int>sequens;
    for (int i = 0; i < N; i++) {
        std::cin >> item;
        sequens.push_back(item);
    }
    Move(sequens, K, N);
    for (int i = 0; i < N - K + 1; i++) {
        std::cout << ReturnMin(i, K) << " ";
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
