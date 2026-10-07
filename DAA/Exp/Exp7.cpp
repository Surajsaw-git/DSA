#include <iostream>
using namespace std;

#define INF 9999

int main()
{
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[10][10];

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];

            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    int key[10];
    int parent[10];
    bool visited[10];

    // Initialize arrays
    for (int i = 0; i < n; i++)
    {
        key[i] = INF;
        parent[i] = -1;
        visited[i] = false;
    }

    // Start from vertex 0
    key[0] = 0;

    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int count = 0; count < n; count++)
    {
        // Find vertex with minimum key
        int u = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }

        // Mark selected vertex
        visited[u] = true;

        // Add edge to MST
        if (parent[u] != -1)
        {
            cout << parent[u] << " - " << u
                 << " : " << graph[parent[u]][u] << endl;

            totalCost += graph[parent[u]][u];
        }

        // Update neighboring vertices
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != INF &&
                !visited[v] &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}