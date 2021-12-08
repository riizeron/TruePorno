// B.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct MyNode {
    int val;
    MyNode* next;
    
    explicit MyNode(int value) {
        val = value;
        next = nullptr;
    }
    ~MyNode() {
        delete next;
        next = nullptr;
    }
};

struct MyList {
    MyNode* first;
    MyNode* last;

    MyList() {
        first = nullptr;
        last = nullptr;
    }
    ~MyList() {
        delete first;
    }
    bool isEmpty() {
        return first == nullptr;
    }
    void pushBack(int value) {
        MyNode* p = new MyNode(value);
        if (isEmpty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void print() {
        if (isEmpty()) {
            return;
        }
        MyNode* n = first;
        std::cout << n->val << " ";
        do {
            n = n->next;
            std::cout << n->val << " ";
        } while (n->next != nullptr);
        delete n;
    }
};

void turnBackwords(MyList* res_list, MyNode* node) {
    if (node->next == nullptr) {
        res_list->pushBack(node->val);
    } else {
        turnBackwords(res_list, node->next);
        res_list->pushBack(node->val);
    }
}

int main() {
    MyList* list = new MyList();
    int n;
    int value;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> value;
        list->pushBack(value);
    }
    MyList* res_list = new MyList();
    turnBackwords(res_list, list->first);
    res_list->print();
    delete list;
    delete res_list;
    return 0;
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
