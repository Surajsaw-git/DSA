#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    int n = 9;
    int target;

    cout << "Enter element to search: ";
    cin >> target;

    int result = binarySearch(arr, n, target);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}