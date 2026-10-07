# Experiment 3 — Quick Sort

## Divide and Conquer + Quick Sort + Complexity Analysis

This is one of the **most important experiments** in your list because it combines:

* Divide and Conquer
* Sorting
* Recursion
* Pivot
* Partitioning
* Best case
* Average case
* Worst case
* Time complexity
* Space complexity

For the jury, you should understand **why Quick Sort works**, not just memorize the code.

---

# 1. First understand the problem

Your experiment says:

> Sort a given set of `n` integer elements using Quick Sort and compute its time complexity. Run the program for varied values of `n` and record the time taken. The elements can be entered by the user or generated using a random number generator and pivot element. Demonstrate how Divide and Conquer works along with worst, average and best case complexity.

So our task is basically:

```text
Input:
5 2 8 1 9 3

        ↓

Quick Sort

        ↓

Output:
1 2 3 5 8 9
```

---

# 2. What is Quick Sort?

**Quick Sort is a comparison-based sorting algorithm that uses the Divide and Conquer technique.**

The basic idea is:

> Choose one element as a **pivot**, place the pivot in its correct position, and divide the remaining elements into two parts.

Then recursively sort the two parts.

---

# 3. What is Divide and Conquer?

This is extremely important for your viva.

**Divide and Conquer** means:

### 1. Divide

Break a large problem into smaller subproblems.

### 2. Conquer

Solve the smaller subproblems.

### 3. Combine

Combine the solutions to obtain the final solution.

For Quick Sort:

```text
              Array
                |
              DIVIDE
                |
       Choose a pivot
                |
        Partition array
          /           \
       LEFT          RIGHT
        |               |
      SORT             SORT
        |               |
        └───────┬───────┘
                |
             Sorted
             Array
```

There is an important difference from Merge Sort:

> Quick Sort does most of its work during **partitioning**, whereas Merge Sort does most of its work during **merging**.

---

# 4. What is a Pivot?

The **pivot** is an element selected from the array around which we partition the array.

For example:

```text
8 3 7 4 2 6
```

Suppose we choose:

```text
pivot = 6
```

We rearrange the elements so that:

```text
elements smaller than 6 | 6 | elements greater than 6
```

For example:

```text
3 4 2 | 6 | 8 7
```

Now `6` is in its final sorted position.

Then we sort:

```text
3 4 2
```

and:

```text
8 7
```

separately.

---

# 5. Pivot Selection

A jury may ask:

> **How can you choose the pivot?**

Common choices are:

### 1. First element

```text
pivot = arr[low]
```

### 2. Last element

```text
pivot = arr[high]
```

### 3. Middle element

```text
pivot = arr[(low + high)/2]
```

### 4. Random element

Choose a random index.

For our practical code, we'll use the **last element as pivot**, because it makes the implementation very easy to understand.

---

# 6. The Most Important Part — Partition

If you understand **partition**, you understand Quick Sort.

Consider:

```text
10 7 8 9 1 5
```

Choose the last element:

```text
pivot = 5
```

We want:

```text
smaller elements | 5 | larger elements
```

After partitioning:

```text
1 | 5 | 10 7 8 9
```

The exact arrangement of the larger elements doesn't matter yet.

The important thing is:

```text
Everything on left  < 5
Everything on right > 5
```

Therefore, `5` is now at its correct position.

---

# 7. How Partition Works

We'll use a variable called:

```cpp
i
```

and another variable:

```cpp
j
```

Think of `i` as the position where the next smaller element should go.

Suppose:

```text
10 7 8 9 1 5
```

and:

```text
pivot = 5
```

Initially:

```text
i = low - 1
```

Since:

```text
low = 0
```

we get:

```text
i = -1
```

Then `j` scans the array from:

```text
low → high - 1
```

---

# 8. Partition Dry Run

Array:

```text
10 7 8 9 1 5
```

Pivot:

```text
5
```

### Start

```text
i = -1
```

---

### j = 0

```text
arr[0] = 10
```

Compare:

```text
10 < 5
```

False.

So don't move `i`.

---

### j = 1

```text
arr[1] = 7
```

```text
7 < 5
```

False.

---

### j = 2

```text
arr[2] = 8
```

```text
8 < 5
```

False.

---

### j = 3

```text
arr[3] = 9
```

```text
9 < 5
```

False.

---

### j = 4

```text
arr[4] = 1
```

Now:

```text
1 < 5
```

True.

So:

```text
i++
```

Now:

```text
i = 0
```

Swap:

```text
arr[i] ↔ arr[j]
```

So:

```text
10 7 8 9 1 5
↓
1 7 8 9 10 5
```

Finally, swap the pivot with:

```text
arr[i+1]
```

So:

```text
1 5 8 9 10 7
```

Wait—this is a subtle point: the exact Lomuto partition sequence depends on the swaps performed, and the correct final state after the scan is obtained by swapping the pivot with `arr[i+1]`. For this array, after moving `1` to the front, the array is:

```text
1 7 8 9 10 5
```

Then:

```text
swap(arr[i+1], arr[high])
```

where:

```text
i + 1 = 1
```

gives:

```text
1 5 8 9 10 7
```

Now:

```text
1 < 5
```

and:

```text
8, 9, 10, 7 > 5
```

So pivot `5` is correctly positioned at index `1`.

---

# 9. Quick Sort Recursion

Now:

```text
1 5 8 9 10 7
  ↑
pivot
```

Pivot index:

```text
1
```

So we recursively sort:

### Left:

```text
1
```

### Right:

```text
8 9 10 7
```

Then the right part gets another pivot.

If pivot = `7`:

```text
7 | 9 10 8
```

Then continue recursively.

Eventually:

```text
1 5 7 8 9 10
```

---

# 10. Quick Sort Algorithm

The complete logic is:

```text
QUICKSORT(arr, low, high)

if low < high

    pivotIndex = PARTITION(arr, low, high)

    QUICKSORT(arr, low, pivotIndex - 1)

    QUICKSORT(arr, pivotIndex + 1, high)
```

The algorithm does **not** explicitly merge the two halves.

This is another important difference from Merge Sort.

---

# 11. Simple C++ Code

Here is the code you should learn for your practical.

```cpp
#include <iostream>
using namespace std;

int partitionArray(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partitionArray(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);

        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
```

---

# 12. Understand the Code

Let's break it into three major sections:

```text
main()
  ↓
quickSort()
  ↓
partitionArray()
```

---

# 13. `partitionArray()` Function

```cpp
int partitionArray(int arr[], int low, int high)
```

This function:

> Places the pivot at its correct position and returns its index.

---

## Pivot

```cpp
int pivot = arr[high];
```

We're choosing the **last element** as pivot.

For:

```text
10 7 8 9 1 5
```

we have:

```text
pivot = 5
```

---

# 14. The `i` variable

```cpp
int i = low - 1;
```

`i` keeps track of the boundary of elements smaller than the pivot.

Initially:

```text
i = low - 1
```

For `low = 0`:

```text
i = -1
```

---

# 15. The `j` variable

```cpp
for (int j = low; j < high; j++)
```

`j` scans all elements **except the pivot**.

Why except pivot?

Because pivot is at:

```text
arr[high]
```

So:

```text
j < high
```

---

# 16. Compare with Pivot

```cpp
if (arr[j] < pivot)
```

If current element is smaller than pivot, we need to move it to the left section.

So:

```cpp
i++;
```

Then:

```cpp
swap(arr[i], arr[j]);
```

---

# 17. Final Pivot Swap

After the loop:

```cpp
swap(arr[i + 1], arr[high]);
```

This places the pivot into its correct position.

Then:

```cpp
return i + 1;
```

returns the pivot's index.

---

# 18. `quickSort()` Function

```cpp
void quickSort(int arr[], int low, int high)
```

This is the recursive function.

---

## Base Condition

```cpp
if (low < high)
```

Why?

If:

```text
low >= high
```

there is either:

* zero elements
* one element

Such a part is already sorted.

Therefore, recursion stops.

---

# 19. Partition

```cpp
int pivotIndex = partitionArray(arr, low, high);
```

This gives us the final position of the pivot.

---

# 20. Sort Left Side

```cpp
quickSort(arr, low, pivotIndex - 1);
```

Everything left of pivot is sorted recursively.

---

# 21. Sort Right Side

```cpp
quickSort(arr, pivotIndex + 1, high);
```

Everything right of pivot is sorted recursively.

---

# 22. Why don't we sort the pivot?

Because after partitioning, the pivot is already in its final position.

For example:

```text
1 5 8 9 10 7
  ↑
 pivot
```

`5` doesn't need to be moved anymore.

---

# 23. Complete Dry Run

Let's take:

```text
5 2 8 1 9 3
```

We call:

```text
quickSort(0,5)
```

Pivot:

```text
3
```

Partition:

```text
2 1 | 3 | 9 8 5
```

Pivot index = `2`.

Now recursively:

```text
Left:
2 1

Right:
9 8 5
```

---

### Left part

```text
2 1
```

Pivot:

```text
1
```

After partition:

```text
1 2
```

Done.

---

### Right part

```text
9 8 5
```

Pivot:

```text
5
```

After partition:

```text
5 8 9
```

Then sort:

```text
8 9
```

Already easy.

Final:

```text
1 2 3 5 8 9
```

---

# 24. Visualize the Divide and Conquer

```text
                    5 2 8 1 9 3
                         |
                    pivot = 3
                         |
              ┌──────────┴──────────┐
              ↓                     ↓
            2 1                    9 8 5
              |                     |
           pivot=1                pivot=5
              |                     |
           1 | 2                  5 | 8 9
                                      |
                                    done
              ↓                     ↓
              1 2                  5 8 9
                    \              /
                     \            /
                      1 2 3 5 8 9
```

This is the **Divide and Conquer concept**.

---

# 25. Best Case

Now let's discuss complexity.

This is extremely important.

Suppose every time we choose a pivot, the array is divided approximately equally.

For example:

```text
              8 elements
             /         \
          4 elements   4 elements
          /   \         /   \
         2     2       2     2
```

This produces a balanced recursion tree.

The height of the tree is:

$$
\log n
$$

At every level, partitioning takes:

$$
O(n)
$$

Therefore:

$$
O(n)\times O(\log n)
$$

So:

$$
\boxed{O(n\log n)}
$$

### Best case:

$$
\boxed{O(n\log n)}
$$

---

# 26. Average Case

In normal/random situations, the pivot generally creates reasonably balanced partitions on average.

Therefore:

$$
\boxed{O(n\log n)}
$$

So:

```text
Best    = O(n log n)
Average = O(n log n)
```

---

# 27. Worst Case

This is extremely important.

Suppose the array is already sorted:

```text
1 2 3 4 5 6 7
```

and we always select the **last element** as pivot.

First pivot:

```text
7
```

Partition becomes:

```text
1 2 3 4 5 6 | 7
```

Then:

```text
6
```

gives:

```text
1 2 3 4 5 | 6
```

Then:

```text
5
```

and so on.

Instead of:

```text
n/2 + n/2
```

we get:

```text
n-1 + 0
```

again and again.

So the recursion tree becomes:

```text
n
|
n-1
|
n-2
|
n-3
|
...
|
1
```

This is basically a linear-depth recursion.

---

# 28. Worst Case Calculation

At each level, partitioning takes:

$$
O(n)
$$

Then:

$$
n+(n-1)+(n-2)+...+1
$$

This gives:

$$
O(n^2)
$$

Therefore:

$$
\boxed{\text{Worst case = }O(n^2)}
$$

---

# 29. Quick Sort Complexity Summary

Memorize this table:

| Case    | Time Complexity |
| ------- | --------------: |
| Best    |  **O(n log n)** |
| Average |  **O(n log n)** |
| Worst   |       **O(n²)** |

This is one of the most likely viva questions.

---

# 30. Why does worst case happen?

Usually because the pivot is consistently very poor.

For example:

```text
1 2 3 4 5 6 7
```

If we always select:

```text
last element
```

then:

```text
pivot = 7
```

creates:

```text
6 elements | pivot | 0 elements
```

instead of:

```text
3 elements | pivot | 3 elements
```

So the recursion becomes highly unbalanced.

---

# 31. Space Complexity

This requires a little more care.

Quick Sort is generally considered an **in-place sorting algorithm** because it does not require an additional array like Merge Sort.

The partition itself uses only a few variables:

```text
pivot
i
j
```

So partition uses:

$$
O(1)
$$

auxiliary space.

However, recursive calls use stack space.

### Best/Average case

Balanced recursion:

$$
\boxed{O(\log n)}
$$

### Worst case

Unbalanced recursion:

$$
\boxed{O(n)}
$$

So:

| Case    | Auxiliary Space |
| ------- | --------------: |
| Best    |        O(log n) |
| Average |        O(log n) |
| Worst   |            O(n) |

---

# 32. Very Important: Is Quick Sort In-Place?

Yes.

A standard Quick Sort implementation is considered **in-place** because it rearranges elements inside the original array instead of requiring another array proportional to `n`.

But:

> It still requires recursion stack space.

So don't say:

> "Quick Sort uses O(1) space in all cases."

That is not correct for the recursive implementation.

---

# 33. Quick Sort vs Merge Sort

Your next experiment is Merge Sort, so this comparison will help you.

| Feature                 | Quick Sort       | Merge Sort       |
| ----------------------- | ---------------- | ---------------- |
| Technique               | Divide & Conquer | Divide & Conquer |
| Best                    | O(n log n)       | O(n log n)       |
| Average                 | O(n log n)       | O(n log n)       |
| Worst                   | **O(n²)**        | **O(n log n)**   |
| Extra array             | Usually no       | **Yes**          |
| Typical auxiliary space | O(log n) average | **O(n)**         |
| In-place                | Generally yes    | Generally no     |
| Main operation          | Partition        | Merge            |
| Stable                  | Usually no       | Yes              |
| Pivot                   | Required         | Not required     |

---

# 34. Why does Merge Sort have O(n log n) worst case but Quick Sort can have O(n²)?

This is a very good jury question.

### Merge Sort

It always divides approximately in half:

```text
n
↓
n/2 + n/2
↓
n/4 + n/4 + ...
```

Therefore:

```text
O(n log n)
```

### Quick Sort

Its partition depends on pivot selection.

Good pivot:

```text
n/2 | pivot | n/2
```

Bad pivot:

```text
n-1 | pivot | 0
```

Therefore worst case becomes:

```text
O(n²)
```

---

# 35. How can we reduce Quick Sort's worst-case probability?

Use a better pivot selection strategy.

For example:

### Randomized pivot

Instead of always choosing:

```text
last element
```

choose a random element.

This reduces the likelihood of repeatedly getting terrible partitions.

Another technique is:

> **Median-of-three**

Choose the median of:

```text
first element
middle element
last element
```

as pivot.

For your basic practical, however, **last-element pivot is much easier to code and explain**.

---

# 36. Random Number Generator

Your experiment says that elements can be generated using a random number generator.

In C++, a simple approach is:

```cpp
#include <cstdlib>
#include <ctime>
```

Then:

```cpp
srand(time(0));

int value = rand() % 100;
```

This generates values approximately from:

```text
0 to 99
```

Example:

```cpp
for (int i = 0; i < n; i++)
{
    arr[i] = rand() % 100;
}
```

---

# 37. Quick Sort With Random Data

You can use:

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int partitionArray(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partitionArray(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    srand(time(0));

    cout << "Generated array:\n";

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
```

---

# 38. Measuring Execution Time

Your experiment also says:

> Run the program for varied values of n and record the time taken to sort.

For this, C++ provides the `<chrono>` library.

Basic idea:

```cpp
auto start = chrono::high_resolution_clock::now();

quickSort(arr, 0, n - 1);

auto end = chrono::high_resolution_clock::now();
```

Then calculate:

```cpp
auto duration =
    chrono::duration_cast<chrono::microseconds>(end - start);
```

---

# 39. Complete Timing Program

For your practical, you can use this:

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

int partitionArray(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partitionArray(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }

    auto start = high_resolution_clock::now();

    quickSort(arr, 0, n - 1);

    auto end = high_resolution_clock::now();

    auto duration =
        duration_cast<microseconds>(end - start);

    cout << "Time taken: "
         << duration.count()
         << " microseconds\n";

    return 0;
}
```

---

# 40. What does `chrono` do?

```cpp
#include <chrono>
```

provides tools to measure time.

Before sorting:

```cpp
auto start = high_resolution_clock::now();
```

After sorting:

```cpp
auto end = high_resolution_clock::now();
```

Difference:

```text
end - start
```

gives the approximate execution duration.

---

# 41. Why do we run different values of n?

Suppose you test:

```text
n = 100
n = 500
n = 1000
n = 5000
n = 10000
```

You can record:

|     n | Time |
| ----: | ---: |
|   100 |  ... |
|   500 |  ... |
|  1000 |  ... |
|  5000 |  ... |
| 10000 |  ... |

As `n` increases, execution time generally increases.

However, **don't expect your measured values to exactly follow O(n log n)** because actual execution time depends on:

* CPU
* compiler
* operating system
* memory
* random input
* implementation
* other running processes

Complexity describes the **growth rate**, not an exact stopwatch value.

---

# 42. Jury Question: What is Divide and Conquer?

Say:

> "Divide and Conquer is an algorithmic technique in which a problem is divided into smaller subproblems, each subproblem is solved, usually recursively, and their solutions are used to solve the original problem."

For Quick Sort:

> "We divide the array around a pivot and recursively sort the left and right partitions."

---

# 43. Jury Question: What is partitioning?

Answer:

> "Partitioning is the process of rearranging the array around a pivot such that elements smaller than the pivot are placed on one side and larger elements on the other side. After partitioning, the pivot reaches its correct sorted position."

---

# 44. Jury Question: What is a pivot?

> "A pivot is an element selected from the array that is used to divide the array into two partitions during Quick Sort."

---

# 45. Jury Question: What if the pivot is the smallest element?

Suppose:

```text
5 6 7 8 9
```

and pivot:

```text
5
```

Then:

```text
left = 0 elements
right = 4 elements
```

This is an unbalanced partition and can contribute to the worst case.

---

# 46. Jury Question: What if pivot is the middle value?

For example:

```text
1 2 3 4 5 6 7
```

pivot:

```text
4
```

We get:

```text
1 2 3 | 4 | 5 6 7
```

This is balanced.

Balanced partitions give:

$$
O(n\log n)
$$

---

# 47. Jury Question: Is Quick Sort stable?

Standard Quick Sort is:

> **Not stable.**

A sorting algorithm is stable if equal elements maintain their original relative order.

You generally don't need to demonstrate this unless asked.

---

# 48. Jury Question: Is Quick Sort in-place?

> Yes, standard Quick Sort rearranges elements within the same array and does not require an auxiliary array proportional to n. However, the recursive calls require stack space.

---

# 49. Jury Question: Why is Quick Sort called Quick Sort?

You can say:

> It is called Quick Sort because it is generally very efficient in practice and has average-case O(n log n) time complexity.

Don't claim that it is **always** faster than every other sorting algorithm.

---

# 50. Jury Question: What is the worst case?

Answer:

> "The worst case occurs when the pivot repeatedly produces highly unbalanced partitions, such as one partition containing n−1 elements and the other containing zero elements. The time complexity becomes O(n²)."

---

# 51. Jury Question: What is the best case?

> "The best case occurs when the pivot divides the array into approximately equal halves at every step. The time complexity is O(n log n)."

---

# 52. Jury Question: What is the average case?

> "The average-case time complexity is O(n log n), assuming reasonably balanced partitions on average."

---

# 53. Jury Question: Why does partition take O(n)?

Because every element in the current subarray is inspected approximately once.

For a subarray of size `n`:

```text
j = low
...
j = high - 1
```

So approximately `n` elements are examined.

Therefore:

$$
O(n)
$$

---

# 54. The Most Important Complexity Derivation

For a balanced Quick Sort:

$$
T(n)=2T(n/2)+O(n)
$$

This gives:

$$
\boxed{O(n\log n)}
$$

For worst case:

$$
T(n)=T(n-1)+O(n)
$$

Therefore:

$$
T(n)=O(n^2)
$$

You should know these two recurrence relations.

---

# 🧠 QUICK SORT CHEAT SHEET

Before your jury, remember this:

```text
                    QUICK SORT
                        |
                Divide & Conquer
                        |
                    Choose Pivot
                        |
                    Partition
                   /          \
                  /            \
              LEFT             RIGHT
                |                |
             Quick Sort       Quick Sort
                |                |
                └───────┬────────┘
                        |
                    Sorted Array
```

### Complexity:

```text
Best Case       O(n log n)
Average Case    O(n log n)
Worst Case      O(n²)

Space:
Best/Average    O(log n)
Worst            O(n)
```

### Key concepts:

```text
Pivot
  ↓
Partition
  ↓
Pivot gets correct position
  ↓
Recursively sort left
  ↓
Recursively sort right
```

---

# 🔥 10 Questions You MUST Know

Before going into your jury, make sure you can answer these without looking:

1. **What is Quick Sort?**
2. **What is Divide and Conquer?**
3. **What is a pivot?**
4. **What is partitioning?**
5. **Why does partition take O(n)?**
6. **What is the best-case complexity?**
7. **What is the average-case complexity?**
8. **What is the worst-case complexity?**
9. **Why can Quick Sort become O(n²)?**
10. **What is the difference between Quick Sort and Merge Sort?**

If you understand everything above, **Experiment 3 is covered sufficiently for both coding and viva**.

Next is **Experiment 4 — Merge Sort**. It will be much easier because you've now understood Divide and Conquer through Quick Sort. We'll learn **split → recursive sort → merge**, the complete C++ code, a detailed dry run, complexity derivation, and the likely jury questions.
