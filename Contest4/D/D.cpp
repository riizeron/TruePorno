#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> Split(std::string str) {
    // std::cout << str << std::endl;
    size_t pos = 0;
    std::vector<std::string> str_vector;

    while ((pos = str.find(':')) != std::string::npos) {
        str_vector.push_back(str.substr(0, pos));
        str.erase(0, pos + 1);
    }

    if (str_vector.size() == 0) {
        str_vector = { "0", "0", str, "0" };
        return str_vector;
    }
    else if (str_vector.size() == 1) {
        str_vector = { "0", str_vector[0], str, "0" };
        return str_vector;
    }
    else {
        return { str_vector[0], str_vector[1], str, "0" };
    }
}

std::vector<int> SimplyfyTime(std::vector<std::string> vec) {
    // std::cout << "qwerty";
    int hour = std::stoi(vec[0]);
    int min = std::stoi(vec[1]);
    int sec = std::stoi(vec[2]);
    int days = std::stoi(vec[3]);
    if (sec >= 60) {
        min += sec / 60;
        sec = sec % 60;
    }
    if (min >= 60) {
        hour += min / 60;
        min = min % 60;
    }
    if (hour >= 24) {
        // std::cout << "hour: " << hour << std::endl;
        days += hour / 24;
        hour = hour % 24;
        // std::cout << "days " << days << std::endl;
    }
    return std::vector<int>{hour, min, sec, days};
}

int main() {
    std::string str_date;
    std::cin >> str_date;
    std::vector<int> int_date_vector = SimplyfyTime(Split(str_date));

    std::string str_interval;
    std::cin >> str_interval;
    std::vector<int> int_interval_vector = SimplyfyTime(Split(str_interval));

    std::vector<std::string> str_result;
    for (size_t i = 0; i < 4; i++) {
        str_result.push_back(std::to_string(int_date_vector[i] + int_interval_vector[i]));
    }

    std::vector<int> int_result = SimplyfyTime(str_result);

    for (size_t i = 0; i < 3; i++) {
        if (int_result[i] < 10)
            std::cout << "0" << int_result[i];
        else
            std::cout << int_result[i];
        if (i != 2) {
            std::cout << ":";
        }
    }
    if (int_result[3] != 0) {
        // std::cout << "days " << int_result[3] << std::endl;
        std::cout << "+" << int_result[3] << " days";
    }
}
