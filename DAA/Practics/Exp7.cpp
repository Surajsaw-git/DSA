#include <iostream>
using namespace std;

#define V 9
#define INF 9999

int main()
{
    int graph[V][V] =
    {
        // 0  1  2  3  4  5  6  7  8
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0,11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9,14, 0, 0, 0 },
        { 0, 0, 0, 9, 0,10, 0, 0, 0 },
        { 0, 0, 4,14,10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8,11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    int parent[V];
    int key[V];
    bool visited[V];

    // Initialize
    for (int i = 0; i < V; i++)
    {
        key[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    // Start from vertex 0
    key[0] = 0;

    // Find V-1 edges
    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;
        int min = INF;

        // Find minimum key vertex
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && key[i] < min)
            {
                min = key[i];
                u = i;
            }
        }

        visited[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print MST
    int total = 0;

    cout << "Prim's MST:\n";
    cout << "Edge\tWeight\n";

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i
             << "\t" << graph[i][parent[i]] << endl;

        total += graph[i][parent[i]];
    }

    cout << "\nTotal MST Weight = " << total << endl;

    return 0;
}
