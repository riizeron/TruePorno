#include <iostream>
#include <map>
#include <string>
#include <utility>

struct DSU {
    std::map<std::string, std::string> fam;

    int depth(std::string name) {
        if (fam[name] == name) {
            return 1;
        }
        return depth(fam[name]) + 1;
    }

    std::string find(std::string name) {
        if (fam[name] == name) {
            return name;
        }
        return find(fam[name]);
    }

    void unite(std::string first, std::string second) {
        if (first != second) {
            fam.insert(std::pair<std::string, std::string>(first, second));
        }
    }
};

int main() {
    int amount;
    std::cin >> amount;
    std::string first;
    std::string second;
    DSU family;
    for (int i = 0; i < amount - 1; ++i) {
        std::cin >> first >> second;
        family.unite(first, second);
    }
    for (auto& item : family.fam) {
        std::cout << item.first << " " << family.depth(item.first) - 2 << std::endl;
    }
}
