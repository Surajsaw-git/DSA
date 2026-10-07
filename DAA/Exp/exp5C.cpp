#include <iostream>
using namespace std;

void multiply(int A[][10], int B[][10], int C[][10], int n)
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
    int n = 2;

    int A[10][10] = {
        {1, 2},
        {3, 4}
    };

    int B[10][10] = {
        {5, 6},
        {7, 8}
    };

    int C[10][10];

    multiply(A, B, C, n);

    cout << "Matrix A:" << endl;
    display(A, n);

    cout << "\nMatrix B:" << endl;
    display(B, n);

    cout << "\nResult Matrix:" << endl;
    display(C, n);

    return 0;
}