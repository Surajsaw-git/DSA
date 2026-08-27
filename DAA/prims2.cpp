#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int V = 9;

    int graph[V][V] =
    {
        //  0   1   2   3   4   5   6   7   8
        {   0,  4,  0,  0,  0,  0,  0,  8,  0 }, // 0
        {   4,  0,  8,  0,  0,  0,  0, 11,  0 }, // 1
        {   0,  8,  0,  7,  0,  4,  0,  0,  2 }, // 2
        {   0,  0,  7,  0,  9, 14,  0,  0,  0 }, // 3
        {   0,  0,  0,  9,  0, 10,  0,  0,  0 }, // 4
        {   0,  0,  4, 14, 10,  0,  2,  0,  0 }, // 5
        {   0,  0,  0,  0,  0,  2,  0,  1,  6 }, // 6
        {   8, 11,  0,  0,  0,  0,  1,  0,  7 }, // 7
        {   0,  0,  2,  0,  0,  0,  6,  7,  0 }  // 8
    };

    int key[V];
    int parent[V];
    bool visited[V];

    // Initialize arrays
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }

    // Start from vertex 0
    key[0] = 0;

    // Prim's Algorithm
    for (int count = 0; count < V; count++)
    {
        // Find vertex with minimum key
        int u = -1;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] &&
                (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }

        // Add vertex to MST
        visited[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print MST
    int totalWeight = 0;

    cout << "Edges in Minimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i
             << "\t" << graph[i][parent[i]] << endl;

        totalWeight += graph[i][parent[i]];
    }

    cout << "\nTotal weight = " << totalWeight << endl;

    return 0;
}