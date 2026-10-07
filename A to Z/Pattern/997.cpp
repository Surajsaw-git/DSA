/*

997. Pattern 7
Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:

    *
   ***
  *****
 *******
*********
Print the pattern in the function given to you.
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
            // Spaces
            for (int k = 0; k < n - i - 1; k++)
            {
                cout << " ";
            }

            // Stars
            for (int j = 0; j < (2 * i) + 1; j++)
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

    Pattern p;
    p.pattern(n);

    return 0;
}
