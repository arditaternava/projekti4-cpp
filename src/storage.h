#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <vector>

class Storage {
public:
    static void saveToFile(const std::string& filename,
                           const std::vector<std::string>& data);

    static std::vector<std::string> readFromFile(const std::string& filename);
};

#endif
