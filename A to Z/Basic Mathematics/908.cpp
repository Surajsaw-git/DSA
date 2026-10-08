/*
You are given an integer n. Return the value of n! or n factorial.

Factorial of a number is the product of all positive integers less than or equal to that number.

Example 1:
Input: n = 2

Output: 2

Explanation: 2! = 1 * 2 = 2.

Example 2:
Input: n = 0

Output: 1

Explanation: 0! is defined as 1.
*/

#include<iostream>
using namespace std;
class Fact
{
    public:
    void factorial_val(int n)
    {
        if (n!=0)
        {
            int ft=1;
            for (int i = 1; i <= n; i++)
            {
                ft = ft*i;
            }
            cout<<ft;
        }
        else
        {
            cout<<1;
        }
        
    }
};
int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    Fact f;
    f.factorial_val(n);
    return 0;

}