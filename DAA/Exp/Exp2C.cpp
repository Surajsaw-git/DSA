#include <iostream>
#include <string>
using namespace std;

int binarySearch(string books[], int n, string target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (books[mid] == target)
        {
            return mid;
        }
        else if (target > books[mid])
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
    string books[] =
    {
        "Algorithms",
        "Computer Networks",
        "Database Systems",
        "Operating Systems",
        "Python Programming"
    };

    int n = 5;
    string target;

    cout << "Enter book title: ";
    getline(cin, target);

    int result = binarySearch(books, n, target);

    if (result != -1)
        cout << "Book found at index " << result;
    else
        cout << "Book not found";

    return 0;
}