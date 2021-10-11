// E.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int Progression(int a1, int d, int n) {
    return a1 + d * n;
}

enum NextStep {
    right,
    down,
    rightU,
    leftD,
};


int main() {
    int size, a1, d;
    std::cin >> size;
    std::cin >> a1 >> d;

    int x = 0;
    int y = 0;
    NextStep way(down);
    int counter = 0;
    int sum = 0;
    int** mat = new int* [size];
    for (int i = 0; i < size; i++) {
        mat[i] = new int[size];
        for (int j = 0; j < size; j++) {
            mat[i][j] = 0;
        }
    }
    int item;
    for (int i = 0; i < size * size; i++) {
        item = Progression(a1, d, i);
        mat[x][y] = item;
        if ((x < size / 2.0-1 && y >= 1+x && y <= size - 2-x)
            ||(x > size / 2.0 && y >= 1+(size-1-x) && y <= size - 2-(size-x-1))) {
            sum += item;
            std::cout << item << " ";
        }
        switch (way) {
        case right:
            y++;
            if (x == 0) {
                way = leftD;
            } else {
                way = rightU;
            }
            break;
        case down:
            x++;
            if (y == 0) {
                way = rightU;
            } else {
                way = leftD;
            }
            break;
        case rightU:
            x--;
            y++;
            if (x == 0) {
                way = right;
            }
            if (y == size - 1) {
                way = down;
            }
            break;
        case leftD:
            x++;
            y--;
            if (y == 0) {
                way = down;
            }
            if (x == size - 1) {
                way = right;
            }
            break;
        default:
            break;
        }
    }
    std::cout << sum << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << mat[i][j] << " ";
        }
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
