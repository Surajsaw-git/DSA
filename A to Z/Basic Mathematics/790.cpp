/*
790. Count of Prime Numbers till N
You are given an integer n. You need to find out the number of prime numbers in the range [1, n] (inclusive). Return the number of prime numbers in the range.

A prime number is a number which has no divisors except, 1 and itself.

Example 1:
Input: n = 6

Output: 3

Explanation: Prime numbers in the range [1, 6] are 2, 3, 5.

Example 2:
Input: n = 10

Output: 4

Explanation: Prime numbers in the range [1, 10] are 2, 3, 5, 7.
*/
#include<iostream>
using namespace std;
class Prime_num
{
    public:
    void returnprime(int n)
    {
        if (n <= 1)
        {
            cout<<0;
        }

        
        int primecount = 0;

        for (int j = 1; j <= n; j++)
        {
            int count = 0;
            for (int i = 1; i <= j; i++)
            {
                if (j % i == 0)
                {
                    count++;
                }
            }

            if (count == 2)
            {
                primecount++;
            }
        }
        cout<<primecount;
        
        
        
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