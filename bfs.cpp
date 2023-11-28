#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            int current = q.front();
            cout << current << " ";
            q.pop();

            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl; // Print new line after each level
    }
}

int main() {
    int numNodes = 6;
    vector<vector<int>> graph(numNodes);

    // Example graph representation
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    cout << "BFS Traversal in tree order starting from node 0:" << endl;
    BFS(graph, 0); // Start BFS from node 0

    return 0;
}
