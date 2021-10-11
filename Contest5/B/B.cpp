// B.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

class MyDeck {
private:
    int* arrDeck;
    int amount;

public:
    MyDeck() {
        arrDeck = nullptr;
        amount = 0;
    }
    ~MyDeck() {
        if (amount > 0) {
            delete[] arrDeck;
        }
    }
    void PushF(int newItem) {
        int* tmp;
        tmp = arrDeck;
        arrDeck = new int[amount + 1];
        amount++;
        for (size_t i = 1; i < amount; i++)
            arrDeck[i] = tmp[i-1];
        arrDeck[0] = newItem;
        std::cout << "ok" << std::endl;
        delete[] tmp;
    }
    void PushL(int newItem) {
        int* tmp;
        tmp = arrDeck;
        arrDeck = new int[amount + 1];
        amount++;
        for (size_t i = 0; i < amount - 1; i++)
            arrDeck[i] = tmp[i];
        arrDeck[amount - 1] = newItem;
        std::cout << "ok" << std::endl;
        delete[] tmp;
    }
    int Size() {
        return amount;
    }
    void Clear() {
        arrDeck = nullptr;
        amount = 0;
        std::cout << "ok" << std::endl;
    }
    int PopF() {
        if (amount == 0) {
            throw - 1;
        }
        amount--;
        int* tmp;
        int first = arrDeck[0];
        tmp = arrDeck;
        arrDeck = new int[amount];
        for (size_t i = 0; i < amount; i++)
        {
            arrDeck[i] = tmp[i + 1];
        }
        delete[] tmp;
        return first;
    }
    int PopL() {
        if (amount == 0) {
            throw - 1;
        }
        amount--;
        return arrDeck[amount];
    }
    int Back() {
        if (amount == 0) {
            throw - 1;
        }
        return arrDeck[amount - 1];
    }
    int Front() {
        if (amount == 0) {
            throw - 1;
        }
        return arrDeck[0];
    }
};

int main() {
    MyDeck* st = new MyDeck();
    std::string command;
    int item;
    do {
        try {
            std::cin >> command;
            if (command == "push_back") {
                std::cin >> item;
                st->PushL(item);
            } else if (command == "push_front") {
                std::cin >> item;
                st->PushF(item);
            } else if (command == "pop_front") {
                std::cout << st->PopF() << std::endl;
            } else if (command == "pop_back") {
                std::cout << st->PopL() << std::endl;
            } else if (command == "back") {
                std::cout << st->Back() << std::endl;
            } else if (command == "front") {
                std::cout << st->Front() << std::endl;
            } else if (command == "size") {
                std::cout << st->Size() << std::endl;
            } else if (command == "clear") {
                st->Clear();
            }
        }
        catch (int a) {
            std::cout << "error" << std::endl;
        }
    } while (command != "exit");
    std::cout << "bye";
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
