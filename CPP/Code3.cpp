#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> arr(n);

    // Take array input
    for (int i = 0; i < n; i++) {
        cout << "Enter the " << i << " index value: ";
        cin >> arr[i];
    }

    // End represents the last position
    // where we can move a zero
    int end = n - 1;

    for (int i = 0; i < end; i++) {

        if (arr[i] == 0) {

            // Store zero
            int temp = arr[i];

            // Shift all elements to the left
            for (int j = i; j < end; j++) {
                arr[j] = arr[j + 1];
            }

            // Put zero at the end
            arr[end] = temp;

            // This position is now fixed
            end--;

            // Check the same index again
            i--;
        }
    }

    // Print final array
    cout << "\nArray after moving zeroes: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}