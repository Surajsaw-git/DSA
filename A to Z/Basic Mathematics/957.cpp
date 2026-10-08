/*
957. Return the Largest Digit in a Number
You are given an integer n. Return the largest digit present in the number.

Example 1:
Input: n = 25

Output: 5

Explanation: The largest digit in 25 is 5.

Example 2:
Input: n = 99

Output: 9

Explanation: The largest digit in 99 is 9.
*/

#include<iostream>
using namespace std;
class Maxvalue
{
    public:
    void returnMax(int n)
    {
        int maxV=0;
        if (n>0)
        {
            while (n>0)
            {
                
                int a = n%10;
                n = n-a;
                n = n/10;
                if (maxV<=a)
                {
                    maxV=a;
                }
                
                
            }
        }
        else if (n<0)
        {
            n=n*(-1);
            while (n>0)
            {
                int a = n%10;
                n = n-a;
                n = n/10;
                if (maxV<=a)
                {
                    maxV=a;
                }
            }
        }
        else
        {
            cout<<0;
        }

        cout<<"Max value is :"<<maxV<<endl;
        
        
        
    }

    
};
int main()
{
    int n;
    cout<<"enter the value of n: ";
    cin>>n;
    Maxvalue m;
    m.returnMax(n);
    return 0;
}

