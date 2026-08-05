#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    int a = 0;
    int b = 1;

    if (n >= 1)
        cout << a << " ";

    if (n >= 2)
        cout << b << " ";

    for (int i = 3; i <= n; i++)
    {
        int c = a + b;
        cout << c << " ";

        a = b;
        b = c;
    }

    return 0;
}