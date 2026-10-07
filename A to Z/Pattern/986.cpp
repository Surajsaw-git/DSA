/*
Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:

*****

****

***

**

*
*/

#include<iostream>
using namespace std;
class Pattern{
    public:
    void pattern(int n)
    {
        //int m=n;
        for (int i = 0; i < n; i++)
        {
            
            
            // for (int j = 0; j < m; j++)
            // {
            //     cout<<"*";
                
            // }
            
            for (int j = 0; j < n-i; j++)
            {
                cout<<"*";
                
            }
            cout<<endl;
            //m = m-1;
        }
        
    }
};
int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    Pattern p;
    p.pattern(n);
    return 0;
}