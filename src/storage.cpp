#include "storage.h"
#include <fstream>
#include <iostream>

void Storage::saveToFile(const std::string& filename,
                         const std::vector<std::string>& data) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Nuk u hap file!" << std::endl;
        return;
    }

    for (const auto& line : data) {
        file << line << std::endl;
    }

    file.close();
}

std::vector<std::string> Storage::readFromFile(const std::string& filename) {
    std::vector<std::string> data;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Nuk u hap file!" << std::endl;
        return data;
    }

    while (getline(file, line)) {
        data.push_back(line);
    }

    file.close();
    return data;
}
