#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> data = {8, 7, 6, 1, 0, 9, 2};
    
    auto start = high_resolution_clock::now();
    
    quickSort(data, 0, data.size() - 1);
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    for (int num : data) {
        cout << num << " ";
    }
    
    cout << "\n" << duration.count() << " microseconds\n";
    
    return 0;
}