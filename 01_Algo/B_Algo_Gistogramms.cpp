#include <iostream>
#include <stack>

struct Column {
    int position;
    int value;
};

int main() {
    int amount;
    std::cin >> amount;
    std::stack<Column> st;
    Column col;
    col = {0, -1};
    st.push(col);

    int final_area = 0;
    int current_area;
    int position;
    int value;
    int top_value;
    for (int iter = 1; iter <= amount + 1; ++iter) {
        if (iter > amount) {
            value = 0;
        } else {
            std::cin >> value;
        }

        position = iter;

        while (value <= st.top().value) {
            position = st.top().position;
            top_value = st.top().value;
            current_area = 1LL * top_value * (iter - position);
            if (current_area > final_area) {
                final_area = current_area;
            }
            st.pop();
        }
        col = {position, value};
        st.push(col);
    }
    std::cout << final_area << std::endl;
    return 0;
}
