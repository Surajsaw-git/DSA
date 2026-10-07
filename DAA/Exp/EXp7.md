# EXPERIMENT 7 — PRIM'S ALGORITHM

This is the **last experiment** in your list. We will learn it from absolute basics and then do the C++ implementation, dry run, complexity, and viva questions.

---

# 1. First understand the problem

Suppose there are several offices:

* Office A
* Office B
* Office C
* Office D
* Office E

We want to connect **all offices using telephone lines**.

Each possible connection has a different cost.

For example:

```text
A ----4---- B
|           |
2           3
|           |
C ----1---- D
```

Our goal is:

> Connect **all offices** with the **minimum possible total cost**.

This is exactly the type of problem solved by **Minimum Spanning Tree (MST)** algorithms.

Two important algorithms for MST are:

1. **Prim's Algorithm**
2. **Kruskal's Algorithm**

Our experiment is **Prim's Algorithm**.

---

# 2. Before Prim's Algorithm — understand Graph

A **graph** is a collection of:

* **Vertices (nodes)**
* **Edges (connections)**

For example:

```text
       4
   A-------B
   |       |
  2|       |3
   |       |
   C-------D
       1
```

Here:

### Vertices

```text
A, B, C, D
```

There are 4 vertices.

### Edges

```text
A-B
A-C
B-D
C-D
```

There are 4 edges.

---

# 3. Weighted Graph

If every edge has a value such as cost, distance, time, etc., it is called a **weighted graph**.

Example:

```text
A ----4---- B
|           |
2           3
|           |
C ----1---- D
```

The numbers are **weights**.

In our office problem:

> Weight = cost of telephone line.

For example:

```text
A ----10---- B
```

means connecting A and B costs ₹10.

---

# 4. What is a Spanning Tree?

Suppose we have:

```text
A
|\
| \
B--C
```

A **spanning tree** is a tree that:

1. Contains **all vertices**
2. Connects all vertices
3. Contains **no cycle**

For 4 vertices, a spanning tree will always have:

$$
V-1
$$

edges.

So if:

```text
V = 5
```

then spanning tree has:

```text
5 - 1 = 4 edges
```

### Important viva point

> A spanning tree connects all vertices without forming a cycle.

---

# 5. What is Minimum Spanning Tree?

There can be multiple spanning trees for the same graph.

We want the spanning tree having the **minimum total edge weight**.

That is called:

> **Minimum Spanning Tree (MST)**

Example:

Suppose we have:

```text
A ----4---- B
|           |
2           3
|           |
C ----1---- D
```

Possible spanning tree:

```text
A ----4---- B
|
2
|
C ----1---- D
```

Total:

$$
4+2+1=7
$$

Another spanning tree could be:

```text
A ----4---- B
            |
            3
            |
            D
            |
            1
            |
            C
```

Total:

$$
4+3+1=8
$$

Therefore the first one is better.

---

# 6. What is Prim's Algorithm?

Now the important definition.

> **Prim's Algorithm is a greedy algorithm used to find the Minimum Spanning Tree of a connected, weighted, undirected graph.**

It starts from **one vertex** and gradually grows the MST.

At every step:

> Choose the minimum-weight edge that connects a selected vertex to an unselected vertex.

This is the main idea you must remember.

---

# 7. Why is Prim's Algorithm called Greedy?

Because at every step it makes the **locally cheapest choice**.

Suppose from the currently selected vertices we have:

```text
A ----2---- B

A ----5---- C

B ----3---- D
```

The available edges have costs:

```text
2
5
3
```

Prim chooses:

```text
2
```

because it is the smallest available edge.

It doesn't try every possible complete tree.

It keeps making the best immediate choice.

Therefore:

> **Prim's Algorithm is a Greedy Algorithm.**

---

# 8. How Prim's Algorithm works

The algorithm maintains three important things.

### 1. visited[]

It tells us:

> Has this vertex already been included in the MST?

Example:

```text
visited[A] = true
```

means A is already selected.

---

### 2. key[]

`key[i]` stores:

> The minimum edge cost currently known to connect vertex `i` to the MST.

For example:

```text
key[B] = 4
```

means the cheapest known connection from the current MST to B costs 4.

---

### 3. parent[]

`parent[i]` tells us:

> From which vertex should we connect vertex `i`?

For example:

```text
parent[B] = A
```

means:

```text
A ----4---- B
```

will be part of the MST.

---

# 9. Simple Prim's Algorithm Steps

Remember these steps for your viva.

### Step 1

Choose any starting vertex.

For example:

```text
A
```

### Step 2

Mark A as selected.

### Step 3

Look at all edges from A to unselected vertices.

### Step 4

Choose the edge having minimum weight.

### Step 5

Add that vertex to MST.

### Step 6

Update the minimum connection cost of neighboring unselected vertices.

### Step 7

Repeat until all vertices are selected.

---

# 10. Example Graph

Let's use this graph for our complete dry run:

```text
        2
   A -------- B
   | \        |
 6 |  \5      | 3
   |    \     |
   C ---- D --+
    \    | 
    1\   |4
       \  |
        E
```

Let's make it easier to understand with an edge list:

```text
A-B = 2
A-C = 6
A-D = 5
B-D = 3
C-D = 1
C-E = 2
D-E = 4
```

We have:

```text
Vertices = A, B, C, D, E
```

---

# 11. Adjacency Matrix

Since you are implementing this in C++, an **adjacency matrix** is very easy to understand.

We'll represent:

```text
A = 0
B = 1
C = 2
D = 3
E = 4
```

Our matrix is:

|   |  A |  B |  C |  D |  E |
| - | -: | -: | -: | -: | -: |
| A |  0 |  2 |  6 |  5 |  0 |
| B |  2 |  0 |  0 |  3 |  0 |
| C |  6 |  0 |  0 |  1 |  2 |
| D |  5 |  3 |  1 |  0 |  4 |
| E |  0 |  0 |  2 |  4 |  0 |

Here:

```text
0 = no direct edge
```

For example:

```text
graph[A][B] = 2
```

means:

```text
A ----2---- B
```

And:

```text
graph[C][D] = 1
```

means:

```text
C ----1---- D
```

Because the graph is undirected:

```text
graph[A][B] == graph[B][A]
```

---

# 12. Initial Values

Suppose we start from vertex A.

Initially:

```text
key:
A = 0
B = INF
C = INF
D = INF
E = INF
```

Why A = 0?

Because A is our starting vertex.

`INF` means:

> We currently don't know a connection cost for that vertex.

Parent:

```text
A = -1
B = -1
C = -1
D = -1
E = -1
```

Visited:

```text
A = false
B = false
C = false
D = false
E = false
```

---

# 13. Step 1 — Select A

The smallest key is:

```text
A = 0
```

So select A.

```text
visited[A] = true
```

Now inspect A's neighbors:

```text
A-B = 2
A-C = 6
A-D = 5
```

Update:

```text
key[B] = 2
parent[B] = A

key[C] = 6
parent[C] = A

key[D] = 5
parent[D] = A
```

E has no direct connection with A.

Current state:

| Vertex | Key | Parent | Visited |
| ------ | --: | ------ | ------- |
| A      |   0 | -      | Yes     |
| B      |   2 | A      | No      |
| C      |   6 | A      | No      |
| D      |   5 | A      | No      |
| E      | INF | -      | No      |

---

# 14. Step 2 — Select B

Among unvisited vertices:

```text
B = 2
C = 6
D = 5
E = INF
```

Smallest:

```text
B = 2
```

Select B.

MST edge:

```text
A ----2---- B
```

Now inspect B's neighbors.

B is connected to:

```text
A = 2
D = 3
```

A is already visited.

D has:

```text
current key[D] = 5
```

But B provides a cheaper connection:

```text
B-D = 3
```

Therefore update:

```text
key[D] = 3
parent[D] = B
```

Current:

| Vertex | Key | Parent | Visited |
| ------ | --: | ------ | ------- |
| A      |   0 | -      | Yes     |
| B      |   2 | A      | Yes     |
| C      |   6 | A      | No      |
| D      |   3 | B      | No      |
| E      | INF | -      | No      |

---

# 15. Step 3 — Select D

Unvisited:

```text
C = 6
D = 3
E = INF
```

Smallest:

```text
D = 3
```

Select D.

MST edge:

```text
B ----3---- D
```

Now inspect D's neighbors:

```text
A = 5
B = 3
C = 1
E = 4
```

A and B are already visited.

Now C:

Current:

```text
key[C] = 6
```

But:

```text
D-C = 1
```

So update:

```text
key[C] = 1
parent[C] = D
```

Now E:

```text
key[E] = INF
```

D gives:

```text
D-E = 4
```

So:

```text
key[E] = 4
parent[E] = D
```

Current:

| Vertex | Key | Parent | Visited |
| ------ | --: | ------ | ------- |
| A      |   0 | -      | Yes     |
| B      |   2 | A      | Yes     |
| C      |   1 | D      | No      |
| D      |   3 | B      | Yes     |
| E      |   4 | D      | No      |

---

# 16. Step 4 — Select C

Unvisited:

```text
C = 1
E = 4
```

Smallest:

```text
C = 1
```

Select C.

MST edge:

```text
D ----1---- C
```

Inspect C's neighbors:

```text
A = 6
D = 1
E = 2
```

A and D are already visited.

E:

Current:

```text
key[E] = 4
```

But:

```text
C-E = 2
```

is cheaper.

So update:

```text
key[E] = 2
parent[E] = C
```

Current:

| Vertex | Key | Parent | Visited |
| ------ | --: | ------ | ------- |
| A      |   0 | -      | Yes     |
| B      |   2 | A      | Yes     |
| C      |   1 | D      | Yes     |
| D      |   3 | B      | Yes     |
| E      |   2 | C      | No      |

---

# 17. Step 5 — Select E

Only E remains.

```text
key[E] = 2
```

Select E.

MST edge:

```text
C ----2---- E
```

All vertices are now selected.

---

# 18. Final Minimum Spanning Tree

The selected edges are:

```text
A ----2---- B
             |
             3
             |
             D
            /
           1
          /
         C
         |
         2
         |
         E
```

Edges:

```text
A-B = 2
B-D = 3
D-C = 1
C-E = 2
```

Total cost:

$$
2+3+1+2
$$

$$
=8
$$

Therefore:

> **Minimum Spanning Tree Cost = 8**

---

# 19. Most Important Dry Run Table

For your jury, remember this table:

| Step | Selected Vertex | Edge Added | Cost |
| ---- | --------------- | ---------- | ---: |
| 1    | A               | Start      |    0 |
| 2    | B               | A-B        |    2 |
| 3    | D               | B-D        |    3 |
| 4    | C               | D-C        |    1 |
| 5    | E               | C-E        |    2 |

Total:

$$
2+3+1+2=\boxed{8}
$$

---

# 20. Now the C++ Code

Here is a **simple adjacency-matrix implementation**.

```cpp
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
```

---

# 21. Understand the Code Part by Part

Don't try to memorize the entire code.

Understand the **four important parts**.

---

## Part 1 — Graph

```cpp
int graph[10][10];
```

This creates an adjacency matrix.

For example:

```text
graph[0][1] = 2
```

means vertex 0 and vertex 1 have an edge of weight 2.

---

# 22. INF

```cpp
#define INF 9999
```

`INF` means infinity.

We use it when there is no direct connection.

For example:

```text
A ----2---- B

A          C
```

If A and C aren't connected:

```cpp
graph[A][C] = INF;
```

This tells Prim:

> Don't consider this as a real edge.

---

# 23. The Three Important Arrays

```cpp
int key[10];
int parent[10];
bool visited[10];
```

### key[]

Stores the minimum edge cost.

### parent[]

Stores where the vertex came from.

### visited[]

Stores whether the vertex has already entered MST.

This is extremely important for viva.

---

# 24. Initialization

```cpp
for (int i = 0; i < n; i++)
{
    key[i] = INF;
    parent[i] = -1;
    visited[i] = false;
}
```

Initially:

```text
No vertex selected
No parent
No known minimum edge
```

So:

```text
key = INF
parent = -1
visited = false
```

---

# 25. Starting Vertex

```cpp
key[0] = 0;
```

We start from vertex 0.

Remember:

> Prim can start from any vertex.

Why zero?

Because in C++ our first vertex is represented by index 0.

---

# 26. Find Minimum Key

This is one of the most important parts:

```cpp
int u = -1;

for (int i = 0; i < n; i++)
{
    if (!visited[i] && (u == -1 || key[i] < key[u]))
    {
        u = i;
    }
}
```

Meaning:

> Find the unvisited vertex having the smallest key value.

Suppose:

```text
key:
A = 0
B = 2
C = 6
D = 5
E = INF
```

Then:

```text
A
```

is selected first.

Later:

```text
B = 2
C = 6
D = 5
```

so B is selected.

---

# 27. Mark Vertex

```cpp
visited[u] = true;
```

This means:

> This vertex is now part of the MST.

---

# 28. Print MST Edge

```cpp
if (parent[u] != -1)
{
    cout << parent[u] << " - " << u
         << " : " << graph[parent[u]][u] << endl;

    totalCost += graph[parent[u]][u];
}
```

Suppose:

```text
parent[D] = B
```

and:

```text
B-D = 3
```

Then:

```text
B - D : 3
```

is printed.

And:

```cpp
totalCost += 3;
```

---

# 29. Update Neighboring Vertices

This is the **heart of Prim's Algorithm**.

```cpp
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
```

Let's understand it.

Suppose we selected D.

D is connected to:

```text
C = 1
E = 4
```

If:

```text
key[C] = 6
```

and:

```text
D-C = 1
```

then:

```cpp
1 < 6
```

So:

```cpp
key[C] = 1;
parent[C] = D;
```

That means:

> C can now be connected to the MST through D at cost 1.

---

# 30. Why Do We Need Parent[]?

Suppose we only had:

```text
key[C] = 1
```

We know the cost but not where the edge comes from.

`parent[C]` tells us:

```text
parent[C] = D
```

Therefore:

```text
D ----1---- C
```

is the MST edge.

So:

> `key[]` tells us **cost** and `parent[]` tells us **connection**.

---

# 31. Input for Our Example

If:

```text
A = 0
B = 1
C = 2
D = 3
E = 4
```

Input:

```text
5

0 2 6 5 0
2 0 0 3 0
6 0 0 1 2
5 3 1 0 4
0 0 2 4 0
```

Output will be similar to:

```text
Edges in Minimum Spanning Tree:
0 - 1 : 2
1 - 3 : 3
3 - 2 : 1
2 - 4 : 2

Minimum Cost = 8
```

---

# 32. Why Does Prim Not Create a Cycle?

This is a common viva question.

Because we only connect:

```text
selected vertex → unvisited vertex
```

The condition:

```cpp
!visited[v]
```

ensures that the new edge goes to an unselected vertex.

Therefore we don't connect two already selected vertices.

So a cycle is avoided.

---

# 33. Prim's Algorithm Complexity

Our implementation uses an **adjacency matrix**.

We repeatedly search for the minimum key.

Therefore:

$$
\boxed{O(V^2)}
$$

### Space complexity

Adjacency matrix requires:

$$
O(V^2)
$$

The arrays require:

```text
key → O(V)
parent → O(V)
visited → O(V)
```

But the matrix dominates.

Therefore:

$$
\boxed{O(V^2)}
$$

---

# 34. Can Prim Be Implemented Using Adjacency List?

Yes.

With:

* adjacency list
* min-priority queue / min-heap

complexity can be:

$$
\boxed{O(E\log V)}
$$

Space:

$$
\boxed{O(V+E)}
$$

But for your practical, **adjacency matrix is much easier to understand and implement**.

---

# 35. Adjacency Matrix vs Adjacency List

| Feature           | Matrix       | List                 |
| ----------------- | ------------ | -------------------- |
| Representation    | 2D array     | Lists of neighbors   |
| Space             | O(V²)        | O(V+E)               |
| Easy to implement | Yes          | Moderate             |
| Good for          | Dense graphs | Sparse graphs        |
| Our Prim code     | O(V²)        | O(E log V) with heap |

### Jury answer

If professor asks:

> Which data structure did you use?

Say:

> "I used an adjacency matrix because it provides simple edge-weight access and makes the O(V²) implementation of Prim's algorithm straightforward."

---

# 36. Prim vs Kruskal

This is **very important for viva** because both find MST.

| Prim                                                  | Kruskal                            |
| ----------------------------------------------------- | ---------------------------------- |
| Starts from a vertex                                  | Starts from edges                  |
| Grows one tree                                        | Builds forest and joins components |
| Selects minimum edge connecting MST to outside vertex | Selects globally smallest edge     |
| Uses visited/key/parent                               | Uses sorting + Union-Find          |
| Good for dense graphs                                 | Good for sparse graphs             |
| Matrix implementation is easy                         | Edge-list implementation is common |
| O(V²) with matrix                                     | O(E log E) mainly due sorting      |

### Simple difference

Remember:

> **Prim = vertex-based growth**

> **Kruskal = edge-based selection**

---

# 37. Prim vs Dijkstra

Another very common viva question.

Students often confuse them.

### Prim

Finds:

> Minimum Spanning Tree.

Goal:

> Connect **all vertices** with minimum total edge cost.

### Dijkstra

Finds:

> Shortest paths from one source vertex to other vertices.

Goal:

> Find minimum distance from a source.

So:

```text
Prim → MST
Dijkstra → Shortest Path
```

Don't say they are the same algorithm.

---

# 38. Conditions for Prim's Algorithm

Prim's algorithm is normally applied to a:

* connected
* undirected
* weighted graph.

### Connected

Every vertex should be reachable from the others.

If graph is disconnected, there is no single spanning tree covering all vertices.

---

# 39. Why Does the Office Problem Use Prim?

Original problem:

> Several offices need to be connected using telephone lines with minimum total cost.

We can represent:

```text
Office = Vertex
Telephone line = Edge
Line cost = Weight
```

We want:

```text
All offices connected
+
No unnecessary cycles
+
Minimum total cost
```

That is exactly:

> **Minimum Spanning Tree**

Therefore:

> **Prim's Algorithm is suitable.**

---

# 40. Strong Jury Answer

If your professor asks:

### "Explain your experiment."

You can say:

> "My experiment is to connect all offices using telephone lines with minimum total cost. I model each office as a vertex and each possible telephone connection as a weighted edge, where the weight represents the connection cost. Since the objective is to connect all vertices with minimum total edge cost without cycles, the problem is a Minimum Spanning Tree problem. I use Prim's Algorithm, which is a greedy algorithm. It starts from any vertex and repeatedly selects the minimum-weight edge connecting the current MST to an unvisited vertex. In my implementation, I use an adjacency matrix along with key, parent and visited arrays. The time complexity is O(V²) and space complexity is O(V²)."

That is an **excellent 5-mark/viva explanation**.

---

# 41. Important Viva Questions

### Q1. What is Prim's Algorithm?

**Answer:**

> Prim's Algorithm is a greedy algorithm used to find the Minimum Spanning Tree of a connected weighted undirected graph.

---

### Q2. What is MST?

**Answer:**

> Minimum Spanning Tree is a spanning tree having the minimum possible total edge weight.

---

### Q3. Why is Prim greedy?

**Answer:**

> At every step it chooses the minimum-weight edge that connects the current MST to an unvisited vertex.

---

### Q4. How many edges does an MST contain?

For V vertices:

$$
\boxed{V-1}
$$

---

### Q5. Can Prim create a cycle?

**Answer:**

> No. It only adds an edge to an unvisited vertex, so a cycle is avoided.

---

### Q6. Can Prim start from any vertex?

**Answer:**

> Yes. Any vertex can be selected as the starting vertex. For a connected graph, the resulting MST cost is minimum, although multiple different MSTs may exist.

---

### Q7. What does `key[]` store?

**Answer:**

> It stores the minimum known edge weight required to connect each unvisited vertex to the current MST.

---

### Q8. What does `parent[]` store?

**Answer:**

> It stores the vertex through which the corresponding vertex will be connected to the MST.

---

### Q9. What does `visited[]` store?

**Answer:**

> It indicates whether a vertex has already been included in the MST.

---

### Q10. What is the time complexity of your implementation?

**Answer:**

> Since I use an adjacency matrix and linearly search for the minimum key, the time complexity is O(V²).

---

### Q11. What is the space complexity?

**Answer:**

> O(V²), mainly because of the adjacency matrix.

---

### Q12. What is the difference between Prim and Kruskal?

**Answer:**

> Prim grows the MST from a starting vertex, whereas Kruskal sorts all edges and repeatedly chooses the smallest edge that does not create a cycle.

---

### Q13. What data structure can improve Prim?

**Answer:**

> An adjacency list combined with a min-priority queue or min-heap can implement Prim in O(E log V).

---

### Q14. Is Prim a Divide and Conquer algorithm?

**Answer:**

> No. Prim is a Greedy algorithm.

This is important because your previous experiments included Divide and Conquer.

---

### Q15. Is Prim a Dynamic Programming algorithm?

**Answer:**

> No. Prim is a Greedy algorithm.

---

# 42. The Most Important Things to Memorize

For tomorrow's jury, memorize these **10 points**:

```text
1. Prim → Greedy Algorithm

2. Prim → Minimum Spanning Tree

3. Graph → Connected, Undirected, Weighted

4. Vertex → Office

5. Edge → Telephone connection

6. Weight → Connection cost

7. key[] → Minimum connection cost

8. parent[] → Connection source

9. visited[] → Already selected or not

10. Matrix implementation → O(V²)
```

And:

```text
MST has V - 1 edges
```

---

# 43. Your Entire Experiment in One Flow

Remember this sequence:

```text
Office Problem
      ↓
Represent offices as vertices
      ↓
Connections as weighted edges
      ↓
Need minimum total cost
      ↓
Minimum Spanning Tree
      ↓
Use Prim's Algorithm
      ↓
Choose starting vertex
      ↓
Find minimum edge
      ↓
Add unvisited vertex
      ↓
Update key and parent
      ↓
Repeat
      ↓
All vertices selected
      ↓
MST obtained
      ↓
Calculate total cost
```

---

# 44. Final Comparison of All 7 Experiments

You have now covered your entire experiment list:

| Experiment | Algorithm/Concept     | Main Idea                        | Complexity     |
| ---------- | --------------------- | -------------------------------- | -------------- |
| 1          | Fibonacci             | Recursion vs Iteration           | O(2ⁿ) / O(n)   |
| 2          | Binary Search         | Divide search space              | O(log n)       |
| 3          | Quick Sort            | Divide + Pivot + Partition       | Avg O(n log n) |
| 4          | Merge Sort            | Divide + Merge                   | O(n log n)     |
| 5          | Matrix Multiplication | Matrix operations / optimization | O(n³) standard |
| 6          | Fractional Knapsack   | Greedy profit/weight             | O(n log n)     |
| 7          | Prim                  | Greedy MST                       | O(V²) matrix   |

## The four major algorithm paradigms you've studied

```text
Recursion
    ↓
Binary Search / Fibonacci

Divide and Conquer
    ↓
Quick Sort / Merge Sort

Optimization
    ↓
Matrix Multiplication

Greedy
    ↓
Fractional Knapsack / Prim
```

**For the jury, don't just memorize code.** Be able to explain what each variable is doing, why the algorithm works, and its time/space complexity. Those are the questions most likely to expose whether you actually understand the experiment.
