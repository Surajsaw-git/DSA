/*
You are given an integer n. You need to check if the number is a perfect number or not. Return true if it is a perfect number, otherwise, return false.

A perfect number is a number whose proper divisors (excluding the number itself) add up to the number itself.

Example 1:
Input: n = 6

Output: true

Explanation: Proper divisors of 6 are 1, 2, 3.

1 + 2 + 3 = 6.

Example 2:
Input: n = 4

Output: false

Explanation: Proper divisors of 4 are 1, 2.

1 + 2 = 3.
*/
#include<iostream>
using namespace std;
class Proper_num
{
    public:

    void perfectnumber(int n)
    {
        int b=0;
        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
            {
                b = b + i;
            }

        }
        if (n==b)
        {
            cout<<"it is a perfect number"<<endl;
        }
        else
        {
            cout<<"It is not a perfect number"<<endl;
        }
        
        
        
    }
};
int main()

{
    int n;
    cout<<"enter the value of n: ";
    cin>>n;
    Proper_num P;
    P.perfectnumber(n);
    return 0;
}