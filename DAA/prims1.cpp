#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int V = 9;

    // Adjacency matrix
    vector<vector<int>> graph(V, vector<int>(V, 0));

    // Add edges
    graph[0][1] = 4;
    graph[1][0] = 4;

    graph[0][7] = 8;
    graph[7][0] = 8;

    graph[1][2] = 8;
    graph[2][1] = 8;

    graph[1][7] = 11;
    graph[7][1] = 11;

    graph[2][3] = 7;
    graph[3][2] = 7;

    graph[2][8] = 2;
    graph[8][2] = 2;

    graph[2][5] = 4;
    graph[5][2] = 4;

    graph[3][4] = 9;
    graph[4][3] = 9;

    graph[3][5] = 14;
    graph[5][3] = 14;

    graph[4][5] = 10;
    graph[5][4] = 10;

    graph[5][6] = 2;
    graph[6][5] = 2;

    graph[6][7] = 1;
    graph[7][6] = 1;

    graph[6][8] = 6;
    graph[8][6] = 6;

    graph[7][8] = 7;
    graph[8][7] = 7;


    // key[i] = minimum weight required
    // to connect vertex i to MST
    vector<int> key(V, INT_MAX);

    // parent[i] = parent of vertex i in MST
    vector<int> parent(V, -1);

    // visited[i] = true if vertex is already in MST
    vector<bool> visited(V, false);


    // Start from vertex 0
    key[0] = 0;

    int totalWeight = 0;

    // We need V vertices
    for (int count = 0; count < V; count++)
    {
        // Find the unvisited vertex
        // having minimum key value
        int u = -1;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }

        // Add vertex u to MST
        visited[u] = true;

        // Update its neighbouring vertices
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
    cout << "Edges in Minimum Spanning Tree:\n";

    cout << "Edge\tWeight\n";

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i
             << "\t" << graph[i][parent[i]] << endl;

        totalWeight += graph[i][parent[i]];
    }

    cout << "\nTotal weight of MST = "
         << totalWeight << endl;

    return 0;
}