#ifndef GRAPH_H
#define GRAPH_H


#include <unordered_map>
#include <vector>
#include <string>

class Graph {
private:
    // adjacency list
    std::unordered_map<std::string, std::vector<std::string>> adj;

    // ndihmëse
    bool hasCycleDFS(const std::string& node,
                     std::unordered_map<std::string, bool>& visited,
                     std::unordered_map<std::string, bool>& stack);

    void topoDFS(const std::string& node,
                 std::unordered_map<std::string, bool>& visited,
                 std::vector<std::string>& result);

public:
    // shtim / lidhje varësish
    void addDependency(const std::string& from, const std::string& to);

    // kontroll ciklesh
    bool hasCycle();

    // renditje topologjike (learning path)
    std::vector<std::string> learningPath();
};

#endif
