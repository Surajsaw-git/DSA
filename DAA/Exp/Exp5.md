# Experiment 5 — Matrix Multiplication

## Accelerating Image Transformations in Augmented Reality

This experiment looks complicated because it is written as a real-world AR problem, but the core programming concept is actually:

> **Matrix Multiplication**

And your jury can ask both the **mathematical concept** and the **algorithm/programming concept**.

We'll build it from zero.

---

# 1. First understand the problem statement

Your experiment says:

> A mobile AR app applies various transformations to object models using large matrices. With increasing model sizes and device resolution, users experience lag during rendering transitions. Find an approach that reduces computational load without compromising transformation accuracy.

Let's translate that into simple language.

Imagine an AR application displays a:

```text
3D car
```

on your mobile screen.

The user moves the car:

```text
Translation
```

rotates it:

```text
Rotation
```

or changes its size:

```text
Scaling
```

These transformations are represented using **matrices**.

For example:

```text
Object
   ↓
Transformation Matrix
   ↓
New Object Position
```

If the application has thousands of points and repeatedly performs matrix multiplication, the calculations become expensive.

---

# 2. What is a Matrix?

A matrix is simply a rectangular arrangement of numbers.

Example:

$$
A=
\begin{bmatrix}
1 & 2\\
3 & 4
\end{bmatrix}
$$

This is a:

```text
2 × 2 matrix
```

because it has:

```text
2 rows
2 columns
```

Another example:

$$
B=
\begin{bmatrix}
5 & 6\\
7 & 8
\end{bmatrix}
$$

---

# 3. Why are matrices used in computer graphics?

Matrices provide a convenient mathematical way to transform points.

For example, we can use matrices for:

* Translation
* Rotation
* Scaling
* Reflection
* Projection
* Transformation of 3D objects

This is why matrices are heavily used in:

* Computer graphics
* AR
* VR
* Game engines
* Robotics
* Computer vision

---

# 4. What is Matrix Multiplication?

Suppose:

$$
A=
\begin{bmatrix}
1 & 2\\
3 & 4
\end{bmatrix}
$$

and:

$$
B=
\begin{bmatrix}
5 & 6\\
7 & 8
\end{bmatrix}
$$

Then:

$$
C=A\times B
$$

To calculate each element of `C`, we multiply corresponding elements and add them.

---

# 5. Calculate C[0][0]

Take the first row of A:

```text
1 2
```

and first column of B:

```text
5
7
```

Multiply:

$$
1\times5 + 2\times7
$$

$$
=5+14
$$

$$
=19
$$

Therefore:

```text
C[0][0] = 19
```

---

# 6. Calculate C[0][1]

First row of A:

```text
1 2
```

Second column of B:

```text
6
8
```

Therefore:

$$
1\times6+2\times8
$$

$$
=6+16
$$

$$
=22
$$

So:

```text
C[0][1] = 22
```

---

# 7. Calculate C[1][0]

Second row of A:

```text
3 4
```

First column of B:

```text
5
7
```

Therefore:

$$
3\times5+4\times7
$$

$$
=15+28
$$

$$
=43
$$

---

# 8. Calculate C[1][1]

Second row:

```text
3 4
```

Second column:

```text
6
8
```

Therefore:

$$
3\times6+4\times8
$$

$$
=18+32
$$

$$
=50
$$

So:

$$
C=
\begin{bmatrix}
19 & 22\\
43 & 50
\end{bmatrix}
$$

---

# 9. The Most Important Rule

For matrix multiplication:

If:

$$
A = m\times n
$$

and:

$$
B = n\times p
$$

then multiplication is possible because the **inner dimensions are equal**:

```text
(m × n) × (n × p)
```

The result is:

$$
C=m\times p
$$

For example:

```text
2 × 3
```

multiplied by:

```text
3 × 4
```

gives:

```text
2 × 4
```

Remember:

> **Columns of first matrix = Rows of second matrix.**

---

# 10. Simple Matrix Multiplication Algorithm

Suppose:

```text
A = m × n
B = n × p
C = m × p
```

The basic algorithm is:

```text
for i = 0 to m-1

    for j = 0 to p-1

        C[i][j] = 0

        for k = 0 to n-1

            C[i][j] =
                C[i][j] + A[i][k] * B[k][j]
```

This is the most important code pattern.

---

# 11. Simple C++ Code

Start with this version first.

```cpp
#include <iostream>
using namespace std;

int main()
{
    int A[2][2] = {
        {1, 2},
        {3, 4}
    };

    int B[2][2] = {
        {5, 6},
        {7, 8}
    };

    int C[2][2] = {0};

    // Matrix multiplication
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Result Matrix:\n";

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << C[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
```

Output:

```text
19 22
43 50
```

---

# 12. Understand the Three Loops

This is **very important for your jury**.

```cpp
for (int i = 0; i < 2; i++)
```

selects the:

> row of A / row of result

Then:

```cpp
for (int j = 0; j < 2; j++)
```

selects the:

> column of B / column of result

Then:

```cpp
for (int k = 0; k < 2; k++)
```

performs:

> multiplication and addition.

So remember:

```text
i → rows
j → columns
k → multiplication/summation
```

---

# 13. Why do we initialize C with 0?

We write:

```cpp
int C[2][2] = {0};
```

because we calculate:

$$
C[i][j] += A[i][k]\times B[k][j]
$$

For example:

$$
C[0][0]
=
1\times5
+
2\times7
$$

The first value must start from zero:

```text
0
+ 1×5
+ 2×7
= 19
```

---

# 14. Matrix Multiplication Complexity

Suppose all matrices are:

$$
n\times n
$$

We have three loops:

```text
i → n times
j → n times
k → n times
```

Therefore:

$$
n\times n\times n
$$

which gives:

$$
\boxed{O(n^3)}
$$

This is the most important complexity for standard matrix multiplication.

---

# 15. Why is O(n³) a Problem for AR?

Suppose:

```text
n = 10
```

Operations roughly grow as:

$$
10^3=1000
$$

Now:

```text
n = 100
```

$$
100^3=1,000,000
$$

Now:

```text
n = 1000
```

$$
1000^3=1,000,000,000
$$

That's a huge increase.

So as matrix size increases, computation can become expensive.

This is why the experiment mentions:

> **large matrices**

and:

> **low-power devices**

---

# 16. Matrix Transformations in AR

Now let's connect matrix multiplication to the AR application.

A point in 2D can be represented as:

$$
P=
\begin{bmatrix}
x\\
y
\end{bmatrix}
$$

A transformation matrix can transform that point.

For example, scaling.

---

# 17. Scaling

Suppose:

```text
x = 2
y = 3
```

and we want to double its size.

Scaling matrix:

$$
S=
\begin{bmatrix}
2 & 0\\
0 & 2
\end{bmatrix}
$$

Point:

$$
P=
\begin{bmatrix}
2\\
3
\end{bmatrix}
$$

Then:

$$
P'=SP
$$

So:

$$
P'=
\begin{bmatrix}
2&0\\
0&2
\end{bmatrix}
\begin{bmatrix}
2\\
3
\end{bmatrix}
$$

Result:

$$
P'=
\begin{bmatrix}
4\\
6
\end{bmatrix}
$$

The object has been scaled.

---

# 18. Rotation

A 2D rotation matrix is:

$$
R=
\begin{bmatrix}
\cos\theta & -\sin\theta\\
\sin\theta & \cos\theta
\end{bmatrix}
$$

This can rotate a point around the origin.

For example, when:

$$
\theta=90^\circ
$$

we have approximately:

$$
\cos90=0
$$

$$
\sin90=1
$$

so:

$$
R=
\begin{bmatrix}
0&-1\\
1&0
\end{bmatrix}
$$

---

# 19. Translation

Translation moves an object.

For example:

```text
x → x + tx
y → y + ty
```

To represent translation conveniently using matrix multiplication, we use **homogeneous coordinates**.

Instead of:

$$
\begin{bmatrix}
x\\
y
\end{bmatrix}
$$

we use:

$$
\begin{bmatrix}
x\\
y\\
1
\end{bmatrix}
$$

Translation matrix:

$$
T=
\begin{bmatrix}
1&0&t_x\\
0&1&t_y\\
0&0&1
\end{bmatrix}
$$

Then:

$$
P'=TP
$$

---

# 20. Why Homogeneous Coordinates?

This is a common viva question.

Translation cannot be represented as a normal 2×2 linear transformation.

So we add an extra coordinate:

```text
(x, y)
```

becomes:

```text
(x, y, 1)
```

This allows translation to be represented using matrix multiplication.

For 3D graphics, we similarly use:

```text
(x, y, z, 1)
```

and usually work with:

```text
4 × 4 transformation matrices
```

---

# 21. Combining Multiple Transformations

This is where matrix multiplication becomes very useful.

Suppose an AR object needs:

```text
Scaling
   ↓
Rotation
   ↓
Translation
```

Instead of applying three separate transformations to every point independently, we can combine the transformation matrices.

Suppose:

$$
S = \text{Scaling}
$$

$$
R = \text{Rotation}
$$

$$
T = \text{Translation}
$$

We can calculate a combined transformation:

$$
M=T\times R\times S
$$

Then apply:

$$
P'=M\times P
$$

This is a major optimization opportunity.

---

# 22. Why Combining Transformations Helps

Without combining:

```text
Point
 ↓
Scaling
 ↓
Rotation
 ↓
Translation
```

Every point may require multiple matrix-vector operations.

Instead, calculate:

```text
T × R × S
```

once.

Then:

```text
Combined Matrix
       ↓
Apply to many points
```

This is called **pre-computing or composing transformations**.

---

# 23. Important Point — Matrix Multiplication Is Not Commutative

This is a very important viva question.

Generally:

$$
A\times B \neq B\times A
$$

For transformations:

```text
Scale → Rotate
```

can produce a different result from:

```text
Rotate → Scale
```

Similarly:

```text
Translation → Rotation
```

is not generally the same as:

```text
Rotation → Translation
```

So we cannot randomly change the order.

---

# 24. Optimization Idea for Your Experiment

The problem says:

> "Examine how transformations are applied, identify opportunities for optimization in matrix operations, and propose an efficient technique that scales better on low-power devices."

A good solution is:

### Transformation composition + precomputation

Instead of repeatedly calculating:

$$
T\times R\times S\times P
$$

for every point, first calculate:

$$
M=T\times R\times S
$$

Then:

$$
P'=M\times P
$$

for each point.

This reduces repeated matrix-matrix calculations.

---

# 25. But What About Divide and Conquer?

Your project context mentions Divide and Conquer, and matrix multiplication can also be optimized using a Divide and Conquer approach.

The classical algorithm is called:

> **Divide and Conquer Matrix Multiplication**

And an important improved algorithm is:

> **Strassen's Matrix Multiplication**

Let's understand the basic Divide and Conquer version first.

---

# 26. Divide and Conquer Matrix Multiplication

Suppose:

$$
A
$$

and:

$$
B
$$

are large matrices.

We divide each matrix into four blocks.

For example:

$$
A=
\begin{bmatrix}
A_{11}&A_{12}\\
A_{21}&A_{22}
\end{bmatrix}
$$

and:

$$
B=
\begin{bmatrix}
B_{11}&B_{12}\\
B_{21}&B_{22}
\end{bmatrix}
$$

Then the result:

$$
C=A\times B
$$

is:

$$
C_{11}=A_{11}B_{11}+A_{12}B_{21}
$$

$$
C_{12}=A_{11}B_{12}+A_{12}B_{22}
$$

$$
C_{21}=A_{21}B_{11}+A_{22}B_{21}
$$

$$
C_{22}=A_{21}B_{12}+A_{22}B_{22}
$$

This is the Divide and Conquer idea.

---

# 27. How Does It Divide?

Imagine:

```text
        Large Matrix
             |
       ┌─────┴─────┐
       ↓           ↓
    smaller     smaller
    matrices    matrices
       ↓           ↓
     solve       solve
       \           /
        \         /
          combine
```

The matrices are divided into smaller blocks until we reach small matrices.

---

# 28. Does Basic Divide and Conquer Improve O(n³)?

Interestingly:

> **Basic Divide and Conquer matrix multiplication still has O(n³) complexity.**

It reorganizes the computation, but doesn't reduce the asymptotic number of multiplications enough.

To improve the asymptotic complexity, we need an algorithm such as:

# ⭐ Strassen's Algorithm

---

# 29. Strassen's Algorithm

Standard block multiplication requires **8 recursive matrix multiplications**.

Strassen reduced this to:

$$
7
$$

recursive matrix multiplications.

This gives a better theoretical complexity.

Standard:

$$
O(n^3)
$$

Strassen:

$$
O(n^{\log_2 7})
$$

Since:

$$
\log_2 7 \approx 2.807
$$

we get approximately:

$$
\boxed{O(n^{2.807})}
$$

---

# 30. Why Does Strassen Help?

Standard multiplication:

```text
8 recursive multiplications
```

Strassen:

```text
7 recursive multiplications
```

It uses additional matrix additions/subtractions to reduce the number of expensive multiplication operations.

This makes its asymptotic complexity better.

---

# 31. Important Caution for Your Jury

Don't say:

> "Strassen is always faster."

That's not necessarily true.

For relatively small matrices, ordinary multiplication can be faster because Strassen has:

* more additions
* more temporary storage
* more complicated implementation
* recursion overhead

So a practical system may use a **hybrid approach**:

```text
Large matrices
     ↓
Strassen / optimized method
     ↓
Small matrices
     ↓
Standard multiplication
```

---

# 32. What Optimization Should You Give in Your Experiment?

Your experiment is about:

> **Accelerating Image Transformations in Augmented Reality**

For the AR application, the most practical answer is:

### Optimization 1 — Precompute combined transformations

Instead of repeatedly multiplying transformation matrices for every point:

$$
M=T\times R\times S
$$

calculate `M` once.

Then apply:

$$
P'=MP
$$

to each point.

---

### Optimization 2 — Avoid unnecessary calculations

If an object hasn't changed:

> Don't recalculate its transformation matrix.

Cache the previously calculated matrix.

---

### Optimization 3 — Use efficient matrix multiplication

For large matrices:

* optimized multiplication
* block multiplication
* Strassen where appropriate
* hardware acceleration / GPU where available

can reduce computation.

---

# 33. Caching Example

Imagine the user hasn't changed:

```text
rotation
scaling
translation
```

Then the transformation matrix remains the same.

Instead of:

```text
Frame 1 → calculate
Frame 2 → calculate again
Frame 3 → calculate again
Frame 4 → calculate again
```

we can do:

```text
Calculate once
      ↓
Store matrix
      ↓
Reuse it
```

This is called:

> **Caching / precomputation**

---

# 34. Simple C++ Matrix Multiplication Function

For your practical, you should know a reusable function.

```cpp
void multiply(int A[][10], int B[][10],
              int C[][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
```

---

# 35. Complete Simple Program

```cpp
#include <iostream>
using namespace std;

void multiply(int A[][10], int B[][10],
              int C[][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void display(int matrix[][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    int n;

    cout << "Enter matrix size: ";
    cin >> n;

    int A[10][10];
    int B[10][10];
    int C[10][10];

    cout << "Enter Matrix A:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter Matrix B:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> B[i][j];
        }
    }

    multiply(A, B, C, n);

    cout << "Result Matrix:\n";

    display(C, n);

    return 0;
}
```

---

# 36. Code Structure

Understand this structure:

```text
main()
 |
 ├── input A
 |
 ├── input B
 |
 ├── multiply(A, B, C)
 |
 └── display(C)
```

The actual multiplication happens here:

```cpp
C[i][j] += A[i][k] * B[k][j];
```

**Memorize this line.**

---

# 37. Complexity of This Program

Three nested loops:

```cpp
for i
    for j
        for k
```

Each runs `n` times.

Therefore:

$$
\boxed{O(n^3)}
$$

Space:

We store:

```text
A → n²
B → n²
C → n²
```

So total auxiliary/storage requirement is:

$$
O(n^2)
$$

---

# 38. Matrix Multiplication — Jury Questions

Now let's prepare the likely viva questions.

---

## Q1. What is matrix multiplication?

> Matrix multiplication is an operation in which each element of the result is obtained by taking the dot product of a row from the first matrix and a column from the second matrix.

---

## Q2. What is the condition for matrix multiplication?

If:

$$
A=m\times n
$$

and:

$$
B=p\times q
$$

then multiplication is possible only when:

$$
\boxed{n=p}
$$

That is:

> Columns of A must equal rows of B.

---

## Q3. What is the complexity of standard matrix multiplication?

For two `n × n` matrices:

$$
\boxed{O(n^3)}
$$

---

## Q4. Why O(n³)?

Because we have three nested loops, each executing approximately `n` times.

$$
n\times n\times n=n^3
$$

---

## Q5. Why are matrices used in AR?

> Matrices provide an efficient mathematical representation of geometric transformations such as translation, rotation, scaling and projection.

---

## Q6. What is a transformation matrix?

> A transformation matrix is a matrix used to transform the coordinates of an object or point, such as changing its position, orientation or size.

---

## Q7. What is translation?

> Translation moves an object from one position to another.

---

## Q8. What is rotation?

> Rotation changes the orientation of an object around a specified point or axis.

---

## Q9. What is scaling?

> Scaling changes the size of an object.

---

## Q10. What are homogeneous coordinates?

> Homogeneous coordinates add an additional coordinate, such as representing a 2D point `(x,y)` as `(x,y,1)`, allowing transformations such as translation to be represented using matrix multiplication.

---

# 39. Very Important Jury Question

### "How can you optimize matrix transformations in AR?"

A strong answer:

> "We can precompute and compose multiple transformation matrices into a single combined matrix. For example, instead of separately applying scaling, rotation and translation repeatedly, we calculate M = T × R × S once and apply the combined matrix to the object points. We can also cache unchanged transformation matrices and use optimized or block-based matrix multiplication for large matrices. This reduces redundant computation and improves performance on low-power devices."

---

# 40. What is Strassen's Algorithm?

Answer:

> "Strassen's algorithm is a Divide and Conquer matrix multiplication algorithm that reduces the number of recursive matrix multiplications from eight to seven. Its time complexity is approximately O(n²·⁸⁰⁷), which is better than the O(n³) complexity of conventional matrix multiplication."

---

# 41. What is the difference between normal and Strassen multiplication?

| Feature                   | Standard           | Strassen            |
| ------------------------- | ------------------ | ------------------- |
| Approach                  | Three nested loops | Divide & Conquer    |
| Complexity                | O(n³)              | O(n²·⁸⁰⁷)           |
| Recursive                 | No                 | Yes                 |
| Multiplications per block | 8                  | 7                   |
| Implementation            | Simple             | Complex             |
| Extra memory              | Lower              | Higher              |
| Small matrices            | Often better       | Often unnecessary   |
| Large matrices            | Can be expensive   | Can be advantageous |

---

# 42. One Important Correction to Remember

If your professor asks:

> "Does Divide and Conquer automatically make matrix multiplication O(n²)?"

Answer:

> **No.**

Basic Divide and Conquer matrix multiplication still has:

$$
O(n^3)
$$

Strassen is the Divide and Conquer optimization that reduces the complexity to approximately:

$$
O(n^{2.807})
$$

This distinction can impress your jury.

---

# 43. How This Experiment Connects Together

The whole experiment can be explained as:

```text
              AR Object
                  ↓
             Object Points
                  ↓
       Transformation Matrices
                  ↓
       ┌──────────┼──────────┐
       ↓          ↓          ↓
    Scaling     Rotation  Translation
       └──────────┼──────────┘
                  ↓
       Combine transformations
                  ↓
             M = T × R × S
                  ↓
       Apply M to object points
                  ↓
          Faster transformation
```

For large matrix operations:

```text
Standard Matrix Multiplication
          ↓
       O(n³)
          ↓
Potential bottleneck
          ↓
Optimization
          ↓
Block / optimized multiplication
or Strassen where appropriate
```

---

# 44. What Should You Say to the Jury?

If they say:

> **"Explain Experiment 5."**

Give this answer:

> "The experiment focuses on accelerating image or object transformations in an augmented reality application. AR objects contain many coordinate points, and transformations such as translation, rotation and scaling are represented using matrices. Standard multiplication of two n × n matrices takes O(n³) time because of three nested loops. As the matrix and model sizes increase, this can cause performance problems on low-power devices. We can optimize the process by composing multiple transformation matrices into a single matrix, such as M = T × R × S, and precomputing and caching it when the transformation does not change. For large matrix multiplication, optimized block methods or Divide and Conquer techniques such as Strassen's algorithm can also be considered. Strassen reduces the theoretical complexity from O(n³) to approximately O(n²·⁸⁰⁷)."

That's a very good answer.

---

# 🧠 EXPERIMENT 5 CHEAT SHEET

### Matrix multiplication

$$
C[i][j]=\sum_k A[i][k]B[k][j]
$$

### Code:

```cpp
C[i][j] += A[i][k] * B[k][j];
```

### Complexity:

```text
Standard:
Time  = O(n³)
Space = O(n²)
```

### Transformations:

```text
Translation → Move
Rotation    → Rotate
Scaling     → Resize
```

### AR optimization:

```text
T × R × S
    ↓
Combined matrix M
    ↓
Reuse M
    ↓
Reduce redundant calculations
```

### Divide & Conquer:

```text
Large matrix
     ↓
Divide into blocks
     ↓
Solve smaller blocks
     ↓
Combine
```

### Strassen:

```text
Standard → 8 multiplications
Strassen → 7 multiplications

O(n³)
   ↓
O(n²·⁸⁰⁷)
```

---

# ⭐ Most Important Things for Tomorrow

If the jury gives you only 2 minutes, remember:

**1. Standard matrix multiplication**

$$
\boxed{O(n^3)}
$$

**2. Why?**

Three nested loops.

**3. AR uses matrices for**

> Translation, rotation, scaling and projection.

**4. Optimization**

> Combine transformations and precompute/cache the combined matrix.

**5. Divide and Conquer matrix multiplication**

> Divide matrices into smaller blocks, recursively multiply them and combine the results.

**6. Strassen**

> Reduces recursive multiplications from 8 to 7 and gives approximately O(n²·⁸⁰⁷).

---

## One very important distinction

Your **Experiment 5 is not simply asking you to implement Strassen's algorithm**. The actual problem is an **AR matrix-transformation optimization problem**. So if your jury asks *"What is your proposed solution?"*, don't jump directly to Strassen.

Your strongest practical answer is:

> **Precompute and combine transformation matrices, cache unchanged transformations, and use optimized matrix multiplication for large workloads.**

Strassen is an additional **Divide-and-Conquer optimization** you should know if they ask about the algorithmic side.

---

**Experiment 5 is complete.**

Next is **Experiment 6 — Fractional Knapsack using the Greedy Algorithm**. This is very important because you'll need to understand **what a Greedy algorithm is, why we calculate `profit/weight`, how to sort the items, why fractions are allowed, and then perform the complete calculation step-by-step with C++ code.**
