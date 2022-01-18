#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <string>

int main() {
    int ppp;
    int nnn;
    int kkk;
    std::cin >> ppp >> nnn >> kkk;
    std::map<std::string, int> counter;
    std::vector<std::string> finalists;
    std::vector<int> command;
    std::string unik;
    for (int iter = 0; iter < ppp; ++iter) {
        std::getline(std::cin >> std::ws, unik);
        if (nnn == 0) {
            continue;
        }
        if (counter.find(unik) == counter.end()) {
            counter.insert(std::pair<std::string, int>(unik, 1));
            finalists.push_back(unik);
            command.push_back(iter);
            nnn--;
        } else {
            if (counter[unik] < kkk) {
                finalists.push_back(unik);
                command.push_back(iter);
                nnn--;
            }
            counter[unik]++;
        }
    }
    int num;
    int ccc = 0;
    for (int i = 0; i < ppp; ++i) {
        std::cin >> num;
        if (ccc < command.size() && i == command[ccc]) {
            std::cout << finalists[ccc] << " #" << num << std::endl;
            ccc++;
        }
    }
}
