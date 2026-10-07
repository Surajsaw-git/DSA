# Experiment 2 — Binary Search

Your experiment says:

> **To use binary search to quickly locate a book record in a library system based on ISBN (0–100) or Title (A–Z).**
>
> (i) Recursion
> (ii) Iteration
>
> Compare time and space complexity of both designs.

We will learn this from **zero**, so that you can both **write the code and explain it confidently in your jury**.

---

# 1. First understand the problem

Imagine a library has books arranged by ISBN:

```text
101  115  123  145  167  189  205  220  250
```

You want to find:

```text
205
```

One simple approach is **Linear Search**:

```text
101 → 115 → 123 → 145 → 167 → 189 → 205
```

You check one by one.

But this can be slow if there are thousands or millions of books.

Instead, we can use **Binary Search**.

---

# 2. What is Binary Search?

Binary Search is a searching algorithm that repeatedly **divides the search range into two halves**.

The most important condition is:

> 🔴 **The data must be sorted.**

For example:

```text
10 20 30 40 50 60 70 80 90
```

is sorted.

But:

```text
10 50 20 90 30 40
```

is not sorted, so normal binary search cannot be directly applied.

---

# 3. Basic Idea

Suppose we want to find:

```text
70
```

in:

```text
10 20 30 40 50 60 70 80 90
```

First, look at the **middle element**.

```text
10 20 30 40 50 60 70 80 90
            ↑
           50
```

Compare:

```text
70 > 50
```

Therefore, 70 cannot be in the left half.

So we eliminate:

```text
10 20 30 40 50
```

and search only:

```text
60 70 80 90
```

Again find the middle:

```text
60 70 80 90
   ↑
   70
```

Found!

---

# 4. Why is Binary Search fast?

Suppose we have:

```text
1000 elements
```

Linear search might need:

```text
1000 comparisons
```

Binary search approximately does:

```text
1000
 ↓
500
 ↓
250
 ↓
125
 ↓
62
 ↓
31
 ↓
15
 ↓
7
 ↓
3
 ↓
1
```

Only around:

$$
\log_2(1000) \approx 10
$$

steps.

That's why binary search is called a **fast searching algorithm**.

---

# 5. Important Terms

In binary search we use three variables:

```text
low
mid
high
```

For example:

```text
10 20 30 40 50 60 70 80 90
↑               ↑         ↑
low             mid       high
```

Initially:

```cpp
low = 0;
high = n - 1;
```

Middle is:

```cpp
mid = low + (high - low) / 2;
```

---

# 6. Why do we use this formula?

You may see:

```cpp
mid = (low + high) / 2;
```

This works in normal situations.

But the safer standard formula is:

```cpp
mid = low + (high - low) / 2;
```

It avoids potential integer overflow when `low` and `high` are extremely large.

For your practical exam, either may be accepted, but I recommend:

```cpp
mid = low + (high - low) / 2;
```

---

# 7. Binary Search Logic

Suppose:

```text
Array = 10 20 30 40 50 60 70 80 90
Target = 70
```

Initially:

```text
low = 0
high = 8
```

Calculate:

```text
mid = 0 + (8 - 0)/2
    = 4
```

So:

```text
array[4] = 50
```

Compare:

```text
target = 70
mid value = 50
```

Since:

```text
70 > 50
```

we search the right side.

Therefore:

```text
low = mid + 1
```

Now:

```text
low = 5
high = 8
```

Calculate:

```text
mid = 5 + (8 - 5)/2
    = 6
```

Then:

```text
array[6] = 70
```

Found!

---

# 8. Three Important Cases

This is extremely important for your viva.

After finding the middle element:

### Case 1 — Element found

```text
target == array[mid]
```

Return `mid`.

---

### Case 2 — Target is greater

```text
target > array[mid]
```

Search right half:

```cpp
low = mid + 1;
```

---

### Case 3 — Target is smaller

```text
target < array[mid]
```

Search left half:

```cpp
high = mid - 1;
```

Remember:

```text
target == arr[mid]
        ↓
      FOUND

target > arr[mid]
        ↓
    go RIGHT

target < arr[mid]
        ↓
     go LEFT
```

---

# PART A — ITERATIVE BINARY SEARCH

Let's first understand the easier implementation.

---

# 9. Iterative Binary Search

Iteration means using a loop.

We will use:

```cpp
while (low <= high)
```

---

## 10. Algorithm

```text
BinarySearch(array, n, target)

low = 0
high = n - 1

while low <= high

    mid = low + (high-low)/2

    if array[mid] == target
        return mid

    else if target > array[mid]
        low = mid + 1

    else
        high = mid - 1

return -1
```

---

# 11. Simple C++ Code

```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    int n = 9;
    int target;

    cout << "Enter element to search: ";
    cin >> target;

    int result = binarySearch(arr, n, target);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}
```

---

# 12. Understand the code line by line

## Function

```cpp
int binarySearch(int arr[], int n, int target)
```

It receives three things:

```text
arr    → array
n      → number of elements
target → element we want to find
```

---

## Initialize low

```cpp
int low = 0;
```

The first index is:

```text
0
```

So:

```text
low = 0
```

---

## Initialize high

```cpp
int high = n - 1;
```

If:

```text
n = 9
```

last index is:

```text
8
```

Therefore:

```text
high = 8
```

---

# 13. Why `while (low <= high)`?

```cpp
while (low <= high)
```

This means:

> Continue searching as long as there is at least one element in the search range.

For example:

```text
low = 4
high = 4
```

There is still one element.

So:

```text
4 <= 4
```

is true.

But:

```text
low = 5
high = 4
```

means no elements remain.

So:

```text
5 <= 4
```

is false.

Search stops.

---

# 14. Calculate middle

```cpp
int mid = low + (high - low) / 2;
```

Suppose:

```text
low = 0
high = 8
```

Then:

```text
mid = 0 + (8 - 0)/2
    = 4
```

---

# 15. Check whether found

```cpp
if (arr[mid] == target)
```

If:

```text
arr[mid] = 50
target = 50
```

then:

```text
50 == 50
```

True.

Return:

```cpp
return mid;
```

---

# 16. Search right half

```cpp
else if (target > arr[mid])
{
    low = mid + 1;
}
```

Suppose:

```text
target = 70
arr[mid] = 50
```

Since:

```text
70 > 50
```

the target must be on the right.

So:

```text
low = mid + 1
```

---

# 17. Search left half

```cpp
else
{
    high = mid - 1;
}
```

Suppose:

```text
target = 30
arr[mid] = 50
```

Since:

```text
30 < 50
```

target must be on the left.

Therefore:

```text
high = mid - 1
```

---

# 18. What does `return -1` mean?

```cpp
return -1;
```

means:

> Element was not found.

Why `-1`?

Because valid array indices are:

```text
0, 1, 2, 3, ...
```

`-1` is not a valid index, so we can use it to indicate failure.

---

# 19. Dry Run — Iterative Binary Search

Array:

```text
10 20 30 40 50 60 70 80 90
```

Target:

```text
70
```

### Step 1

```text
low = 0
high = 8
mid = 4
```

```text
arr[4] = 50
```

Compare:

```text
70 > 50
```

So:

```text
low = 5
```

---

### Step 2

```text
low = 5
high = 8
```

Calculate:

```text
mid = 5 + (8 - 5)/2
    = 6
```

```text
arr[6] = 70
```

Compare:

```text
70 == 70
```

Therefore:

```text
FOUND
```

Index:

```text
6
```

---

# PART B — RECURSIVE BINARY SEARCH

Now we'll implement the same algorithm using recursion.

---

# 20. Main idea

Instead of:

```cpp
while (low <= high)
```

we call the function again with a smaller range.

For example:

```text
binarySearch(arr, low, mid-1, target)
```

or:

```text
binarySearch(arr, mid+1, high, target)
```

---

# 21. Recursive Algorithm

```text
BinarySearch(arr, low, high, target)

if low > high
    return -1

mid = low + (high-low)/2

if arr[mid] == target
    return mid

else if target < arr[mid]
    return BinarySearch(arr, low, mid-1, target)

else
    return BinarySearch(arr, mid+1, high, target)
```

---

# 22. C++ Code

```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target)
{
    // Base case: element not found
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    // Element found
    if (arr[mid] == target)
    {
        return mid;
    }

    // Search left half
    if (target < arr[mid])
    {
        return binarySearch(arr, low, mid - 1, target);
    }

    // Search right half
    return binarySearch(arr, mid + 1, high, target);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    int n = 9;
    int target;

    cout << "Enter element to search: ";
    cin >> target;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}
```

---

# 23. Understand the Recursive Code

The most important difference is this:

### Iterative:

```cpp
while (low <= high)
```

### Recursive:

```cpp
return binarySearch(...);
```

The recursive function calls itself with a smaller search range.

---

# 24. Base Case

```cpp
if (low > high)
{
    return -1;
}
```

This is extremely important.

Suppose we have:

```text
low = 5
high = 4
```

No elements remain.

Therefore:

```text
low > high
```

and we return:

```text
-1
```

---

# 25. Recursive Left Search

If:

```text
target < arr[mid]
```

then:

```cpp
return binarySearch(arr, low, mid - 1, target);
```

We throw away the right half.

---

# 26. Recursive Right Search

If:

```text
target > arr[mid]
```

then:

```cpp
return binarySearch(arr, mid + 1, high, target);
```

We throw away the left half.

---

# 27. Recursive Dry Run

Array:

```text
10 20 30 40 50 60 70 80 90
```

Target:

```text
70
```

Call:

```text
binarySearch(arr, 0, 8, 70)
```

Calculate:

```text
mid = 4
arr[4] = 50
```

Since:

```text
70 > 50
```

call:

```text
binarySearch(arr, 5, 8, 70)
```

Again:

```text
mid = 6
arr[6] = 70
```

Therefore:

```text
70 == 70
```

Return:

```text
6
```

The result goes back through the recursive calls.

---

# 28. Recursion Visualization

Think of it like this:

```text
binarySearch(0,8)
       |
       | target > mid
       ↓
binarySearch(5,8)
       |
       | target == mid
       ↓
      FOUND
```

If searching for `30`:

```text
binarySearch(0,8)
       |
       | 30 < 50
       ↓
binarySearch(0,3)
       |
       | 30 > 20
       ↓
binarySearch(2,3)
       |
       ↓
     FOUND
```

---

# 29. Time Complexity

This is one of the most important things to remember.

At every step, binary search eliminates approximately **half of the elements**.

Therefore:

$$
n \rightarrow \frac n2 \rightarrow \frac n4 \rightarrow \frac n8 ...
$$

After `k` steps:

$$
\frac{n}{2^k}=1
$$

Therefore:

$$
2^k=n
$$

Taking logarithm:

$$
k=\log_2 n
$$

So:

$$
\boxed{O(\log n)}
$$

---

# 30. Best Case

When is binary search fastest?

If the target is the middle element during the first comparison.

Example:

```text
10 20 30 40 50 60 70
         ↑
        40
```

If target = `40`, found immediately.

Only one comparison.

Therefore:

$$
\boxed{O(1)}
$$

---

# 31. Average Case

On average, binary search repeatedly divides the array in half.

Therefore:

$$
\boxed{O(\log n)}
$$

---

# 32. Worst Case

The target may be:

* near the end
* or not present at all

We continue dividing until only one element remains.

Therefore:

$$
\boxed{O(\log n)}
$$

---

# 33. Time Complexity Table

| Case    |   Complexity |
| ------- | -----------: |
| Best    |     **O(1)** |
| Average | **O(log n)** |
| Worst   | **O(log n)** |

This is **very important for viva**.

---

# 34. Space Complexity — Iterative

Iterative binary search uses:

```text
low
high
mid
```

Only a fixed number of variables.

Therefore:

$$
\boxed{O(1)}
$$

---

# 35. Space Complexity — Recursive

Every recursive function call is stored in the call stack.

Maximum recursive depth:

$$
O(\log n)
$$

Therefore:

$$
\boxed{O(\log n)}
$$

So:

| Implementation |     Time |        Space |
| -------------- | -------: | -----------: |
| Iterative      | O(log n) |     **O(1)** |
| Recursive      | O(log n) | **O(log n)** |

---

# ⭐ 36. Very Important Comparison

Your experiment specifically asks:

> Compare time and space complexity of both designs.

Remember this:

```text
                    Binary Search

              Iterative       Recursive
              
Time           O(log n)       O(log n)

Space          O(1)           O(log n)
```

### Key point:

**Both have the same time complexity.**

But:

**Iterative uses less memory.**

Why?

Because recursion requires the **call stack**.

---

# 37. Binary Search vs Linear Search

The jury may ask this.

| Feature           | Linear Search    | Binary Search         |
| ----------------- | ---------------- | --------------------- |
| Data requirement  | Can be unsorted  | **Must be sorted**    |
| Approach          | Check one by one | Divide into halves    |
| Best case         | O(1)             | O(1)                  |
| Average           | O(n)             | O(log n)              |
| Worst             | O(n)             | O(log n)              |
| Implementation    | Simpler          | Slightly more complex |
| Large sorted data | Slow             | **Very fast**         |

---

# 38. What about ISBN?

Your experiment specifically mentions:

> ISBN `(0–100)`

Suppose books have ISBNs:

```text
10
25
30
45
60
75
90
```

and we want:

```text
60
```

We can use binary search directly because ISBN values are numeric and sorted.

---

# 39. What about Book Title?

The experiment also says:

> Title `(A–Z)`

Suppose titles are:

```text
Algorithms
Computer Networks
Database Systems
Operating Systems
Python Programming
```

They are alphabetically sorted.

We can perform binary search using **string comparison**.

For example:

```cpp
if (titles[mid] == target)
```

and:

```cpp
if (target > titles[mid])
```

String comparison works lexicographically in C++.

---

# 40. Simple Title Search Example

```cpp
#include <iostream>
#include <string>
using namespace std;

int binarySearch(string books[], int n, string target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (books[mid] == target)
        {
            return mid;
        }
        else if (target > books[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    string books[] =
    {
        "Algorithms",
        "Computer Networks",
        "Database Systems",
        "Operating Systems",
        "Python Programming"
    };

    int n = 5;
    string target;

    cout << "Enter book title: ";
    getline(cin, target);

    int result = binarySearch(books, n, target);

    if (result != -1)
        cout << "Book found at index " << result;
    else
        cout << "Book not found";

    return 0;
}
```

The **algorithm remains exactly the same**.

The only major difference is:

```cpp
int arr[]
```

becomes:

```cpp
string books[]
```

---

# 41. Important Condition — SORTED DATA

Suppose:

```text
10 50 20 80 30
```

You want to find:

```text
30
```

Binary search cannot safely determine which half to discard because the data isn't sorted.

Therefore:

> **Binary Search requires sorted data.**

This is probably one of the first questions your jury can ask.

---

# 🎯 Important Viva Questions

## Q1. What is binary search?

> Binary search is a searching algorithm that works on sorted data by repeatedly dividing the search space into two halves.

---

## Q2. What is the main requirement of binary search?

> The input data must be sorted.

---

## Q3. Why is binary search faster than linear search?

> Binary search eliminates approximately half of the remaining elements after each comparison, resulting in O(log n) time complexity.

---

## Q4. What are `low`, `mid`, and `high`?

> `low` represents the first index of the current search range, `high` represents the last index, and `mid` represents the middle index.

---

## Q5. How do you calculate mid?

```cpp
mid = low + (high - low) / 2;
```

---

## Q6. What happens when target > arr[mid]?

> We search the right half by setting `low = mid + 1`.

---

## Q7. What happens when target < arr[mid]?

> We search the left half by setting `high = mid - 1`.

---

## Q8. What happens when target == arr[mid]?

> The element is found and we return the middle index.

---

## Q9. What is the best-case time complexity?

$$
O(1)
$$

Because the target may be the first middle element checked.

---

## Q10. What is the worst-case time complexity?

$$
O(\log n)
$$

---

## Q11. What is the iterative space complexity?

$$
O(1)
$$

---

## Q12. What is recursive space complexity?

$$
O(\log n)
$$

because of recursive function calls stored in the call stack.

---

## Q13. Which is better: recursive or iterative binary search?

> Both have O(log n) time complexity, but iterative binary search is generally more memory-efficient because it requires O(1) auxiliary space compared with O(log n) recursive stack space.

---

## Q14. Can binary search work on an unsorted array?

> No, not in its standard form. The data must be sorted.

---

## Q15. Can binary search work with strings?

> Yes. If the strings are sorted lexicographically, binary search can be used to search titles alphabetically.

---

# 🧠 Jury Trick Question

They may ask:

> **"Why don't we always use binary search instead of linear search?"**

Good answer:

> Binary search requires the data to be sorted. If the data is unsorted or the dataset is very small, linear search may be more suitable. Also, if data changes frequently and maintaining sorted order is expensive, binary search may not always be the best choice.

Excellent answer for viva.

---

# 🧠 Your Memory Sheet

Before moving to the next experiment, remember this:

```text
                 BINARY SEARCH
                       |
                Data must be SORTED
                       |
             Find middle element
                       |
          ┌────────────┼────────────┐
          ↓            ↓            ↓
       target <     target ==     target >
        arr[mid]     arr[mid]      arr[mid]
          ↓            ↓            ↓
       LEFT          FOUND         RIGHT
          ↓                         ↓
 high=mid-1                   low=mid+1
```

### Complexity:

```text
Best case      = O(1)
Average case   = O(log n)
Worst case     = O(log n)

Iterative space = O(1)
Recursive space = O(log n)
```

### The most important comparison:

```text
                 ITERATIVE      RECURSIVE
Time             O(log n)       O(log n)
Space            O(1)           O(log n)
```

---

# 🔥 What You Should Be Able to Do in the Jury

Given:

```text
10 20 30 40 50 60 70 80 90
```

and target:

```text
80
```

you should immediately be able to explain:

```text
low = 0
high = 8
mid = 4
arr[mid] = 50

80 > 50
→ right half

low = 5
high = 8
mid = 6
arr[mid] = 70

80 > 70
→ right half

low = 7
high = 8
mid = 7
arr[mid] = 80

FOUND
```

If you can do this on paper, **you understand binary search rather than merely memorizing the code.**

---

## One final distinction

For your **Experiment 2**, you should keep these two codes ready:

**Iterative:**

```cpp
while (low <= high)
```

**Recursive:**

```cpp
return binarySearch(arr, low, mid - 1, target);
```

and:

```cpp
return binarySearch(arr, mid + 1, high, target);
```

Those are the key differences.

**Experiment 2 is complete.**

When you say **"continue"**, we'll start **Experiment 3 — Quick Sort**, and this one is especially important because your jury can ask you to explain **Divide and Conquer, pivot selection, partitioning, recursion, and best/average/worst-case complexity**, followed by the complete C++ program and a full dry run.
