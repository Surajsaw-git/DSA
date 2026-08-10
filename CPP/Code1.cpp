#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i << " index value: ";
        cin >> arr[i];
    }

    int arrMax = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arrMax)
        {
            arrMax = arr[i];
        }
    }

    cout << "The max value of arr is " << arrMax << endl;

    return 0;
}