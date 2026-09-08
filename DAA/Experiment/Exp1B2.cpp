#include<iostream>
using namespace std;
int fibonacci(int n)
{
    if(n==0)
        return 0;
    int a =0;
    int b =1;
    int c;
    for (int i = 2; i <=n; i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return b;
    
}
int main()
{
    int n;
    cout<<"Enter the number n: ";
    cin>>n;
    cout<<"The fibonacci number is :"<<fibonacci(n)<<endl;
    cout<<"The Fibonacci Sequence is :";
    for (int i = 0; i <= n; i++)
    {
        cout<<fibonacci(i)<<" ";
    }
    
    return 0;
}