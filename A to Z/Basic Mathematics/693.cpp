/*
693. GCD of Two Numbers
You are given two integers n1 and n2. You need find the Greatest Common Divisor (GCD) of the two given numbers. Return the GCD of the two numbers.

The Greatest Common Divisor (GCD) of two integers is the largest positive integer that divides both of the integers.

Example 1:
Input: n1 = 4, n2 = 6

Output: 2

Explanation: Divisors of n1 = 1, 2, 4, Divisors of n2 = 1, 2, 3, 6

Greatest Common divisor = 2.

Example 2:
Input: n1 = 9, n2 = 8

Output: 1

Explanation: Divisors of n1 = 1, 3, 9 Divisors of n2 = 1, 2, 4, 8.

Greatest Common divisor = 1.
*/
#include<iostream>
using namespace std;
class Cod
{
    public:
    void cod_count(int n1,int n2)
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
        
        
        
    }
};
int main()
{
    int n1,n2;
    cout<<"Enter the value of n1: ";
    cin>>n1;
    cout<<"Enter the value of n2: ";
    cin>>n2;

    Cod C;
    C.cod_count(n1,n2);
    return 0;

}