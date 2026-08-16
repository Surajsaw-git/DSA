#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter the " << i << " index value: ";
        cin >> arr[i];
    }

    int j = 0;  // position for next non-zero element

    for (int i = 0; i < n; i++) {

        if (arr[i] != 0) {
            arr[j] = arr[i];
            j++;
        }
    }

    // Put zeroes in remaining positions
    while (j < n) {
        arr[j] = 0;
        j++;
    }

    cout << "\nArray after moving zeroes: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}