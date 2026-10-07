# Experiment 6 — Fractional Knapsack

## Greedy Algorithm

This experiment is **very important for your jury** because it tests whether you understand the **Greedy approach**, not just the code.

Your experiment says:

> A delivery company has items with different weights and profits. A truck has a limited weight capacity. Use a Greedy approach to maximize profit. Fractional inclusion of items is allowed. Display selected items/fractions and maximum profit.

The keyword here is:

# ⭐ FRACTIONAL KNAPSACK

Because fractions are allowed, we can use the **Greedy Algorithm**.

---

# 1. First understand the real-world problem

Imagine a truck can carry:

```text
Maximum capacity = 15 kg
```

We have:

| Item | Weight | Profit |
| ---- | -----: | -----: |
| 1    |   2 kg |    ₹10 |
| 2    |   3 kg |     ₹5 |
| 3    |   5 kg |    ₹15 |
| 4    |   7 kg |     ₹7 |
| 5    |   1 kg |     ₹6 |
| 6    |   4 kg |    ₹18 |
| 7    |   1 kg |     ₹3 |

We want:

> **Maximum possible profit without exceeding 15 kg.**

And importantly:

> We can take a **fraction** of an item.

For example, if an item weighs 4 kg and we have only 2 kg capacity left, we can take:

```text
2 / 4 = 0.5
```

of the item.

---

# 2. What is the Knapsack Problem?

The Knapsack Problem is an optimization problem.

We have:

```text
Items
  ↓
Weight + Profit
  ↓
Limited capacity
  ↓
Maximize profit
```

Mathematically:

$$
\text{Maximize Profit}
$$

subject to:

$$
\sum w_i x_i \leq W
$$

where:

* \(w_i\) = weight
* \(x_i\) = fraction selected
* \(W\) = capacity

For Fractional Knapsack:

$$
0\leq x_i\leq1
$$

---

# 3. Why is this called Fractional Knapsack?

Because:

### 0/1 Knapsack

You can take:

```text
0 → Don't take
1 → Take completely
```

You cannot take half.

### Fractional Knapsack

You can take:

```text
0
0.25
0.5
0.75
1
```

etc.

---

# 4. Why can we use Greedy?

This is the most important concept.

We calculate:

$$
\boxed{\frac{Profit}{Weight}}
$$

This tells us:

> **How much profit we get per unit of weight.**

We call this:

# Profit-to-weight ratio

or:

# Profit density

---

# 5. Example

Suppose:

```text
Item 1:
Weight = 2
Profit = 10
```

Ratio:

$$
\frac{10}{2}=5
$$

So:

```text
₹5 profit per kg
```

Another:

```text
Item 2:
Weight = 3
Profit = 5
```

Ratio:

$$
\frac{5}{3}=1.67
$$

So item 1 is much better.

Therefore, we prefer:

```text
Higher profit/weight ratio
```

---

# 6. The Greedy Strategy

The strategy is:

> **Always select the item having the highest profit-to-weight ratio first.**

Then:

1. Take the complete item if possible.
2. If the remaining capacity isn't enough, take the required fraction.
3. Stop when the truck is full.

So:

```text id="u8d3mj"
Calculate profit/weight
        ↓
Sort descending
        ↓
Highest ratio first
        ↓
Take item
        ↓
Capacity remaining?
        ↓
Yes → Continue
No → Take fraction and stop
```

---

# 7. Very Important

The sorting order is:

$$
\boxed{\text{Highest } \frac{Profit}{Weight} \text{ first}}
$$

NOT:

```text
Highest profit first
```

and NOT:

```text
Lowest weight first
```

This is one of the most common mistakes.

---

# 8. Let's Solve Your Earlier Example

The data from your previous practical discussion is:

```text id="3b0p4f"
n = 7
Capacity = 15

Profit:
10  5  15  7  6  18  3

Weight:
2   3   5   7   1   4   1
```

Let's solve it completely.

---

# 9. Step 1 — Calculate Profit/Weight

Formula:

$$
Ratio=\frac{Profit}{Weight}
$$

### Item 1

$$
10/2=5
$$

### Item 2

$$
5/3=1.67
$$

### Item 3

$$
15/5=3
$$

### Item 4

$$
7/7=1
$$

### Item 5

$$
6/1=6
$$

### Item 6

$$
18/4=4.5
$$

### Item 7

$$
3/1=3
$$

Now table:

| Item | Profit | Weight | Profit/Weight |
| ---- | -----: | -----: | ------------: |
| 1    |     10 |      2 |         **5** |
| 2    |      5 |      3 |          1.67 |
| 3    |     15 |      5 |         **3** |
| 4    |      7 |      7 |             1 |
| 5    |      6 |      1 |         **6** |
| 6    |     18 |      4 |       **4.5** |
| 7    |      3 |      1 |         **3** |

---

# 10. Step 2 — Sort by Ratio

Descending order:

```text id="q0o0c4"
Item 5 → 6
Item 1 → 5
Item 6 → 4.5
Item 3 → 3
Item 7 → 3
Item 2 → 1.67
Item 4 → 1
```

So:

| Order |  Item | Weight | Profit |    Ratio |
| ----: | ----: | -----: | -----: | -------: |
|     1 | **5** |      1 |      6 |    **6** |
|     2 | **1** |      2 |     10 |    **5** |
|     3 | **6** |      4 |     18 |  **4.5** |
|     4 | **3** |      5 |     15 |    **3** |
|     5 | **7** |      1 |      3 |    **3** |
|     6 | **2** |      3 |      5 | **1.67** |
|     7 | **4** |      7 |      7 |    **1** |

Capacity:

```text id="4s1q5v"
15 kg
```

---

# 11. Step 3 — Select Item 5

Item 5:

```text
Weight = 1
Profit = 6
```

Capacity:

```text
15
```

We can take the complete item.

Remaining capacity:

$$
15-1=14
$$

Profit:

$$
6
$$

---

# 12. Select Item 1

Item 1:

```text
Weight = 2
Profit = 10
```

Remaining capacity:

```text
14 kg
```

Take full item.

Remaining:

$$
14-2=12
$$

Profit:

$$
6+10=16
$$

---

# 13. Select Item 6

Item 6:

```text
Weight = 4
Profit = 18
```

Remaining capacity:

```text
12 kg
```

Take complete item.

Remaining:

$$
12-4=8
$$

Profit:

$$
16+18=34
$$

---

# 14. Select Item 3

Item 3:

```text
Weight = 5
Profit = 15
```

Remaining capacity:

```text
8 kg
```

Take complete item.

Remaining:

$$
8-5=3
$$

Profit:

$$
34+15=49
$$

---

# 15. Select Item 7

Item 7:

```text
Weight = 1
Profit = 3
```

Remaining:

```text
3 kg
```

Take complete item.

Remaining:

$$
3-1=2
$$

Profit:

$$
49+3=52
$$

---

# 16. Item 2

Item 2:

```text
Weight = 3
Profit = 5
```

But remaining capacity:

```text
2 kg
```

We cannot take all 3 kg.

But this is **Fractional Knapsack**.

So we take:

$$
\frac{2}{3}
$$

of Item 2.

---

# 17. Calculate Fractional Profit

Full item:

```text
Weight = 3
Profit = 5
```

We take:

$$
2/3
$$

Therefore profit:

$$
5\times\frac{2}{3}
$$

$$
=\frac{10}{3}
$$

$$
=3.33
$$

So total profit:

$$
52+3.33
$$

$$
=\boxed{55.33}
$$

Truck is now full:

$$
1+2+4+5+1+2=15
$$

---

# 18. Final Answer

Selected:

```text id="x0f7vb"
Item 5 → 100%
Item 1 → 100%
Item 6 → 100%
Item 3 → 100%
Item 7 → 100%
Item 2 → 2/3
Item 4 → 0%
```

Final:

$$
\boxed{\text{Maximum Profit}=55.33}
$$

Weight:

$$
\boxed{15}
$$

---

# 19. Final Selection Table

| Item      | Weight Taken | Fraction |    Profit |
| --------- | -----------: | -------: | --------: |
| 5         |            1 |        1 |         6 |
| 1         |            2 |        1 |        10 |
| 6         |            4 |        1 |        18 |
| 3         |            5 |        1 |        15 |
| 7         |            1 |        1 |         3 |
| 2         |            2 |      2/3 |      3.33 |
| 4         |            0 |        0 |         0 |
| **Total** |       **15** |          | **55.33** |

---

# 20. Now Understand Why Greedy Works Here

The important thing is:

> We are allowed to take fractions.

Suppose we have only 2 kg remaining.

If the next item weighs 3 kg, we can take exactly:

$$
2/3
$$

of it.

Therefore, choosing the highest profit-per-weight item is optimal.

This is why the Greedy strategy works for **Fractional Knapsack**.

---

# 21. Very Important — Greedy Does NOT Always Work for 0/1 Knapsack

This is a classic viva question.

If items cannot be divided, choosing the highest ratio first can produce a non-optimal solution.

Therefore:

```text id="83uz6e"
Fractional Knapsack
       ↓
Greedy works
```

but:

```text id="lbllz6"
0/1 Knapsack
       ↓
Greedy does NOT generally guarantee optimal solution
       ↓
Dynamic Programming commonly used
```

Memorize this.

---

# 22. C++ Structure

We need a structure to store:

```text
Item number
Profit
Weight
Ratio
```

We can create:

```cpp id="j6xyy6"
struct Item
{
    int id;
    float profit;
    float weight;
    float ratio;
};
```

---

# 23. Why do we need a Structure?

Because each item has multiple properties.

For example:

```text id="7wxt3x"
Item 1
Profit = 10
Weight = 2
Ratio = 5
```

Instead of using separate unrelated arrays, a structure groups them together.

---

# 24. Sorting Items

After calculating ratios, we need to sort them in descending order.

We can use:

```cpp id="vky7u3"
sort(items, items + n, compare);
```

The comparison function:

```cpp id="8p7vfk"
bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}
```

means:

> Put the item with the larger ratio first.

---

# 25. Complete C++ Program

This is the version you should practice for the jury:

```cpp id="k70fx8"
#include <iostream>
#include <algorithm>

using namespace std;

struct Item
{
    int id;
    float profit;
    float weight;
    float ratio;
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int n;
    float capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter profit and weight of each item:\n";

    for (int i = 0; i < n; i++)
    {
        items[i].id = i + 1;

        cin >> items[i].profit;
        cin >> items[i].weight;

        items[i].ratio =
            items[i].profit / items[i].weight;
    }

    cout << "Enter truck capacity: ";
    cin >> capacity;

    // Sort according to profit/weight ratio
    sort(items, items + n, compare);

    float totalProfit = 0;

    cout << "\nSelected Items:\n";

    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
            break;

        // Take complete item
        if (items[i].weight <= capacity)
        {
            capacity -= items[i].weight;

            totalProfit += items[i].profit;

            cout << "Item " << items[i].id
                 << " -> 100% selected\n";
        }

        // Take fraction
        else
        {
            float fraction =
                capacity / items[i].weight;

            totalProfit +=
                items[i].profit * fraction;

            cout << "Item " << items[i].id
                 << " -> "
                 << fraction * 100
                 << "% selected\n";

            capacity = 0;
        }
    }

    cout << "\nMaximum Profit = "
         << totalProfit << endl;

    return 0;
}
```

---

# 26. Understand the Code

The program has four major stages:

```text id="lq4d0n"
Input
 ↓
Calculate ratio
 ↓
Sort by ratio
 ↓
Select items greedily
```

---

# 27. Structure

```cpp id="0n0dgs"
struct Item
{
    int id;
    float profit;
    float weight;
    float ratio;
};
```

Each item contains:

```text
id
profit
weight
ratio
```

---

# 28. Calculate Ratio

Inside the loop:

```cpp id="v0k9th"
items[i].ratio =
    items[i].profit / items[i].weight;
```

For example:

```text id="f6wxal"
profit = 18
weight = 4
```

gives:

$$
18/4=4.5
$$

---

# 29. Sorting

```cpp id="h9yt7p"
sort(items, items + n, compare);
```

This sorts the items.

The comparison:

```cpp id="l5qjs8"
return a.ratio > b.ratio;
```

means descending order.

So:

```text id="85sl30"
6
5
4.5
3
...
```

---

# 30. Complete Item Selection

```cpp id="8tfr6v"
if (items[i].weight <= capacity)
```

If the entire item fits:

```cpp id="1ymc2a"
capacity -= items[i].weight;
totalProfit += items[i].profit;
```

So we take 100%.

---

# 31. Fractional Selection

If the item doesn't fit:

```cpp id="p3hl6g"
float fraction =
    capacity / items[i].weight;
```

Suppose:

```text id="qmyo1f"
capacity = 2
weight = 3
```

Then:

$$
fraction=2/3
$$

Then:

```cpp id="u8nt9n"
totalProfit += items[i].profit * fraction;
```

If profit = 5:

$$
5\times2/3=3.33
$$

---

# 32. Why do we set capacity to zero?

```cpp id="y1a1q9"
capacity = 0;
```

Because once we take the fraction that fills the remaining capacity, the truck is full.

There is no reason to continue.

---

# 33. Time Complexity

Our algorithm does:

### Step 1

Calculate ratios:

$$
O(n)
$$

### Step 2

Sort items:

$$
O(n\log n)
$$

### Step 3

Traverse items:

$$
O(n)
$$

Total:

$$
O(n)+O(n\log n)+O(n)
$$

Dominant term:

$$
\boxed{O(n\log n)}
$$

---

# 34. Space Complexity

We store `n` items:

```text id="m8f5dj"
id
profit
weight
ratio
```

Therefore:

$$
\boxed{O(n)}
$$

depending on the sorting implementation and storage.

For your practical answer:

> **Time = O(n log n), Space = O(n).**

---

# 35. Why Is This a Greedy Algorithm?

This is a very likely viva question.

Answer:

> "It is a Greedy algorithm because at every step we make the locally optimal choice—the item with the highest profit-to-weight ratio—without reconsidering previous choices."

---

# 36. What is Greedy Algorithm?

A Greedy Algorithm:

> **Makes the best-looking choice at the current step, hoping that these local optimal choices lead to a global optimum.**

In Fractional Knapsack:

```text id="qgwh0b"
Local best choice
        ↓
Highest profit/weight
        ↓
Take item/fraction
        ↓
Repeat
```

---

# 37. Greedy Properties

Two important concepts often associated with problems where greedy methods work are:

### 1. Greedy-choice property

A globally optimal solution can be reached by making the appropriate greedy choice at each step.

### 2. Optimal substructure

An optimal solution contains optimal solutions to its subproblems.

For your level, remember these terms because the jury may ask.

---

# 38. Fractional vs 0/1 Knapsack

Very important:

| Feature              | Fractional      | 0/1                 |
| -------------------- | --------------- | ------------------- |
| Item can be divided? | **Yes**         | No                  |
| Greedy works?        | **Yes**         | Generally no        |
| Typical approach     | **Greedy**      | Dynamic Programming |
| Selection            | 0 to 1 fraction | 0 or 1              |
| Example              | 2/3 of item     | Whole item only     |

---

# 39. Jury Question: Why ratio instead of profit?

Suppose:

```text id="l1t8in"
Item A:
Profit = 100
Weight = 100

Item B:
Profit = 60
Weight = 10
```

Ratios:

```text id="r5m58n"
A = 100/100 = 1

B = 60/10 = 6
```

Although A has higher total profit, B gives much more profit per unit of capacity.

Therefore, for fractional knapsack:

> We use **profit/weight ratio**.

---

# 40. Jury Question: Why do we sort in descending order?

Because:

> We want to select the item providing the highest profit per unit of weight first.

---

# 41. Jury Question: What happens when an item doesn't fit?

If fractions are allowed:

> We take the fraction that exactly fills the remaining capacity.

Formula:

$$
Fraction=\frac{Remaining\ Capacity}{Item\ Weight}
$$

---

# 42. Jury Question: Can fraction be greater than 1?

No.

Because:

$$
0\leq fraction\leq1
$$

If:

```text id="r7w8sq"
capacity = 2
weight = 3
```

fraction:

$$
2/3
$$

If:

```text id="w7l4y9"
capacity = 5
weight = 3
```

we don't calculate `5/3`.

We simply take the whole item because it fits.

---

# 43. Jury Question: What is the time complexity?

> **O(n log n)** because calculating ratios and selecting items take O(n), while sorting the items by profit-to-weight ratio takes O(n log n).

---

# 44. Jury Question: What is the space complexity?

> **O(n)** to store the items and their profit-to-weight ratios.

---

# 45. Jury Question: Why isn't Fractional Knapsack O(n)?

Because we need to sort the items based on:

$$
Profit/Weight
$$

Sorting takes:

$$
O(n\log n)
$$

and dominates the linear traversal.

---

# 46. Jury Question: Give an example where greedy fails for 0/1 knapsack

A classic example:

Capacity:

```text id="up6a5a"
50
```

Items:

| Item | Weight | Profit |
| ---- | -----: | -----: |
| A    |     10 |     60 |
| B    |     20 |    100 |
| C    |     30 |    120 |

Ratios:

```text id="09o7x4"
A = 6
B = 5
C = 4
```

Greedy picks A and B:

```text
Weight = 30
Profit = 160
```

Remaining capacity:

```text
20
```

C cannot fit.

But the optimal 0/1 solution is:

```text
B + C
```

Weight:

$$
20+30=50
$$

Profit:

$$
100+120=220
$$

So greedy fails for 0/1 knapsack.

But for **fractional** knapsack, we could take fractions and greedy would work.

---

# 47. Your Experiment's Complete Flow

You should visualize it as:

```text id="c0uk0v"
              FRACTIONAL KNAPSACK
                       |
                  Input Items
                       |
                Profit + Weight
                       |
                Calculate Ratio
                       |
             Profit / Weight
                       |
              Sort Descending
                       |
             Highest Ratio First
                       |
             ┌─────────┴─────────┐
             ↓                   ↓
       Item Fits             Item Doesn't Fit
             ↓                   ↓
       Take Complete         Take Fraction
             ↓                   ↓
             └─────────┬─────────┘
                       ↓
                 Update Capacity
                       ↓
                 Repeat
                       ↓
                Maximum Profit
```

---

# 48. What Should You Say to the Jury?

If they ask:

> **"Explain your Fractional Knapsack experiment."**

Say:

> "The Fractional Knapsack problem is an optimization problem where we have items with different weights and profits and a knapsack with limited capacity. Since fractions of items are allowed, I use a Greedy approach. First, I calculate the profit-to-weight ratio for every item. Then I sort the items in descending order of this ratio. I select the highest-ratio items first. If an entire item fits, I take it completely; otherwise, I take the fraction required to fill the remaining capacity. The time complexity is O(n log n) because of sorting, and the space complexity is O(n)."

That's an excellent viva answer.

---

# 🧠 FINAL CHEAT SHEET — FRACTIONAL KNAPSACK

### Formula:

$$
\boxed{Ratio=\frac{Profit}{Weight}}
$$

### Strategy:

```text id="s8b2wu"
Calculate ratio
      ↓
Sort descending
      ↓
Highest ratio first
      ↓
Take full item if possible
      ↓
Otherwise take fraction
```

### Complexity:

$$
\boxed{Time=O(n\log n)}
$$

$$
\boxed{Space=O(n)}
$$

### Critical distinction:

```text id="kqu6yt"
Fractional Knapsack
        ↓
Fractions allowed
        ↓
Greedy works


0/1 Knapsack
        ↓
Fractions NOT allowed
        ↓
Greedy does not generally work
        ↓
Dynamic Programming
```

### Most important viva words:

> **Greedy choice → Profit/Weight ratio → Descending sort → Fractional selection → O(n log n)**

---

# 🔥 One-minute revision

If your professor suddenly asks:

**"Why Greedy?"**

→ Because fractions are allowed, so selecting the highest profit per unit weight first leads to an optimal solution.

**"What do you calculate?"**

→ `profit / weight`.

**"Order?"**

→ Descending ratio.

**"If item doesn't fit?"**

→ Take the required fraction.

**"Time?"**

→ `O(n log n)`.

**"Space?"**

→ `O(n)`.

**"Does this work for 0/1 Knapsack?"**

→ No, not generally.

---

**Experiment 6 is complete.**

Next is your **last experiment — Experiment 7: Prim's Algorithm**. This is another very important jury topic. We'll start from **graphs → weighted graphs → spanning trees → minimum spanning trees → greedy concept → Prim's algorithm → adjacency matrix → complete C++ code → full dry run → complexity → Prim vs Kruskal → viva questions**.
