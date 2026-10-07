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