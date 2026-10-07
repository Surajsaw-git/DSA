Absolutely. **Experiment 8 is Kruskal's Algorithm**, and it is very closely related to Experiment 7 (Prim's Algorithm) because **both are used to find a Minimum Spanning Tree (MST)**.

Your experiment statement says:

> Connect every city zone while minimizing the total underground cable installation cost.

So let's first understand the problem, then Kruskal's algorithm, then the data structures, and finally we'll do a complete C++ implementation and dry run.

---

# EXPERIMENT 8 — KRUSKAL'S ALGORITHM

## 1. Understand the problem statement

Your problem says:

> An energy company wants to lay underground power lines between different city zones. Every possible connection has a different cost. Connect every zone with minimum total cost.

For example, suppose we have five zones:

```text
A, B, C, D, E
```

Possible cable connections:

```text
A ---- 4 ---- B
A ---- 2 ---- C
B ---- 3 ---- D
C ---- 1 ---- D
C ---- 5 ---- E
D ---- 4 ---- E
```

The numbers represent:

> **Cost of laying cable between two zones.**

Our objective is:

```text
Connect ALL zones
        +
Minimum total cost
        +
No unnecessary cycles
```

This is exactly a **Minimum Spanning Tree problem**.

And one of the algorithms used to solve MST is:

# Kruskal's Algorithm

---

# 2. First understand MST again

Before learning Kruskal, you must know three terms:

### Graph

A collection of:

* vertices
* edges

Example:

```text
A ---- B
|      |
C ---- D
```

---

### Weighted Graph

If edges have costs:

```text
A --5-- B
|       |
2       3
|       |
C --1-- D
```

then it is a **weighted graph**.

For our problem:

```text
Vertex = City zone
Edge = Cable route
Weight = Cable installation cost
```

---

# 3. What is a Spanning Tree?

A spanning tree:

1. Contains all vertices.
2. Connects all vertices.
3. Contains no cycle.

For `V` vertices:

$$
\boxed{\text{Number of edges} = V-1}
$$

For example, if we have:

```text
5 zones
```

the spanning tree must have:

$$
5-1=4
$$

edges.

---

# 4. What is Minimum Spanning Tree?

There can be many different spanning trees.

We want the one having the **minimum total cost**.

That is:

> **Minimum Spanning Tree (MST)**

Example:

```text
A --2-- B
|       |
4       3
|       |
C --1-- D
```

One possible spanning tree:

```text
A --2-- B
        |
        3
        |
        D
        |
        1
        |
        C
```

Cost:

$$
2+3+1=6
$$

If another spanning tree costs 9, then the one costing 6 is the MST.

---

# 5. What is Kruskal's Algorithm?

Now the most important definition:

> **Kruskal's Algorithm is a greedy algorithm used to find the Minimum Spanning Tree of a weighted undirected graph.**

Its basic strategy is very simple:

> **Sort all edges by increasing weight and keep selecting the cheapest edge, provided it does not create a cycle.**

That's the entire idea.

Remember:

```text
SORT EDGES
     ↓
CHEAPEST EDGE FIRST
     ↓
CHECK CYCLE
     ↓
NO CYCLE → ADD
     ↓
CYCLE → REJECT
     ↓
REPEAT
```

---

# 6. Why is Kruskal a Greedy Algorithm?

Because it always tries to make the cheapest possible choice.

Suppose the edges are:

```text
A-B = 8
A-C = 2
B-C = 5
C-D = 1
```

Kruskal looks at:

```text
1
2
5
8
```

and starts with the cheapest:

```text
C-D = 1
```

Then:

```text
A-C = 2
```

Then:

```text
B-C = 5
```

and so on.

So:

> Kruskal makes a locally cheapest choice at each step.

Therefore it is a **Greedy Algorithm**.

---

# 7. The biggest difference from Prim

This is extremely important for your jury.

### Prim

Prim starts with a vertex.

```text
Start at A
   ↓
Find cheapest edge connected to current tree
   ↓
Add vertex
   ↓
Continue
```

### Kruskal

Kruskal starts with **edges**.

```text
Take ALL edges
      ↓
Sort them by cost
      ↓
Take cheapest edge
      ↓
Check cycle
      ↓
Add/reject
```

So remember:

> **Prim = Vertex based**

> **Kruskal = Edge based**

---

# 8. Example Graph

Let's use this graph throughout our experiment.

```text
        2
   A -------- B
   | \        |
  6|  \5      |3
   |    \     |
   C ---- D --+
    \    |
    2\   |4
       \ |
        E
```

Let's clearly list all edges:

| Edge | Cost |
| ---- | ---: |
| A-B  |    2 |
| A-C  |    6 |
| A-D  |    5 |
| B-D  |    3 |
| C-D  |    1 |
| C-E  |    2 |
| D-E  |    4 |

We have:

```text
Vertices = 5
Edges = 7
```

---

# 9. First Step of Kruskal — Sort Edges

This is the **first major step**.

Original edges:

```text
A-B = 2
A-C = 6
A-D = 5
B-D = 3
C-D = 1
C-E = 2
D-E = 4
```

Sort in ascending order:

| Order | Edge | Cost |
| ----: | ---- | ---: |
|     1 | C-D  |    1 |
|     2 | A-B  |    2 |
|     3 | C-E  |    2 |
|     4 | B-D  |    3 |
|     5 | D-E  |    4 |
|     6 | A-D  |    5 |
|     7 | A-C  |    6 |

This is different from Prim.

Prim doesn't necessarily sort **all edges** first.

Kruskal does.

---

# 10. Now select edges one by one

We need:

$$
V-1
$$

edges.

We have:

```text
V = 5
```

Therefore:

$$
5-1=4
$$

We need **4 edges**.

---

# 11. Step 1 — C-D = 1

Cheapest edge:

```text
C ----1---- D
```

If we add it:

```text
C ----1---- D
```

There is no cycle.

So:

> **Accept C-D**

Current MST:

```text
C ----1---- D
```

Total cost:

$$
1
$$

---

# 12. Step 2 — A-B = 2

Next cheapest:

```text
A ----2---- B
```

Does this create a cycle?

Current:

```text
C ---- D
```

A and B are not connected to them.

So no cycle.

Therefore:

> **Accept A-B**

MST now:

```text
A ----2---- B


C ----1---- D
```

Total:

$$
1+2=3
$$

---

# 13. Step 3 — C-E = 2

Next:

```text
C ----2---- E
```

Current components are:

```text
A-B
```

and

```text
C-D
```

E is separate.

Adding C-E:

```text
C ----1---- D
|
2
|
E
```

No cycle.

So:

> **Accept C-E**

Total:

$$
1+2+2=5
$$

---

# 14. Step 4 — B-D = 3

Next:

```text
B ----3---- D
```

Current components:

```text
A-B
```

and:

```text
C-D-E
```

B belongs to the first component.

D belongs to the second component.

Therefore connecting them will **not create a cycle**.

Accept:

```text
A --2-- B
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

Total:

$$
1+2+2+3
$$

$$
=\boxed{8}
$$

We now have:

```text
4 edges
```

and:

```text
V - 1 = 4
```

So we are finished.

---

# 15. Final MST

Our MST is:

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

Selected edges:

```text
C-D = 1
A-B = 2
C-E = 2
B-D = 3
```

Total:

$$
\boxed{8}
$$

---

# 16. What if an edge creates a cycle?

This is the most important part of Kruskal.

Suppose after selecting:

```text
C-D
A-B
C-E
B-D
```

we consider:

```text
D-E = 4
```

Look at the current MST:

```text
A -- B
     |
     D
    /
   C
   |
   E
```

D and E are **already connected** through:

```text
D → B → A
```

and E through:

```text
D → C → E
```

So adding:

```text
D-E
```

would create a cycle:

```text
D ---- E
|       |
C-------+
```

Therefore:

> **Reject D-E.**

This is why Kruskal needs a way to detect cycles.

---

# 17. How do we detect cycles efficiently?

This is where **Disjoint Set Union (DSU)** comes in.

It is also called:

> **Union-Find**

This is the most important data structure used with Kruskal.

---

# 18. What is DSU?

Initially every vertex is its own separate group.

For our graph:

```text
A
B
C
D
E
```

We can represent:

```text
parent[A] = A
parent[B] = B
parent[C] = C
parent[D] = D
parent[E] = E
```

Meaning:

```text
A → A
B → B
C → C
D → D
E → E
```

Every vertex is currently its own component.

---

# 19. What is a Component?

A component is a group of connected vertices.

Initially:

```text
{A} {B} {C} {D} {E}
```

After adding:

```text
C-D
```

we have:

```text
{A} {B} {C,D} {E}
```

After adding:

```text
A-B
```

we have:

```text
{A,B} {C,D} {E}
```

After adding:

```text
C-E
```

we have:

```text
{A,B} {C,D,E}
```

After adding:

```text
B-D
```

everything becomes:

```text
{A,B,C,D,E}
```

Now all vertices are connected.

---

# 20. Two important DSU operations

DSU mainly provides two operations:

### 1. Find

```text
find(x)
```

It tells us:

> Which component does x belong to?

### 2. Union

```text
union(a,b)
```

It combines two different components.

---

# 21. How Find helps detect cycles

Suppose we have:

```text
A-B
```

Before adding:

```text
A → A
B → B
```

So:

```text
find(A) != find(B)
```

They belong to different components.

Therefore:

> Safe to add.

Then we perform:

```text
union(A,B)
```

Now A and B belong to the same component.

---

# 22. Now suppose we consider another A-B edge

We check:

```text
find(A)
find(B)
```

Both return the same representative.

Therefore:

```text
find(A) == find(B)
```

This means:

> A and B are already connected.

Adding the edge would create a cycle.

So:

> Reject the edge.

This is the core of Kruskal's cycle detection.

---

# 23. DSU Example

Initially:

```text
A   B   C   D   E
```

After:

```text
union(A,B)
```

we have:

```text
A---B
```

After:

```text
union(C,D)
```

we have:

```text
A---B

C---D
```

Now:

```text
find(A) != find(C)
```

So connecting A and C is safe.

After:

```text
union(A,C)
```

all become one component:

```text
A---B
|
C---D
```

---

# 24. Kruskal Algorithm — Complete Steps

Memorize this:

### Step 1

Create a list of all edges.

### Step 2

Sort edges by increasing weight.

### Step 3

Initially every vertex is a separate component.

### Step 4

Take the smallest edge.

### Step 5

Use `find()` on both endpoints.

### Step 6

If they belong to different components:

```text
Add edge
Union components
```

### Step 7

If they belong to the same component:

```text
Reject edge
```

because it creates a cycle.

### Step 8

Continue until:

$$
V-1
$$

edges are selected.

---

# 25. Pseudocode

This is useful for your jury:

```text
KRUSKAL(G)

Sort all edges in increasing order of weight

Create separate set for every vertex

MST = empty

for each edge (u, v) in sorted edges

    if FIND(u) != FIND(v)

        add (u, v) to MST

        UNION(u, v)

    if MST contains V-1 edges
        stop

return MST
```

---

# 26. Now C++ Code

We'll use a simple `struct Edge`.

```cpp id="w8x9o5"
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
```

---

# 27. Understand the Code Slowly

Don't memorize it line by line.

Understand the major sections.

---

## Part 1 — Edge Structure

```cpp
struct Edge
{
    int u;
    int v;
    int weight;
};
```

Each edge contains:

```text
u      → starting vertex
v      → ending vertex
weight → cost
```

For example:

```text
A-B = 2
```

could be stored as:

```text
u = A
v = B
weight = 2
```

---

# 28. Sorting Function

```cpp
bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}
```

This tells `sort()`:

> Sort edges according to weight in ascending order.

Then:

```cpp
sort(graph, graph + edges, compare);
```

changes:

```text
6
2
5
1
3
```

into:

```text
1
2
3
5
6
```

This is a very important step in Kruskal.

---

# 29. Parent Array

```cpp
int parent[10];
```

DSU uses the parent array to represent components.

Initially:

```cpp
for (int i = 0; i < vertices; i++)
{
    parent[i] = i;
}
```

So:

```text
parent[0] = 0
parent[1] = 1
parent[2] = 2
...
```

Every vertex is its own component.

---

# 30. Find Function

```cpp
int findParent(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent[x]);
}
```

This finds the **representative/root** of a component.

Suppose:

```text
A → B
B → C
C → C
```

Then:

```text
find(A)
```

eventually reaches:

```text
C
```

So C is the representative.

---

# 31. Why This Line?

```cpp
return parent[x] = findParent(parent[x]);
```

This performs **path compression**.

It makes future `find()` operations faster by directly connecting the vertex to the root.

You don't need to explain the implementation deeply unless your professor asks.

Just remember:

> Path compression improves the efficiency of DSU's find operation.

---

# 32. Union Function

```cpp
void unionSets(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    parent[b] = a;
}
```

First we find the representatives.

Then:

```cpp
parent[b] = a;
```

combines the two components.

For example:

```text
Component 1: A-B
Component 2: C-D
```

If we perform:

```text
union(A,C)
```

they become one component.

---

# 33. The Most Important Part

Inside the main loop:

```cpp
int parentU = findParent(u);
int parentV = findParent(v);
```

We find the component of both endpoints.

Then:

```cpp
if (parentU != parentV)
```

means:

> The two vertices belong to different components.

Therefore:

```cpp
add edge
union
```

If:

```cpp
parentU == parentV
```

then:

> Both vertices already belong to the same component.

Therefore adding the edge would create a cycle.

So we don't add it.

---

# 34. Why `selectedEdges == vertices - 1`?

A tree with V vertices always contains:

$$
V-1
$$

edges.

So:

```cpp
if (selectedEdges == vertices - 1)
    break;
```

means:

> We already have an MST, so stop.

---

# 35. Example Input

Let's use our graph.

Assign:

```text
A = 0
B = 1
C = 2
D = 3
E = 4
```

There are:

```text
5 vertices
7 edges
```

Input:

```text
5
7

0 1 2
0 2 6
0 3 5
1 3 3
2 3 1
2 4 2
3 4 4
```

Output:

```text
Edges in Minimum Spanning Tree:
2 - 3 : 1
0 - 1 : 2
2 - 4 : 2
1 - 3 : 3

Minimum Cost = 8
```

---

# 36. Kruskal Dry Run Table

This table is very important.

| Step | Edge | Weight | Cycle? | Decision |
| ---: | ---- | -----: | ------ | -------- |
|    1 | C-D  |      1 | No     | Accept   |
|    2 | A-B  |      2 | No     | Accept   |
|    3 | C-E  |      2 | No     | Accept   |
|    4 | B-D  |      3 | No     | Accept   |
|    5 | D-E  |      4 | Yes    | Reject   |
|    6 | A-D  |      5 | Yes    | Reject   |
|    7 | A-C  |      6 | Yes    | Reject   |

We stop after selecting 4 edges because:

$$
V-1=4
$$

---

# 37. Time Complexity

Kruskal's most expensive operation is:

```text
Sorting all edges
```

If there are E edges:

$$
O(E\log E)
$$

DSU operations are very efficient with path compression.

Therefore the overall complexity is generally written as:

$$
\boxed{O(E\log E)}
$$

Since for a simple graph:

$$
E \leq V^2
$$

it can also be related to:

$$
O(E\log V)
$$

in common discussions, but for your exam:

> **Kruskal = O(E log E)**

is the safest answer.

---

# 38. Space Complexity

We store:

* E edges
* parent array

Therefore:

$$
\boxed{O(E+V)}
$$

---

# 39. Prim vs Kruskal — VERY IMPORTANT

You now know both algorithms.

| Prim                                          | Kruskal                            |
| --------------------------------------------- | ---------------------------------- |
| Greedy                                        | Greedy                             |
| Finds MST                                     | Finds MST                          |
| Starts with a vertex                          | Starts with edges                  |
| Grows one tree                                | Builds components                  |
| Selects minimum edge connected to current MST | Selects globally smallest edge     |
| Uses key/visited/parent                       | Uses DSU/Union-Find                |
| No explicit sorting of all edges required     | Sorts all edges                    |
| Matrix implementation: O(V²)                  | O(E log E)                         |
| Often convenient for dense graphs             | Often convenient for sparse graphs |

### Easy way to remember:

```text
PRIM
 ↓
Pick a vertex
 ↓
Grow the tree


KRUSKAL
 ↓
Pick an edge
 ↓
Avoid cycle
 ↓
Build the tree
```

---

# 40. Prim and Kruskal on the Same Problem

Your previous experiment:

> Connect offices with minimum telephone-line cost.

Can use **Prim**.

Current experiment:

> Connect city zones with minimum underground cable cost.

Can use **Kruskal**.

Both solve:

```text
Minimum Spanning Tree
```

The difference is **how they construct the MST**.

---

# 41. Why Kruskal is Suitable for This Experiment

Your problem gives:

> "All possible connection costs."

That naturally gives us an **edge list**.

For example:

```text
Zone A → Zone B → ₹10
Zone A → Zone C → ₹5
Zone B → Zone D → ₹7
...
```

Kruskal can directly work with these edges:

```text
1. Store edges
2. Sort by cost
3. Select cheapest safe edges
```

So it is a very natural approach.

---

# 42. What Does "Compare Possible Approaches" Mean?

Your experiment says:

> "Compare possible approaches and determine which offers the most cost-effective outcome."

Here, the important approaches are MST algorithms such as:

### Kruskal

Sort edges and select cheapest non-cycle edges.

### Prim

Start from a vertex and repeatedly choose the cheapest connecting edge.

Both can produce the same minimum total cost for the same graph.

For example:

```text
Kruskal → Minimum cost = 8
Prim    → Minimum cost = 8
```

The **cost-effective outcome** is the MST with minimum total installation cost.

---

# 43. Important Viva Questions

### Q1. What is Kruskal's Algorithm?

> Kruskal's Algorithm is a greedy algorithm used to find the Minimum Spanning Tree of a weighted undirected graph.

---

### Q2. What is the main idea?

> Sort all edges in increasing order of weight and select the cheapest edge if it does not form a cycle.

---

### Q3. Why is Kruskal greedy?

> Because it selects the lowest-cost available edge at each step.

---

### Q4. Why do we sort edges?

> To process the cheapest edges first.

---

### Q5. How do you detect cycles?

> Using the Disjoint Set Union (DSU), also called Union-Find.

---

### Q6. What are the two main DSU operations?

> Find and Union.

---

### Q7. What does Find do?

> It determines the representative of the component containing a vertex.

---

### Q8. What does Union do?

> It combines two different components into one.

---

### Q9. When do we reject an edge?

If:

```text
find(u) == find(v)
```

because the two vertices are already connected and adding the edge would create a cycle.

---

### Q10. How many edges does MST have?

$$
\boxed{V-1}
$$

---

### Q11. Time complexity?

$$
\boxed{O(E\log E)}
$$

mainly because of sorting.

---

### Q12. Space complexity?

$$
\boxed{O(E+V)}
$$

---

### Q13. Difference between Prim and Kruskal?

> Prim grows the MST from a starting vertex, while Kruskal selects edges globally in increasing order and uses DSU to avoid cycles.

---

### Q14. Can Kruskal work with disconnected graphs?

Kruskal can process a disconnected graph, but it will produce a **minimum spanning forest**, not one MST connecting every vertex.

For an MST:

> The graph should be connected.

---

### Q15. Is Kruskal Divide and Conquer?

**No.**

It is:

> **Greedy.**

---

# 44. Strong Jury Answer

If your professor says:

### "Explain your experiment."

Say:

> "The problem is to connect all city zones using underground power cables while minimizing the total installation cost. I represent each zone as a vertex and each possible cable route as a weighted edge, where the weight represents the installation cost. This becomes a Minimum Spanning Tree problem. I use Kruskal's greedy algorithm. First, I sort all edges in increasing order of cost. Then I consider each edge one by one and add it to the MST only if it does not form a cycle. To detect cycles efficiently, I use the Disjoint Set Union or Union-Find data structure with find and union operations. Since an MST with V vertices contains V-1 edges, I stop after selecting V-1 edges. The time complexity is O(E log E), mainly because of sorting, and the space complexity is O(E+V)."

That's a very strong answer for the jury.

---

# 45. What You MUST Remember Tomorrow

If you forget everything else, remember this:

```text
KRUSKAL
   ↓
GREEDY
   ↓
MINIMUM SPANNING TREE
   ↓
SORT ALL EDGES
   ↓
CHEAPEST EDGE FIRST
   ↓
CHECK CYCLE
   ↓
NO CYCLE → ACCEPT
   ↓
CYCLE → REJECT
   ↓
USE DSU / UNION-FIND
   ↓
STOP AT V-1 EDGES
```

And the complexity:

$$
\boxed{O(E\log E)}
$$

---

## Final difference you should be able to say instantly

```text
Prim:
Start with a VERTEX → grow MST

Kruskal:
Start with EDGES → sort → avoid cycles → build MST
```

That distinction is **one of the most likely jury questions**.
