#include <iostream>
#include "storage.h"

int main() {
    std::cout << "Hello from Projekti 4" << std::endl;

    std::vector<std::string> data = {
        "Rreshti 1",
        "Rreshti 2",
        "Rreshti 3"
    };

    Storage::saveToFile("data.txt", data);

    auto readData = Storage::readFromFile("data.txt");

    for (const auto& line : readData) {
        std::cout << line << std::endl;
    }

    return 0;
}
