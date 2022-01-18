#include <iostream>
#include <deque>

struct Window {
    std::deque<int> gap;

    int getMin() {
        return gap.front();
    }

    void push(int value) {
        while (!gap.empty() && gap.back() > value) {
            gap.pop_back();
        }
        gap.push_back(value);
    }

    void del(int value) {
        if (!gap.empty() && gap.front() == value) {
            gap.pop_front();
        }
    }
};

int main() {
    int amount;
    int range;
    std::cin >> amount >> range;
    int *elems = new int[amount];
    for (int i = 0; i < amount; ++i) {
        std::cin >> elems[i];
    }
    Window win;
    for (int i = 0; i < amount; ++i) {
        win.push(elems[i]);
        if (i >= range - 1) {
            std::cout << win.getMin() << std::endl;
            win.del(elems[i - range + 1]);
        }
    }
    delete[] elems;
    return 0;
}
