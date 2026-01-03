#include <iostream>
#include <vector>
#include <string>
#include "graph.h"

int main()
{
    std::cout << "Hello from Projekti 4" << std::endl;
    return 0;
    Graph g;

    g.addDependency("Programim 1", "Programim 2");
    g.addDependency("Programim 2", "Struktura");

    if (g.hasCycle())
    {
        std::cout << "❌ Ka cikël\n";
    }
    else
    {
        std::cout << "✅ Learning Path:\n";
        for (auto &s : g.learningPath())
            std::cout << s << std::endl;
    }
}
