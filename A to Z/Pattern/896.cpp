/*
Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:

*****

*****

*****

*****

*****

Print the pattern in the function given to you.

Example 1:
Input: n = 4
*/
#include <iostream>
using namespace std;

class Pattern
{
public:
    void pattern(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    Pattern P;
    P.pattern(n);

    return 0;
}
