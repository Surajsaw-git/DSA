#include <iostream>
#include <algorithm>
using namespace std;

#define V 9

struct Edge
{
    int u;
    int v;
    int weight;
};

// Find parent
int findParent(int parent[], int x)
{
    if (parent[x] == x)
        return x;

    return findParent(parent, parent[x]);
}

// Union
void unionSet(int parent[], int rank[], int a, int b)
{
    a = findParent(parent, a);
    b = findParent(parent, b);

    if (rank[a] < rank[b])
    {
        parent[a] = b;
    }
    else if (rank[a] > rank[b])
    {
        parent[b] = a;
    }
    else
    {
        parent[b] = a;
        rank[a]++;
    }
}

// Compare edges by weight
bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

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

    Edge edges[20];
    int edgeCount = 0;

    // Convert adjacency matrix to edge list
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (graph[i][j] != 0)
            {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = graph[i][j];

                edgeCount++;
            }
        }
    }

    // Sort edges according to weight
    sort(edges, edges + edgeCount, compare);

    int parent[V];
    int rank[V];

    // Initialize sets
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    int total = 0;
    int count = 0;

    cout << "Kruskal's MST:\n";
    cout << "Edge\tWeight\n";

    // Select edges
    for (int i = 0; i < edgeCount && count < V - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        // If different sets, add edge
        if (parentU != parentV)
        {
            cout << u << " - " << v
                 << "\t" << w << endl;

            total += w;
            count++;

            unionSet(parent, rank, parentU, parentV);
        }
    }

    cout << "\nTotal MST Weight = " << total << endl;

    return 0;
}
