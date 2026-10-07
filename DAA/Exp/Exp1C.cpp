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