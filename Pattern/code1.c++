#include<iostream>
using namespace std;
class Pattern
{
    public:
    void printPattern(int n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<"* ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Pattern p;
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    p.printPattern(n);
    return 0;
}