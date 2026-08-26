#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the "<<i<<" index value ";
        cin>>arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    // If k is greater than n
    while (k <= 0 || k >= n) {
    cout << "Invalid k. Enter again: ";
    cin >> k;
    }

    // First part size = n - k
    vector<int> firstPart(n - k);

    // Second part size = k
    vector<int> secondPart(k);

    // Store first part
    for (int i = 0; i < n - k; i++)
    {
        firstPart[i] = arr[i];
    }

    // Store second part
    for (int i = 0; i < k; i++)
    {
        secondPart[i] = arr[n - k + i];
    }

    // Merge second part first
    // Then first part
    vector<int> result(n);

    int index = 0;

    // Put second part
    for (int i = 0; i < k; i++)
    {
        result[index] = secondPart[i];
        index++;
    }

    // Put first part
    for (int i = 0; i < n - k; i++)
    {
        result[index] = firstPart[i];
        index++;
    }

    // Print rotated array
    cout << "Rotated array: ";

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}