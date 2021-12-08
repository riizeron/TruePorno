// C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

struct MyNode {
    int val;
    MyNode* next;
    MyNode* previous;
    explicit MyNode(int value, MyNode* prev, MyNode* nex) {
        val = value;
        next = nex;
        previous = prev;
    }
};

struct MyDoubleLinkedList {
    MyNode* first;
    MyNode* last;
    MyDoubleLinkedList() {
        first = nullptr;
        last = nullptr;
    }
    bool isEmpty() {
        return first == nullptr;
    }
    void pushFront(int value) {
        MyNode* n = new MyNode(value, nullptr, first);
        if (isEmpty()) {
            first = n;
            last = n;
            return;
        }
        MyNode* tmp = first;
        tmp->previous = n;
        first = n;
    }
    void pushBack(int value) {
        MyNode* n = new MyNode(value, last, nullptr);
        if (isEmpty()) {
            first = n;
            last = n;
            return;
        }
        MyNode* tmp = last;
        tmp->next = n;
        last = n;
    }
    void insert(int value, int pos) {
        MyNode* n = first;
        for (int i = 0; i < pos; i++) {
            n = n->next;
        }
        MyNode* new_node = new MyNode(value, n, n->next);
        if (n->next != 0) {
            n->next->previous = new_node;
        }
        n->next = new_node;
    }
    void remove(int pos) {
        MyNode* n = first;
        for (int i = 0; i < pos; i++) {
            n = n->next;
        }
        n->next = n->next->next;
        if (n->next != nullptr) {
            n->next->previous = n;
        }
    }
    void print() {
        if (isEmpty()) {
            return;
        }
        MyNode* n = first;
        while (n) {
            std::cout << n->val << " ";
            n = n->next;
        }
        n = nullptr;
    }
    void printReverse() {
        if (isEmpty()) {
            return;
        }
        MyNode* n = last;
        while (n) {
            std::cout << n->val << " ";
            n = n->previous;
        }
    }
};

int main() {
    int n, m;
    MyDoubleLinkedList* list = new MyDoubleLinkedList();
    std::cin >> n >> m;
    int val, pos;
    std::string command;
    for (int i = 0; i < n; i++) {
        std::cin >> val;
        list->pushBack(val);
    }
    for (int i = 0; i < m; i++) {
        std::cin >> command;
        if (command == "push_front") {
            std::cin >> val;
            list->pushFront(val);
        } else if (command == "push_back") {
            std::cin >> val;
            list->pushBack(val);
        } else if (command == "insert") {
            std::cin >> val;
            std::cin >> pos;
            list->insert(val, pos);
        } else if (command == "remove") {
            std::cin >> pos;
            list->remove(pos);
        } else {
            std::cout << "Incorrect command" << std::endl;
        }
    }
    list->print();
    std::cout << std::endl;
    list->printReverse();
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
