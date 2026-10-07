#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int partitionArray(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partitionArray(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    srand(time(0));

    cout << "Generated array:\n";

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}