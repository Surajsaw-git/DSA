#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target)
{
    // Base case: element not found
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    // Element found
    if (arr[mid] == target)
    {
        return mid;
    }

    // Search left half
    if (target < arr[mid])
    {
        return binarySearch(arr, low, mid - 1, target);
    }

    // Search right half
    return binarySearch(arr, mid + 1, high, target);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    int n = 9;
    int target;

    cout << "Enter element to search: ";
    cin >> target;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}