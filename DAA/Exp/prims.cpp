#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int V = 6;
    
    vector<vector<int>> graph = {
        {0, 12, 8, 0, 0, 0},
        {12, 0, 9, 22, 0, 11},
        {8, 9, 0, 16, 0, 14},
        {0, 22, 16, 0, 15, 18},
        {0, 0, 0, 15, 0, 3},
        {0, 11, 14, 18, 3, 0}
    };

    vector<int> parent(V);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u;

        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    char nodes[] = {'S', 'A', 'B', 'C', 'D', 'E'};
    int totalWeight = 0;
    
    for (int i = 1; i < V; i++) {
        cout << nodes[parent[i]] << " - " << nodes[i] << " : " << graph[i][parent[i]] << "\n";
        totalWeight += graph[i][parent[i]];
    }
    
    cout << "\nTotal MST Weight: " << totalWeight << "\n";

    return 0;
}