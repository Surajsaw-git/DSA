/*
886. Sum of Array Elements
Given an array arr of size n, the task is to find the sum of all the elements in the array.

Example 1:
Input: n=5, arr = [1,2,3,4,5]

Output: 15

Explanation: Sum of all the elements is 1+2+3+4+5 = 15

Example 2:
Input: n=6, arr = [1,2,1,1,5,1]

Output: 11

Explanation: Sum of all the elements is 1+2+1+1+5+1 = 11
*/
#include <iostream>
#include <vector>
using namespace std;

class ArraySum
{
public:
    void returnsumofarray(vector<int>& arr, int n)
    {
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
        }

        cout << "Sum of array: " << sum;
    }
};

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value at index " << i << ": ";
        cin >> arr[i];
    }

    ArraySum A;
    A.returnsumofarray(arr, n);

    return 0;
}