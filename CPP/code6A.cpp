// Find the second largest element in an array without sorting.
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{50, 30, 50};

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int temp = arr[0];
    int second_max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (temp < arr[i])
        {
            second_max = temp;
            temp = arr[i];
        }

        else if (arr[i] > second_max && arr[i] < temp)
        {
            second_max = arr[i];
        }

        // If second_max is same as temp,
        // find a value smaller than temp
        else if (second_max == temp && arr[i] < temp)
        {
            second_max = arr[i];
        }
        
    }

    cout << "Max = " << temp << endl;
    cout << "Second Max = " << second_max << endl;

    return 0;
}