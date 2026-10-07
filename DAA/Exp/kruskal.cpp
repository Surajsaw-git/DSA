#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Structure for storing an edge
struct Edge
{
    int u;
    int v;
    int weight;
};


// Find the representative of a set
int findParent(vector<int>& parent, int x)
{
    if (parent[x] == x)
    {
        return x;
    }

    return parent[x] = findParent(parent, parent[x]);
}


// Join two sets
void unionSet(vector<int>& parent,
              vector<int>& rank,
              int u, int v)
{
    int parentU = findParent(parent, u);
    int parentV = findParent(parent, v);

    // If both have same parent,
    // they are already connected
    if (parentU == parentV)
    {
        return;
    }

    // Attach smaller rank tree
    // under larger rank tree
    if (rank[parentU] < rank[parentV])
    {
        parent[parentU] = parentV;
    }
    else if (rank[parentU] > rank[parentV])
    {
        parent[parentV] = parentU;
    }
    else
    {
        parent[parentV] = parentU;
        rank[parentU]++;
    }
}


int main()
{
    int V = 9;

    // Adjacency Matrix
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


    // Store all edges
    vector<Edge> edges;

    // Extract edges from adjacency matrix
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (graph[i][j] != 0)
            {
                Edge e;

                e.u = i;
                e.v = j;
                e.weight = graph[i][j];

                edges.push_back(e);
            }
        }
    }


    // Sort edges according to weight
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b)
         {
             return a.weight < b.weight;
         });


    // DSU arrays
    vector<int> parent(V);
    vector<int> rank(V, 0);


    // Initially every vertex is its own parent
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }


    // Store MST edges
    vector<Edge> MST;

    int totalWeight = 0;


    // Process edges in sorted order
    for (Edge edge : edges)
    {
        int u = edge.u;
        int v = edge.v;

        // Check whether adding this edge
        // creates a cycle
        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        if (parentU != parentV)
        {
            // No cycle, so add edge
            MST.push_back(edge);

            totalWeight += edge.weight;

            // Join the two sets
            unionSet(parent, rank, u, v);
        }

        // MST needs V-1 edges
        if (MST.size() == V - 1)
        {
            break;
        }
    }


    // Print MST
    cout << "Edges in Minimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";

    for (Edge edge : MST)
    {
        cout << edge.u << " - "
             << edge.v << "\t"
             << edge.weight << endl;
    }

    cout << "\nTotal weight = "
         << totalWeight << endl;


    return 0;
}