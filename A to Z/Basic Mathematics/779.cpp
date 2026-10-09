/*
You are given an integer n. You need to check if the number is prime or not. Return true if it is a prime number, otherwise return false.

A prime number is a number which has no divisors except 1 and itself.

Example 1:
Input: n = 5

Output: true

Explanation: The only divisors of 5 are 1 and 5 , So the number 5 is prime.

Example 2:
Input: n = 8

Output: false

Explanation: The divisors of 8 are 1, 2, 4, 8, thus it is not a prime number.
*/
#include<iostream>
using namespace std;
class Prime_num
{
    public:
    void returnprime(int n)
    {
        //your code goes here
        if (n <= 1)
        {
            //return false;
            cout<<"Not Prime number";
        }

        int count = 0;

        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                count++;
            }
        }

        if (count == 2)
        {
            //return true;
            cout<<"Prime number";
        }
        else
        {
            //return false;
            cout<<"Not Prime number";
        }
        
        
    }
};
int main()

{
    int n;
    cout<<"enter the value of n: ";
    cin>>n;
    Prime_num P;
    P.returnprime(n);
    return 0;
}