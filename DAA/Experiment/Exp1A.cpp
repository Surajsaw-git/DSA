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