#include <iostream>
#include <stack>

int main() {
    int amount;
    std::cin >> amount;
    std::stack<int> values;
    std::stack<int> qwerties;
    int value;
    int64_t counter = 0;
    int64_t qwerty;
    for (int iter = 0; iter < amount; ++iter) {
        std::cin >> value;
        if (!values.empty() && value == values.top()) {
            qwerty = qwerties.top();
            qwerties.pop();
            qwerty++;
            qwerties.push(qwerty);
        } else {
            if (!qwerties.empty() && qwerties.top() >= 3) {
                for (int i = 0; i < qwerties.top(); ++i) {
                    values.pop();
                }
                counter += qwerties.top();
                qwerties.pop();
            }
            if (!values.empty() && value == values.top()) {
                qwerty = qwerties.top();
                qwerties.pop();
                qwerty++;
                qwerties.push(qwerty);
            } else {
                qwerties.push(1);
            }
        }
        values.push(value);
    }
    if (!qwerties.empty() && qwerties.top() >= 3) {
        counter += qwerties.top();
    }
    std::cout << counter << std::endl;
    return 0;
}
