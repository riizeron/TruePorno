// A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class MyNode {
    int val;
    MyNode* next;
    explicit MyNode(int value) {
        val = value;
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
    bool isEmpty() {
        return first == nullptr;
    }
    void pushBack(MyNode* p) {
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
        while (n!=nullptr) {
            std::cout << n->val << " ";
            n = n->next;
        }
        n = nullptr;
    }
};

void merge(MyList* result, MyList* list1, MyList* list2, int len) {
    MyNode* n1 = list1->first;
    MyNode* n2 = list2->first;
    int list1Flag = 0;
    int list2Flag = 0;
    for (int i = 0; i < len; i++) {
        if (n2 == nullptr||list2Flag) {
            if (n1 != nullptr&&!list1Flag) {
                result->pushBack(n1);
                if (n1 == list1->last) {
                    break;
                } else {
                    n1 = n1->next;
                }
            } else {
                break;
            }
        } else if (n1 == nullptr||list1Flag) {
            if (n2 != nullptr&&!list2Flag) {
                result->pushBack(n2);
                if (n2 == list1->last) {
                    break;
                } else {
                    n2 = n2->next;
                }
            } else {
                break;
            }
        } else if (n1->val <= n2->val) {
            result->pushBack(n1);
            if (n1 != list1->last) {
                n1 = n1->next;
            } else {
                list1Flag = 1;
            }
        } else if (n1->val > n2->val) {
            result->pushBack(n2);
            if (n2 != list2->last) {
                n2 = n2->next;
            } else {
                list2Flag = 1;
            }
        }
    }
}

int main() {
    MyList* list1=new MyList();
    MyList* list2 = new MyList();
    int val;
    int n, m;
    MyNode* elem;
    std::cin >> n;
    std::cin >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> val;
        elem = new MyNode(val);
        list1->pushBack(elem);
    }
    for (int i = 0; i < m; i++) {
        std::cin >> val;
        elem = new MyNode(val);
        list2->pushBack(elem);
    }
    MyList* res = new MyList();
    merge(res, list1, list2, n + m);
    res->print();
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
