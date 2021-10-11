// A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

class MyStack {
 public:
    MyStack() {
        arrStack = nullptr;
        amount = 0;
    }
    ~MyStack() {
        if (amount > 0) {
            delete[] arrStack;
        }
    }
    void Push(int newItem) {
        int* tmp;
        tmp = arrStack;
        arrStack = new int[amount + 1];
        amount++;
        for (size_t i = 0; i < amount - 1; i++)
            arrStack[i] = tmp[i];
        arrStack[amount - 1] = newItem;
        std::cout << "ok" << std::endl;
        delete[] tmp;
    }
    int Size() {
        return amount;
    }
    void Clear() {
        arrStack = nullptr;
        amount = 0;
        std::cout << "ok" << std::endl;
    }
    int Pop() {
        if (amount == 0) {
            throw -1;
        }
        amount--;
        return arrStack[amount];
    }
    int Back() {
        if (amount == 0) {
            throw -1;
        }
        return arrStack[amount - 1];
    }
 private:
    int* arrStack;
    int amount;
};

int main() {
    MyStack* st = new MyStack();
    std::string command;
    int item;

        do {
            try {
                std::cin >> command;
                if (command == "push") {
                    std::cin >> item;
                    st->Push(item);
                }
                else if (command == "pop") {
                    std::cout << st->Pop() << std::endl;
                }
                else if (command == "back") {
                    std::cout << st->Back() << std::endl;
                }
                else if (command == "size") {
                    std::cout << st->Size() << std::endl;
                }
                else if (command == "clear") {
                    st->Clear();
                }
            } catch (int a) {
                std::cout << "error" << std::endl;
            }
        } while (command != "exit");
        std::cout << "bye";
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
