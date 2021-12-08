// D.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

struct MyNode {
    int val;
    MyNode* next;
    explicit MyNode(int value) {
        val = value;
        next = nullptr;
    }
};

class MyList {
public:
    MyNode* first;
    MyNode* last;
    MyList() {
        first = nullptr;
        last = nullptr;
    }
    bool isEmpty() {
        return first == nullptr;
    }
    void pushBack(int value) {
        MyNode* n = new MyNode(value);
        if (isEmpty()) {
            first = n;
            last = n;
            return;
        }
        last->next = n;
        last = n;
    }
    void insert(int value, int pos) {
        MyNode* n = first;
        for (int i = 0; i < pos; i++) {
            n = n->next;
        }
        MyNode* new_node = new MyNode(value);
        new_node->next = n->next;
        n->next = new_node;
    }
    void remove(int pos) {
        MyNode* n = first;
        for (int i = 0; i < pos; i++) {
            n = n->next;
        }
        n->next = n->next->next;
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
};
int main() {
    int n, m;
    MyList* list = new MyList();
    std::string command;
    std::cin >> n >> m;
    int val, pos;
    for (int i = 0; i < n; i++) {
        std::cin >> val;
        list->pushBack(val);
    }
    for (int i = 0; i < m; i++) {
        std::cin >> command;
        if (command == "insert") {
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
