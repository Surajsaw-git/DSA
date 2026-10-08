/*
211. Palindrome Number
You are given an integer n. You need to check whether the number is a palindrome number or not. Return true if it's a palindrome number, otherwise return false.

A palindrome number is a number which reads the same both left to right and right to left.

Example 1:
Input: n = 121

Output: true

Explanation: When read from left to right : 121.

When read from right to left : 121.

Example 2:
Input: n = 123

Output: false

Explanation: When read from left to right : 123.

When read from right to left : 321.
*/
#include<iostream>
using namespace std;
class palindrome
{
    public:
    void returnpalindrome(int n)
    {
        int b=0;
        int c=n;
        if (n>0)
        {
            while (n>0)
            {
                b=b*10;
                int a = n%10;
                n = n/10;
                b=b+a;
            }
            if(b==c)
            {
                cout<<"it is palindrome";
            }
            else
            {
                cout<<"it is not a palindrome";
            }
        }
        else if (n<0)
        {
            n = n*(-1);
            while (n>0)
            {
                b=b*10;
                int a = n%10;
                n = n/10;
                b=b+a;
            }
            b=b*(-1);
            
            if(b==c)
            {
                cout<<"it is palindrome";
            }
            else
            {
                cout<<"it is not a palindrome";
            }
        }
        else
        {
            cout<<"it is not a palindrome";
        }
        
        
        
        
        
    }

    
};
int main()
{
    int n;
    cout<<"enter the value of n: ";
    cin>>n;
    palindrome r;
    r.returnpalindrome(n);
    return 0;
}

