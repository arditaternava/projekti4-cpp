#include "graph.h"
#include <algorithm>

// 1️⃣ shtim / lidhje varësish
void Graph::addDependency(const std::string& from,
                          const std::string& to) {
    adj[from].push_back(to);
    adj[to]; // siguron që nyja ekziston
}

// 2️⃣ kontroll ciklesh (DFS)
bool Graph::hasCycleDFS(const std::string& node,
                        std::unordered_map<std::string, bool>& visited,
                        std::unordered_map<std::string, bool>& stack) {
    visited[node] = true;
    stack[node] = true;

    for (const auto& next : adj[node]) {
        if (!visited[next] && hasCycleDFS(next, visited, stack))
            return true;
        else if (stack[next])
            return true;
    }

    stack[node] = false;
    return false;
}

bool Graph::hasCycle() {
    std::unordered_map<std::string, bool> visited, stack;

    for (const auto& p : adj) {
        if (!visited[p.first]) {
            if (hasCycleDFS(p.first, visited, stack))
                return true;
        }
    }
    return false;
}

// 3️⃣ renditje topologjike
void Graph::topoDFS(const std::string& node,
                    std::unordered_map<std::string, bool>& visited,
                    std::vector<std::string>& result) {
    visited[node] = true;

    for (const auto& next : adj[node]) {
        if (!visited[next])
            topoDFS(next, visited, result);
    }

    result.push_back(node);
}

std::vector<std::string> Graph::learningPath() {
    std::unordered_map<std::string, bool> visited;
    std::vector<std::string> result;

    for (const auto& p : adj) {
        if (!visited[p.first])
            topoDFS(p.first, visited, result);
    }

    std::reverse(result.begin(), result.end());
    return result;
}
