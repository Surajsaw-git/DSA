# Experiment 4 — Merge Sort

Now we move to **Merge Sort**.

Your experiment says:

> **Sort examination answer sheets of individual enrolment numbers in a given order by the Dean of Examination. Identify the sorting algorithm and discuss time and space complexity.**

The key idea is that the answer sheets have **enrolment numbers**, and we need to arrange them in sorted order.

For example:

```text
Input:
105 102 109 101 107

        ↓ Merge Sort

Output:
101 102 105 107 109
```

The algorithm we use is:

# ⭐ Merge Sort

Merge Sort is a **Divide and Conquer** sorting algorithm.

Since you just learned Quick Sort, you'll notice that both use Divide and Conquer, but they use it differently.

---

# 1. What is Merge Sort?

**Merge Sort is a sorting algorithm that divides an array into smaller halves, recursively sorts those halves, and then merges the sorted halves.**

The three steps are:

```text
DIVIDE
   ↓
CONQUER
   ↓
COMBINE
```

For Merge Sort:

```text
                 8 3 5 1 9 6 2 4
                         |
                       DIVIDE
                         |
             ┌───────────┴───────────┐
             ↓                       ↓
          8 3 5 1                  9 6 2 4
             |                       |
           DIVIDE                  DIVIDE
             ↓                       ↓
          8 3   5 1                9 6   2 4
             |                       |
           DIVIDE                  DIVIDE
             ↓                       ↓
          8  3  5  1              9  6  2  4
             |                       |
           MERGE                   MERGE
             ↓                       ↓
           3 8  1 5                6 9  2 4
             |                       |
             └───────────┬───────────┘
                         ↓
                      MERGE
                         ↓
                 1 2 3 4 5 6 8 9
```

---

# 2. Why is Merge Sort called Divide and Conquer?

Because:

### Divide

Divide the array into two halves.

### Conquer

Recursively sort both halves.

### Combine

Merge the two sorted halves.

So:

```text
Merge Sort
    ↓
Divide
    ↓
Sort left + sort right
    ↓
Merge
```

---

# 3. The Most Important Concept — Splitting

Suppose:

```text
8 3 5 1 9 6 2 4
```

We divide it:

```text
8 3 5 1 | 9 6 2 4
```

Again:

```text
8 3 | 5 1 | 9 6 | 2 4
```

Again:

```text
8 | 3 | 5 | 1 | 9 | 6 | 2 | 4
```

Now every part contains only one element.

A single element is already sorted.

So we start **merging**.

---

# 4. What Does "Merge" Mean?

Suppose we have two sorted arrays:

```text
Left:
3 8

Right:
1 5
```

We need to combine them into:

```text
1 3 5 8
```

We compare the first elements:

```text
3 vs 1
```

`1` is smaller:

```text
1
```

Then:

```text
3 vs 5
```

`3` is smaller:

```text
1 3
```

Then:

```text
8 vs 5
```

`5` is smaller:

```text
1 3 5
```

Finally:

```text
8
```

Result:

```text
1 3 5 8
```

That process is called **merging**.

---

# 5. Very Important Difference From Quick Sort

Remember this:

### Quick Sort

```text
Partition → Recursively sort
```

### Merge Sort

```text
Divide → Recursively sort → Merge
```

The major operation is different.

| Quick Sort       | Merge Sort           |
| ---------------- | -------------------- |
| Partition        | Merge                |
| Pivot required   | No pivot             |
| Usually in-place | Requires extra array |
| Worst O(n²)      | Worst O(n log n)     |

---

# 6. Merge Sort Algorithm

The algorithm has two functions:

```text
mergeSort()
merge()
```

### `mergeSort()`

Responsible for:

* dividing
* recursive calls

### `merge()`

Responsible for:

* combining sorted parts

---

# 7. Basic Algorithm

```text
MERGE_SORT(arr, low, high)

if low < high

    mid = (low + high) / 2

    MERGE_SORT(arr, low, mid)

    MERGE_SORT(arr, mid + 1, high)

    MERGE(arr, low, mid, high)
```

Notice the order:

```text
1. Divide
2. Sort left
3. Sort right
4. Merge
```

---

# 8. Simple C++ Code

This is the main code I recommend you learn for your practical:

```cpp
#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[high - low + 1];

    // Compare elements from both halves
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements from left half
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements from right half
    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy temp back to original array
    for (i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);

        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
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

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
```

---

# 9. Understand the Code

Let's break the program into:

```text
main()
  ↓
mergeSort()
  ↓
merge()
```

---

# 10. `mergeSort()` Function

```cpp
void mergeSort(int arr[], int low, int high)
```

It receives:

```text
arr  → array
low  → starting index
high → ending index
```

---

# 11. Base Condition

```cpp
if (low < high)
```

Why?

Suppose:

```text
low = 3
high = 3
```

There is only one element.

A single element is already sorted.

So recursion stops.

---

# 12. Find Middle

```cpp
int mid = low + (high - low) / 2;
```

Suppose:

```text
low = 0
high = 7
```

Then:

```text
mid = 0 + (7 - 0)/2
    = 3
```

So:

```text
Left:
0 1 2 3

Right:
4 5 6 7
```

---

# 13. Sort Left Half

```cpp
mergeSort(arr, low, mid);
```

This recursively sorts:

```text
low → mid
```

For example:

```text
0 → 3
```

---

# 14. Sort Right Half

```cpp
mergeSort(arr, mid + 1, high);
```

This recursively sorts:

```text
mid + 1 → high
```

For example:

```text
4 → 7
```

---

# 15. Merge

Finally:

```cpp
merge(arr, low, mid, high);
```

Now both halves are sorted.

We combine them.

---

# 16. Understand the `merge()` Function

```cpp
void merge(int arr[], int low, int mid, int high)
```

Suppose:

```text
low = 0
mid = 2
high = 5
```

Then:

```text
Left half:
0 1 2

Right half:
3 4 5
```

---

# 17. Three Important Variables

```cpp
int i = low;
int j = mid + 1;
int k = 0;
```

### `i`

Tracks the left half.

### `j`

Tracks the right half.

### `k`

Tracks the temporary array.

Think:

```text
i → left
j → right
k → temp
```

---

# 18. Temporary Array

```cpp
int temp[high - low + 1];
```

We need temporary memory to store the merged result.

For example:

```text
Left:  3 8
Right: 1 5
```

We create:

```text
temp:
_ _ _ _
```

Then fill it:

```text
1 3 5 8
```

Then copy it back to the original array.

---

# 19. Main Merge Loop

```cpp
while (i <= mid && j <= high)
```

This means:

> Continue comparing while both halves still contain elements.

---

# 20. Compare Elements

```cpp
if (arr[i] <= arr[j])
```

If left element is smaller:

```cpp
temp[k] = arr[i];
```

Otherwise:

```cpp
temp[k] = arr[j];
```

Then move the corresponding pointer.

---

# 21. Why `i++`?

Suppose:

```text
Left:
3 8

Right:
1 5
```

Compare:

```text
3 vs 1
```

1 is smaller.

So:

```text
temp[0] = 1
```

Move right pointer:

```text
j++
```

Now compare:

```text
3 vs 5
```

3 is smaller.

So:

```text
temp[1] = 3
```

Move:

```text
i++
```

---

# 22. What About Remaining Elements?

Suppose:

```text
Left:
3 8

Right:
1
```

After comparison:

```text
1
```

the right half is finished.

But:

```text
3 8
```

are still remaining.

So we need:

```cpp
while (i <= mid)
```

to copy them.

Similarly:

```cpp
while (j <= high)
```

copies remaining right-side elements.

---

# 23. Copy Back

Finally:

```cpp
for (i = low, k = 0; i <= high; i++, k++)
{
    arr[i] = temp[k];
}
```

This puts the sorted result back into the original array.

---

# 24. Full Dry Run

Let's take:

```text
8 3 5 1
```

We call:

```text
mergeSort(0,3)
```

---

## Step 1 — Divide

```text
8 3 | 5 1
```

---

## Step 2 — Divide Again

```text
8 | 3 | 5 | 1
```

Each single element is sorted.

---

# 25. First Merge

Merge:

```text
8
3
```

Compare:

```text
8 vs 3
```

3 is smaller.

So:

```text
3 8
```

---

# 26. Second Merge

Merge:

```text
5
1
```

Compare:

```text
5 vs 1
```

1 is smaller.

Result:

```text
1 5
```

Now we have:

```text
3 8 | 1 5
```

Both halves are sorted.

---

# 27. Final Merge

Compare:

```text
3 vs 1
```

Take:

```text
1
```

Now:

```text
3 vs 5
```

Take:

```text
3
```

Now:

```text
8 vs 5
```

Take:

```text
5
```

Finally:

```text
8
```

Result:

```text
1 3 5 8
```

---

# 28. Complete Visualization

```text
                 8 3 5 1
                     |
                   DIVIDE
                     |
              ┌──────┴──────┐
              ↓             ↓
            8 3            5 1
              |             |
            DIVIDE        DIVIDE
              ↓             ↓
            8 | 3         5 | 1
              ↓             ↓
            MERGE         MERGE
              ↓             ↓
             3 8          1 5
                \          /
                 \        /
                  \      /
                   MERGE
                     ↓
                  1 3 5 8
```

This diagram is excellent for explaining Merge Sort to the jury.

---

# 29. Larger Example

Consider:

```text
38 27 43 3 9 82 10
```

First:

```text
38 27 43 3 | 9 82 10
```

Then:

```text
38 27 | 43 3 | 9 82 | 10
```

Then:

```text
38 | 27 | 43 | 3 | 9 | 82 | 10
```

Merge:

```text
27 38
3 43
9 82
10
```

Then:

```text
3 27 38 43
9 10 82
```

Finally:

```text
3 9 10 27 38 43 82
```

---

# 30. Time Complexity

This is one of the most important parts of the experiment.

At every level, the array is divided into halves.

The recursion depth is:

$$
\log n
$$

At each level, merging all elements takes:

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

---

# 31. Best Case

Even if the array is already sorted:

```text
1 2 3 4 5 6 7 8
```

Merge Sort still divides and merges.

Therefore:

$$
\boxed{O(n\log n)}
$$

---

# 32. Average Case

For random data:

$$
\boxed{O(n\log n)}
$$

---

# 33. Worst Case

Even in the worst case:

$$
\boxed{O(n\log n)}
$$

This is a major advantage over standard Quick Sort.

---

# 34. Complexity Table

Memorize this:

| Case    |     Merge Sort |
| ------- | -------------: |
| Best    | **O(n log n)** |
| Average | **O(n log n)** |
| Worst   | **O(n log n)** |

This is a very common viva question.

---

# 35. Why is Worst Case Still O(n log n)?

Because Merge Sort **always divides the array approximately into halves**, regardless of the input arrangement.

Unlike Quick Sort, it does not depend on selecting a good or bad pivot.

So the recursion depth remains approximately:

$$
\log n
$$

and merging each level requires:

$$
O(n)
$$

Therefore:

$$
O(n\log n)
$$

even in the worst case.

---

# 36. Space Complexity

This is another extremely important difference.

We use:

```cpp
int temp[...];
```

to merge the arrays.

The temporary array requires:

$$
O(n)
$$

space.

Additionally, recursion requires:

$$
O(\log n)
$$

stack space.

But the dominant term is:

$$
O(n)
$$

Therefore:

$$
\boxed{O(n)}
$$

auxiliary space.

---

# 37. Is Merge Sort In-Place?

The standard array implementation we are using is:

> **Not in-place**

because it uses an additional temporary array of size proportional to `n`.

Remember:

```text
Quick Sort → generally in-place
Merge Sort → requires O(n) extra array
```

---

# 38. Is Merge Sort Stable?

Yes.

Standard Merge Sort can be implemented as a:

> **Stable sorting algorithm.**

Why?

In our code:

```cpp
if (arr[i] <= arr[j])
```

we choose the left element when two elements are equal.

This preserves their relative ordering.

---

# 39. Merge Sort for Examination Answer Sheets

Now connect it to your actual experiment.

Suppose enrollment numbers are:

```text
202405
202401
202409
202403
202402
```

We need to arrange answer sheets according to enrollment number:

```text
202401
202402
202403
202405
202409
```

Merge Sort is suitable because:

* It has predictable O(n log n) time.
* It works well for large datasets.
* Its worst-case complexity remains O(n log n).
* It is stable.

For an exam answer, you can say:

> "The enrollment numbers of answer sheets can be sorted using Merge Sort, a Divide and Conquer algorithm. The numbers are recursively divided into smaller subarrays, sorted, and then merged. Merge Sort has O(n log n) time complexity in best, average and worst cases, with O(n) auxiliary space."

---

# 40. Quick Sort vs Merge Sort

This comparison is extremely likely to be asked because you have both experiments.

| Feature        | Quick Sort       | Merge Sort       |
| -------------- | ---------------- | ---------------- |
| Technique      | Divide & Conquer | Divide & Conquer |
| Division       | Based on pivot   | Always halves    |
| Pivot          | Required         | Not required     |
| Best           | O(n log n)       | O(n log n)       |
| Average        | O(n log n)       | O(n log n)       |
| Worst          | **O(n²)**        | **O(n log n)**   |
| Extra space    | O(log n) average | **O(n)**         |
| In-place       | Usually yes      | No               |
| Stable         | Usually no       | **Yes**          |
| Main operation | Partition        | Merge            |

---

# 41. Jury Question — Which is better?

If they ask:

> **Which is better, Quick Sort or Merge Sort?**

Don't simply say one is always better.

Say:

> "It depends on the application. Quick Sort is usually memory-efficient because it can work in-place and often performs very well in practice. Merge Sort guarantees O(n log n) worst-case time and is stable, but it requires O(n) additional memory for the standard array implementation."

That's a much better answer.

---

# 42. Jury Question — Why doesn't Merge Sort have O(n²)?

Because:

> Merge Sort always divides the array into approximately equal halves, and merging takes linear time at each level. Therefore there are O(log n) levels, each requiring O(n) work.

Hence:

$$
O(n\log n)
$$

---

# 43. Jury Question — Why does Merge Sort need extra memory?

Because during the merge operation we need a temporary array to store the combined sorted elements before copying them back.

Therefore:

$$
O(n)
$$

extra space.

---

# 44. Jury Question — What is merging?

> Merging is the process of combining two already sorted subarrays into one sorted array.

---

# 45. Jury Question — What is the base case?

```cpp
if (low < high)
```

When:

```text
low >= high
```

there is zero or one element, which is already sorted.

---

# 46. Jury Question — Is Merge Sort recursive?

Yes.

The standard implementation recursively divides the array into smaller subarrays.

---

# 47. Jury Question — Is Merge Sort a Divide and Conquer algorithm?

Yes.

It follows:

```text
Divide
   ↓
Conquer
   ↓
Combine
```

Specifically:

```text
Divide → split array
Conquer → recursively sort
Combine → merge
```

---

# 48. Jury Question — Is Merge Sort stable?

Yes, the standard Merge Sort can be stable.

---

# 49. Jury Question — Is Merge Sort in-place?

Standard array Merge Sort:

> No.

It generally requires:

$$
O(n)
$$

additional memory.

---

# 50. Jury Question — What is the time complexity?

Say:

```text
Best Case    = O(n log n)
Average Case = O(n log n)
Worst Case   = O(n log n)
```

---

# 51. Jury Question — What is space complexity?

For the standard implementation:

$$
\boxed{O(n)}
$$

because of the temporary array.

---

# 52. Important Recurrence

You may be asked to derive the complexity.

Merge Sort has:

$$
T(n)=2T(n/2)+O(n)
$$

Why?

Because:

```text
2T(n/2)
```

means:

* sort left half
* sort right half

and:

```text
O(n)
```

means merging the two halves.

Therefore:

$$
\boxed{T(n)=O(n\log n)}
$$

---

# 53. Quick Sort vs Merge Sort — Easy Memory Trick

Remember:

### Quick Sort:

> **Pivot → Partition**

### Merge Sort:

> **Split → Merge**

That's the easiest way to distinguish them.

```text
QUICK SORT
Pivot
 ↓
Partition
 ↓
Recursive sorting


MERGE SORT
Split
 ↓
Recursive sorting
 ↓
Merge
```

---

# 🎯 What You Should Say to the Jury

If they ask:

> **"Explain your Merge Sort experiment."**

You can say:

> "My experiment uses Merge Sort to arrange examination answer sheets according to enrollment numbers. Merge Sort is a Divide and Conquer sorting algorithm. First, the array is recursively divided into two halves until each subarray contains one element. Then the sorted subarrays are merged by comparing their elements. The merging continues until the complete array is sorted. Merge Sort has O(n log n) time complexity in best, average and worst cases. Its standard implementation requires O(n) auxiliary space because of the temporary array. It is also a stable sorting algorithm."

That's a strong **5-mark/viva answer**.

---

# 🧠 Experiment 4 Cheat Sheet

Write this on your mental revision sheet:

```text
                  MERGE SORT
                      |
              DIVIDE AND CONQUER
                      |
                    Split
                      ↓
                 Left | Right
                      ↓
               Recursive Sort
                      ↓
                    Merge
                      ↓
                 Sorted Array
```

### Complexity

```text
Best       = O(n log n)
Average    = O(n log n)
Worst      = O(n log n)

Space      = O(n)
```

### Key properties

```text
Stable       → YES
In-place     → NO (standard implementation)
Pivot        → NOT required
Recursion    → YES
```

### Most important comparison:

```text
Quick Sort              Merge Sort

Pivot                   No pivot
Partition               Merge
Worst O(n²)             Worst O(n log n)
Usually in-place        Extra O(n) space
Usually unstable        Stable
```

---

## 🔥 Four things to memorize tonight

If you're short on time, make absolutely sure you remember:

**1. Merge Sort formula**

$$
T(n)=2T(n/2)+O(n)
$$

**2. Complexity**

$$
\boxed{O(n\log n)}
$$

for **best, average and worst**.

**3. Space**

$$
\boxed{O(n)}
$$

**4. Core process**

> **Divide → Recursively Sort → Merge**

---

**Experiment 4 is complete.**

Next we'll do **Experiment 5 — Matrix Multiplication: "Accelerating Image Transformations in Augmented Reality."** This one is conceptually different from Quick/Merge Sort. I'll first teach you **ordinary matrix multiplication from zero**, then explain how matrices represent **translation, rotation and scaling in AR**, identify the performance bottleneck, and finally explain the **optimization/divide-and-conquer approach** your experiment is asking for.
