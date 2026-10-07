#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

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

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }

    auto start = high_resolution_clock::now();

    quickSort(arr, 0, n - 1);

    auto end = high_resolution_clock::now();

    auto duration =
        duration_cast<microseconds>(end - start);

    cout << "Time taken: "
         << duration.count()
         << " microseconds\n";

    return 0;
}