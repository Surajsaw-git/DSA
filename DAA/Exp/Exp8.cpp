#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u;
    int v;
    int weight;
};

bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int parent[10];

int findParent(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent[x]);
}

void unionSets(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    parent[b] = a;
}

int main()
{
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    Edge graph[20];

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < edges; i++)
    {
        cin >> graph[i].u
            >> graph[i].v
            >> graph[i].weight;
    }

    // Initially every vertex is its own parent
    for (int i = 0; i < vertices; i++)
    {
        parent[i] = i;
    }

    // Sort edges by weight
    sort(graph, graph + edges, compare);

    int totalCost = 0;
    int selectedEdges = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int i = 0; i < edges; i++)
    {
        int u = graph[i].u;
        int v = graph[i].v;

        int parentU = findParent(u);
        int parentV = findParent(v);

        // If different components, add edge
        if (parentU != parentV)
        {
            cout << u << " - " << v
                 << " : " << graph[i].weight << endl;

            totalCost += graph[i].weight;

            unionSets(u, v);

            selectedEdges++;

            if (selectedEdges == vertices - 1)
                break;
        }
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}