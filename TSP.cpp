#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define V 4 // Number of vertices/cities

int travellingSalesmanProblem(int graph[][V], int s) {
    vector<int> vertex;
    for (int i = 0; i < V; i++) {
        if (i != s)
            vertex.push_back(i);
    }

    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];

        min_path = min(min_path, current_pathweight);
    } while (next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

int main() {
    int graph[][V] = {{0, 10, 15, 20},
                      {10, 0, 35, 25},
                      {15, 35, 0, 30},
                      {20, 25, 30, 0}};
    int s = 0; // Starting vertex

    cout << "Graph of cities:" << endl;
    for (int x = 0; x < V; x++) {
        for (int y = 0; y < V; y++) {
            cout << graph[x][y] << " ";
        }
        cout << endl;
    }

    cout << "Minimum traveling cost: " << travellingSalesmanProblem(graph, s) << endl;

    return 0;
}
