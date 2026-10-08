/*
937. Check if the Number is Armstrong
You are given an integer n. You need to check whether it is an armstrong number or not. Return true if it is an armstrong number, otherwise return false.

An armstrong number is a number which is equal to the sum of the digits of the number, raised to the power of the number of digits.

Example 1:
Input: n = 153

Output: true

Explanation: Number of digits : 3.

13 + 53 + 33 = 1 + 125 + 27 = 153.

Therefore, it is an Armstrong number.

Example 2:
Input: n = 12

Output: false

Explanation: Number of digits : 2.

12 + 22 = 1 + 4 = 5.

Therefore, it is not an Armstrong number.
*/

#include<iostream>
using namespace std;
class Armstrong
{
    public:
    void armreturn(int n)
    {
        int a;
        int b=0;
        while (n>0)
        {
            a = n%10;
            b += a * a * a;
            n=n/10;
            
        }
        if (n==b)
        {
            //return true;
            cout<<"it is Armstrong"<<endl;
        }
        else
        {
            //return fasle;
            cout<<"it is not Armstrong"<<endl;
        }
        
        
        
    }
};
int main()

{
    int n;
    cout<<"enter the value of n: ";
    cin>>n;
    Armstrong Arm;
    Arm.armreturn(n);
    return 0;
}