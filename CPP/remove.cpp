#include<iostream>
using namespace std;
int main()
{
    int n;
    int value;
    cout<<"enter the numbers of elements: ";
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout<<"enter the element of "<<i<<" index: ";
        cin>>arr[i];
    }

    cout<<"Enter the value that you want to remove: ";
    cin>>value;
    int count=0;
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==value)
        {
            cout<<"index:"<<i<<endl;
            count++;
            arr[i]=NULL;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i];
    }
    
    
    
    
    
    return 0;
}