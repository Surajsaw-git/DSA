Absolutely. Since your **jury/viva exam is tomorrow**, we’ll prepare this in a very practical way.

I’ll teach you **one experiment at a time**, starting from absolute basics. For every experiment, I’ll cover:

1. **What the problem means**
2. **Algorithm/concept**
3. **Why we use that algorithm**
4. **Step-by-step working**
5. **Simple C++ code**
6. **Line-by-line code explanation**
7. **Dry run with an example**
8. **Time complexity**
9. **Space complexity**
10. **Best / average / worst case wherever applicable**
11. **Important viva questions + answers**
12. **Common mistakes**
13. **What you should say to the jury**

---

# 📚 Your Complete Preparation Roadmap

We have **7 experiments**, but several contain multiple concepts.

### UNIT 1 — Basic Algorithms

**Experiment 1 — Fibonacci**

* Recursion
* Iteration
* Time complexity
* Space complexity
* Comparison

**Experiment 2 — Binary Search**

* Searching
* Sorted data requirement
* Recursive binary search
* Iterative binary search
* Time and space complexity
* Comparison

---

### UNIT 2 — Divide and Conquer

**Experiment 3 — Quick Sort**

* Divide and Conquer
* Partitioning
* Pivot
* Recursive calls
* Best / Average / Worst case
* Time complexity
* Space complexity
* C++ implementation

**Experiment 4 — Merge Sort**

* Divide and Conquer
* Splitting
* Merging
* Recursive implementation
* Time and space complexity
* Comparison with Quick Sort

---

### UNIT 2 — Matrix Multiplication

**Experiment 5 — Matrix Multiplication**

* Matrix representation
* Normal matrix multiplication
* Transformation matrices
* Computational bottleneck
* Optimization
* Divide and Conquer idea
* Complexity
* Application to AR

---

### UNIT 2 — Greedy Algorithms

**Experiment 6 — Fractional Knapsack**

* Greedy method
* Profit/weight ratio
* Sorting
* Fractional selection
* Complete C++ program
* Complexity
* Dry run

**Experiment 7 — Prim's Algorithm**

* Minimum Spanning Tree
* Graph
* Weighted graph
* Adjacency matrix
* Prim's Algorithm
* Greedy approach
* C++ implementation
* Complexity
* Comparison with Kruskal

---

# ⭐ Important for Your Jury

Don't just memorize code.

For each algorithm, you should be able to answer these five questions:

> **1. What is the algorithm?**
> **2. How does it work?**
> **3. Why did you use it?**
> **4. What is its time and space complexity?**
> **5. What happens in the worst case?**

If you can answer these, you'll be in a strong position for the viva.

---

# EXPERIMENT 1 — FIBONACCI

Let's start from the first experiment.

---

## 1. What is Fibonacci?

The Fibonacci sequence is:

```text
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
```

Each number is obtained by adding the previous two numbers.

Mathematically:

$$
F(n)=F(n-1)+F(n-2)
$$

with:

$$
F(0)=0
$$

$$
F(1)=1
$$

For example:

```text
F(0) = 0
F(1) = 1

F(2) = F(1) + F(0)
     = 1 + 0
     = 1

F(3) = F(2) + F(1)
     = 1 + 1
     = 2

F(4) = F(3) + F(2)
     = 2 + 1
     = 3
```

Therefore:

```text
Fibonacci:
0 1 1 2 3 5 8 13 ...
```

---

# 2. Why are we implementing it in two ways?

Your experiment specifically asks:

> Generate nth Fibonacci number using:
>
> **(i) Recursion**
>
> **(ii) Iteration**

So we need to create **two different designs** for the same problem.

### Method 1 — Recursion

A function calls itself.

```text
fib(n)
   |
   +-- fib(n-1)
   |
   +-- fib(n-2)
```

### Method 2 — Iteration

We use a loop.

```text
for(...)
```

Then we'll compare:

```text
             Recursion       Iteration
Time           ?                ?
Space          ?                ?
```

---

# PART A — Fibonacci Using Recursion

## 3. What is recursion?

**Recursion means a function calls itself to solve a smaller version of the same problem.**

For Fibonacci:

$$
F(n)=F(n-1)+F(n-2)
$$

So the function can directly implement this formula.

---

# 4. Recursive Fibonacci Algorithm

The logic is:

```text
fib(n)

if n == 0
    return 0

if n == 1
    return 1

return fib(n-1) + fib(n-2)
```

Notice something important.

For example:

```text
fib(5)
```

becomes:

```text
fib(4) + fib(3)
```

Then:

```text
fib(4) = fib(3) + fib(2)

fib(3) = fib(2) + fib(1)

fib(2) = fib(1) + fib(0)
```

This keeps happening until we reach:

```text
fib(0)
fib(1)
```

These are called **base cases**.

---

# 5. Recursive Fibonacci C++ Code

```cpp
#include <iostream>
using namespace std;

int fibonacci(int n)
{
    // Base cases
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci number = " << fibonacci(n);

    return 0;
}
```

---

# 6. Understand the code line by line

### Header

```cpp
#include <iostream>
```

This allows us to use:

```cpp
cin
cout
```

---

### Namespace

```cpp
using namespace std;
```

Allows us to write:

```cpp
cout
```

instead of:

```cpp
std::cout
```

---

## Function

```cpp
int fibonacci(int n)
```

This creates a function called:

```text
fibonacci
```

It accepts:

```text
n
```

and returns an integer.

---

## First base case

```cpp
if (n == 0)
    return 0;
```

If we ask:

```text
fibonacci(0)
```

the answer is:

```text
0
```

We don't make another recursive call.

---

## Second base case

```cpp
if (n == 1)
    return 1;
```

Similarly:

```text
fibonacci(1) = 1
```

---

## Recursive case

```cpp
return fibonacci(n - 1) + fibonacci(n - 2);
```

This is the most important line.

It directly represents:

$$
F(n)=F(n-1)+F(n-2)
$$

For example:

```text
fibonacci(5)
```

becomes:

```text
fibonacci(4) + fibonacci(3)
```

---

# 7. Dry Run — fibonacci(5)

Let's trace it.

```text
fib(5)
```

↓

```text
fib(4) + fib(3)
```

Now:

```text
fib(4)
= fib(3) + fib(2)
```

and:

```text
fib(3)
= fib(2) + fib(1)
```

Eventually:

```text
fib(2)
= fib(1) + fib(0)
= 1 + 0
= 1
```

Therefore:

```text
fib(3)
= fib(2) + fib(1)
= 1 + 1
= 2
```

Then:

```text
fib(4)
= fib(3) + fib(2)
= 2 + 1
= 3
```

And:

```text
fib(5)
= fib(4) + fib(3)
= 3 + 2
= 5
```

So:

```text
Answer = 5
```

---

# 8. Recursion Tree

This is **very important for your viva**.

For:

```text
fib(5)
```

the calls look approximately like:

```text
                    fib(5)
                   /      \
              fib(4)      fib(3)
              /   \        /   \
          fib(3) fib(2) fib(2) fib(1)
          /  \
      fib(2) fib(1)
      /   \
   fib(1) fib(0)
```

Notice something.

We calculate the same values **again and again**.

For example:

```text
fib(3)
```

appears multiple times.

And:

```text
fib(2)
```

also appears multiple times.

This repeated calculation is why recursive Fibonacci is inefficient.

---

# 9. Time Complexity of Recursive Fibonacci

The recurrence is:

$$
T(n)=T(n-1)+T(n-2)+O(1)
$$

This results in exponential complexity.

For basic algorithm analysis, we generally state:

$$
\boxed{O(2^n)}
$$

More tightly, it is:

$$
O(\phi^n)
$$

where:

$$
\phi \approx 1.618
$$

But **for your jury/exam, remember:**

> Recursive Fibonacci has exponential time complexity: **O(2ⁿ)**.

---

# 10. Space Complexity of Recursive Fibonacci

Why does recursion require memory?

Because every function call is stored in the **call stack** until it returns.

The deepest chain is approximately:

```text
fib(5)
  |
fib(4)
  |
fib(3)
  |
fib(2)
  |
fib(1)
```

Maximum depth is proportional to `n`.

Therefore:

$$
\boxed{O(n)}
$$

### Important:

Recursive Fibonacci:

```text
Time  = O(2^n)
Space = O(n)
```

---

# PART B — Fibonacci Using Iteration

Now let's make the same Fibonacci calculation using a loop.

---

# 11. What is iteration?

**Iteration means repeatedly executing statements using a loop.**

For Fibonacci, instead of calling the function repeatedly, we maintain two values:

```text
a = previous Fibonacci number
b = current Fibonacci number
```

Initially:

```text
a = 0
b = 1
```

Then calculate:

```text
c = a + b
```

and move forward:

```text
a = b
b = c
```

---

# 12. Iterative Fibonacci Algorithm

```text
fib(n)

if n == 0
    return 0

a = 0
b = 1

repeat n-1 times

    c = a + b
    a = b
    b = c

return b
```

---

# 13. Iterative Fibonacci C++ Code

```cpp
#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 0)
        return 0;

    int a = 0;
    int b = 1;

    for (int i = 2; i <= n; i++)
    {
        int c = a + b;

        a = b;
        b = c;
    }

    return b;
}

int main()
{
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci number = " << fibonacci(n);

    return 0;
}
```

---

# 14. Understand the iterative code

Initially:

```cpp
int a = 0;
int b = 1;
```

So:

```text
a = 0
b = 1
```

This represents:

```text
F(0) = 0
F(1) = 1
```

---

## Loop

```cpp
for (int i = 2; i <= n; i++)
```

We start from `2` because:

```text
F(0)
F(1)
```

are already known.

---

## Calculate next number

```cpp
int c = a + b;
```

For example:

```text
a = 0
b = 1

c = 0 + 1
  = 1
```

---

## Move values forward

```cpp
a = b;
b = c;
```

Now:

```text
a = 1
b = 1
```

Next:

```text
c = 1 + 1
  = 2
```

Then:

```text
a = 1
b = 2
```

Next:

```text
c = 1 + 2
  = 3
```

And so on.

---

# 15. Dry Run — n = 7

Initial:

```text
a = 0
b = 1
```

### i = 2

```text
c = 0 + 1 = 1

a = 1
b = 1
```

### i = 3

```text
c = 1 + 1 = 2

a = 1
b = 2
```

### i = 4

```text
c = 1 + 2 = 3

a = 2
b = 3
```

### i = 5

```text
c = 2 + 3 = 5

a = 3
b = 5
```

### i = 6

```text
c = 3 + 5 = 8

a = 5
b = 8
```

### i = 7

```text
c = 5 + 8 = 13

a = 8
b = 13
```

Therefore:

```text
F(7) = 13
```

---

# 16. Time Complexity of Iterative Fibonacci

The loop runs approximately `n` times.

Therefore:

$$
\boxed{O(n)}
$$

---

# 17. Space Complexity of Iterative Fibonacci

We only use:

```text
a
b
c
i
```

A fixed number of variables.

The amount of memory does not increase with `n`.

Therefore:

$$
\boxed{O(1)}
$$

---

# 18. Final Comparison

This is **very important for your jury**.

| Feature               | Recursion                          | Iteration          |
| --------------------- | ---------------------------------- | ------------------ |
| Approach              | Function calls itself              | Uses loop          |
| Time                  | O(2ⁿ)                              | O(n)               |
| Space                 | O(n)                               | O(1)               |
| Repeated calculations | Yes                                | No                 |
| Call stack            | Required                           | Not required       |
| Performance           | Slow for large n                   | Much faster        |
| Memory usage          | Higher                             | Very low           |
| Implementation        | Simple mathematical representation | Slightly more code |

---

# ⭐ Most Important Viva Question

### Q1. Which implementation is better for Fibonacci?

**Answer:**

> The iterative implementation is generally better because it has **O(n) time complexity and O(1) auxiliary space**, whereas the simple recursive implementation has **O(2ⁿ) time complexity and O(n) stack space**.

---

### Q2. Why is recursive Fibonacci slow?

> Because it calculates the same Fibonacci values multiple times. For example, `fib(3)` and `fib(2)` may be calculated repeatedly.

---

### Q3. What is the base case?

> The base cases are `F(0) = 0` and `F(1) = 1`. They stop the recursive calls.

---

### Q4. What happens if we don't have a base case?

> The recursion will continue indefinitely until the program eventually causes a stack overflow.

---

### Q5. What is recursion?

> Recursion is a technique in which a function calls itself to solve smaller instances of the same problem.

---

### Q6. What is iteration?

> Iteration repeatedly executes a block of statements using a loop such as `for` or `while`.

---

### Q7. Why is iterative space complexity O(1)?

> Because it uses only a fixed number of variables regardless of the value of `n`.

---

### Q8. Why is recursive space O(n)?

> Because recursive function calls are stored in the call stack, and the maximum recursion depth grows proportionally to `n`.

---

### Q9. Can recursive Fibonacci be optimized?

Yes.

We can use **Dynamic Programming / Memoization** to avoid repeated calculations.

Then Fibonacci can be calculated in:

$$
O(n)
$$

time.

But **your experiment specifically asks for recursion and iteration**, so don't confuse the basic recursive implementation with memoized recursion.

---

# 🎯 What to Say to the Jury

If they say:

> **"Explain your first experiment."**

You can say:

> "My first experiment is to generate the nth Fibonacci number using recursion and iteration and compare their time and space complexities. Fibonacci follows the recurrence F(n) = F(n-1) + F(n-2), with F(0) = 0 and F(1) = 1. In the recursive approach, the function calls itself for n-1 and n-2, but it performs repeated calculations, giving exponential time complexity O(2ⁿ) and O(n) stack space. In the iterative approach, I use a loop and maintain the previous two Fibonacci values. It takes O(n) time and O(1) auxiliary space. Therefore, the iterative approach is more efficient for large values of n."

That's a **very strong viva answer**.

---

# ⚠️ One Important Point

Your experiment says:

> "Generate the nth Fibonacci **numbers**"

Sometimes the jury may ask you to generate the **first n Fibonacci numbers**, rather than just calculate `F(n)`.

For example:

```text
Input: 7

Output:
0 1 1 2 3 5 8
```

That's slightly different from:

```text
Input: 7
Output:
13
```

So you should know both.

### First n Fibonacci numbers — iterative

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    int a = 0;
    int b = 1;

    cout << "Fibonacci series: ";

    for (int i = 0; i < n; i++)
    {
        cout << a << " ";

        int c = a + b;
        a = b;
        b = c;
    }

    return 0;
}
```

For:

```text
n = 7
```

output:

```text
0 1 1 2 3 5 8
```

---

# 🧠 Remember This for Tomorrow

Write this in your mental cheat sheet:

```text
Fibonacci
│
├── Recursive
│   ├── Formula: F(n)=F(n-1)+F(n-2)
│   ├── Base cases: F(0)=0, F(1)=1
│   ├── Time: O(2^n)
│   └── Space: O(n)
│
└── Iterative
    ├── Uses loop
    ├── Stores previous 2 values
    ├── Time: O(n)
    └── Space: O(1)
```

## ⭐ Most important comparison

```text
Recursive       → O(2^n), O(n)
Iterative       → O(n),   O(1)
                  ↑         ↑
                 Time      Space
```

**Experiment 1 is now covered from concept → algorithm → code → dry run → complexity → viva.**

When you're ready, say **"continue"**, and we'll move to **Experiment 2: Binary Search**, starting from what searching means and why binary search requires sorted data, then we'll do **both recursive and iterative C++ implementations** in the same depth.
