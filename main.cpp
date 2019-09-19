#include <iostream>
#include <vector>
#include "common.h"
int main() {

    std::vector<int> integers = parseInts("23,4,56");
    for (const auto &item : integers) {
        std::cout << item << std::endl;
    }

    return 0;
}