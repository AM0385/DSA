#include <iostream>
#include <vector>
using namespace std;

void DFSUtil(vector<vector<int>>& graph, int v, vector<bool>& visited, int depth) {
    visited[v] = true;

    for (int i = 0; i < depth; ++i)
        cout << "  "; // Add spaces to simulate tree-like structure

    cout << "|-- " << v << endl; // Print current node with depth indicator

    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            DFSUtil(graph, neighbor, visited, depth + 1);
        }
    }
}

void DFS(vector<vector<int>>& graph, int start) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);

    cout << "DFS Traversal in tree order starting from node " << start << ":" << endl;
    DFSUtil(graph, start, visited, 0);
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

    DFS(graph, 0); // Start DFS from node 0

    return 0;
}
