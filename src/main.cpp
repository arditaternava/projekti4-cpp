#include <iostream>
#include <vector>
#include <string>
#include "storage.h"
#include "graph.h"

int main(int argc, char* argv[])
{
    std::cout << "Hello from Projekti 4" << std::endl;

    // STORAGE
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

    // GRAPH
    Graph g;
    g.addDependency("Programim 1", "Programim 2");
    g.addDependency("Programim 2", "Struktura");

    if (g.hasCycle()) {
        std::cout << "❌ Ka cikël\n";
    } else {
        std::cout << "✅ Learning Path:\n";
        for (auto& s : g.learningPath())
            std::cout << s << std::endl;
    }

    return 0;
}
