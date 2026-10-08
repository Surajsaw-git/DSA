/*
You are given an integer n. You need to return the number of digits in the number.

The number will have no leading zeroes, except when the number is 0 itself.

Example 1:
Input: n = 4

Output: 1

Explanation: There is only 1 digit in 4.

Example 2:
Input: n = 14

Output: 2

Explanation: There are 2 digits in 14.

Example 3:
Input: n = 234

Output:
3
*/
#include<iostream>
using namespace std;
class Bm
{
    public:
    void returndigit(int n)
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
                count++;

            };
        }
        else if (n==0)
        {
            count = 1;
        }
        else
        {
            while (n>0)
            {
                int a=n%10;
                n = n-a;
                n = n/10;
                count++;

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
    m.returndigit(n);

    return 0;
}