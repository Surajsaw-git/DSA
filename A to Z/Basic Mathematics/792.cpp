/*
792. LCM of two numbers
You are given two integers n1 and n2. You need find the Lowest Common Multiple (LCM) of the two given numbers. Return the LCM of the two numbers.

The Lowest Common Multiple (LCM) of two integers is the lowest positive integer that is divisible by both the integers.

Example 1:
Input: n1 = 4, n2 = 6

Output: 12

Explanation: 4 * 3 = 12, 6 * 2 = 12.

12 is the lowest integer that is divisible both 4 and 6.

Example 2:
Input: n1 = 3, n2 = 5

Output: 15

Explanation: 3 * 5 = 15, 5 * 3 = 15.

15 is the lowest integer that is divisible both 3 and 5.
*/
#include<iostream>
using namespace std;
class LCM
{
    public:
    void returnlcm(int n1,int n2)
    {
        int small;
        if (n1>n2)
        {
            small = n2;
        }
        else if (n1==n2)
        {
            small=n1;
        }
        else
        {
            small = n1;
        }
        int max_divisor=1;
        for (int i = 1; i <=small; i++)
        {
            if (n1%i==0 && n2%i==0)
            {
                max_divisor=i;
            }
            
        }
        cout<<"Max divisor: "<<max_divisor<<endl;
        int lcm = (n1*n2)/max_divisor;
        cout<<"LCM: "<<lcm<<endl;
    }
};
int main()
{
    int n1,n2;
    cout<<"Enter the value of n1: ";
    cin>>n1;
    cout<<"Enter the value of n2: ";
    cin>>n2;

    LCM L;
    L.returnlcm(n1,n2);
    return 0;

}