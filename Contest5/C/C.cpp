// C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

class MyQueue {
private:
    int* arrQueue;
    int amount;
    int* tmp;

public:
    MyQueue() {
        arrQueue = nullptr;
        amount = 0;
        tmp = nullptr;
    }
    ~MyQueue() {
        if (amount > 0) {
            delete[] arrQueue;
        }
    }
    void EnqueueMid(int newItem) {
        tmp = arrQueue;
        arrQueue = new int[amount + 1];
        int index = amount % 2 == 0 ? amount / 2 : amount / 2 + 1;
        amount++;
        for (size_t i = 0; i < index; i++)
            arrQueue[i] = tmp[i];
        arrQueue[index] = newItem;
        for (size_t i = index + 1; i < amount; i++)
            arrQueue[i] = tmp[i - 1];
        delete[] tmp;
    }
    void Enqueue(int newItem) {
        tmp = arrQueue;
        arrQueue = new int[amount + 1];
        amount++;
        for (size_t i = 0; i < amount - 1; i++)
            arrQueue[i] = tmp[i];
        arrQueue[amount - 1] = newItem;
        delete[] tmp;
    }
    int Dequeue() {
        if (amount == 0) {
            throw - 1;
        }
        amount--;
        int first = arrQueue[0];
        tmp = arrQueue;
        arrQueue = new int[amount];
        for (size_t i = 0; i < amount; i++)
        {
            arrQueue[i] = tmp[i + 1];
        }
        delete[] tmp;
        return first;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    MyQueue* st = new MyQueue();
    std::string command;
    int item;
    int counter;
    std::cin >> counter;
    for (size_t i = 0; i < counter; i++) {
        std::cin >> command;
        if (command == "+") {
            std::cin >> item;
            st->Enqueue(item);
        } else if (command == "*") {
            std::cin >> item;
            st->EnqueueMid(item);
        } else {
            std::cout << st->Dequeue() << std::endl;
        }
    }
    delete st;
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
