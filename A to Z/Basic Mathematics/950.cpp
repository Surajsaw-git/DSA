/*
You are given an integer n. You need to return the number of odd digits present in the number.

The number will have no leading zeroes, except when the number is 0 itself.

Example 1:
Input: n = 5

Output: 1

Explanation: 5 is an odd digit.

Example 2:
Input: n = 25

Output: 1

Explanation: The only odd digit in 25 is 5.
*/

#include<iostream>
using namespace std;
class Bm
{

public:
    void oddreturn(int n)
    {
        int count=0;
        if (n<0)
        {
            n = n*(-1);
            while (n>0)
            {
                int a=n%10;
                n = n-a;
                n = n/10;
                if (a%2!=0)
                {
                    count++;
                }
                

            };
        }
        else if (n==0)
        {
            count = 0;
        }
        else
        {
            while (n>0)
            {
                int a=n%10;
                n = n-a;
                n = n/10;
                if (a%2!=0)
                {
                    count++;
                }

            };
        }
        cout<<"number of digit :"<<count;
    }
};
int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    Bm m;
    m.oddreturn(n);

    return 0;
}