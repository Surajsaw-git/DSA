#include<bits/stdc++.h>
using namespace std;

void print()
{
    int count=0;
    if(count==5)
    {
        return;
    }
    cout<<count<<endl;
    count++;
    print();
}
int main()
{

    print();
    return 0;
}