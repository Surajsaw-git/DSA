/*
101. Reverse a number

Core
You are given an integer n. Return the integer formed by placing the digits of n in reverse order.

Example 1:
Input: n = 25

Output: 52

Explanation: Reverse of 25 is 52.

Example 2:
Input: n = 123

Output: 321

Explanation: Reverse of 123 is 321.
*/

#include<iostream>
using namespace std;
class reverse
{
    public:
    void returnreverse(int n)
    {
        int b=0;
        if (n>0)
        {
            while (n>0)
            {
                b=b*10;
                int a = n%10;
                n = n-a;
                n = n/10;
                b=b+a;
            }
            cout<<b;
        }
        else if (n<0)
        {
            n=n*(-1);
            while (n>0)
            {
                b=b*10;
                int a = n%10;
                n = n-a;
                n = n/10;
                b=b+a;
            }
            b=b*(-1);
            cout<<b;
        }
        else
        {
            cout<<0;
        }
        
        
        
    }

    
};
int main()
{
    int n;
    cout<<"enter the value of n: ";
    cin>>n;
    reverse r;
    r.returnreverse(n);
    return 0;
}

