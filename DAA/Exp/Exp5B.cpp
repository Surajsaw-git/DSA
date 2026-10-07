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