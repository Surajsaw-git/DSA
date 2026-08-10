//Reverse an array in place.

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter the value of n:";
    cin>>n;
    m=n;
    vector<int> arr(n);
    

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the value "<<i<<" index value of array : ";
        cin>>arr[i];
    }
    int right = n-1;
    int left = 0;
    while (left<right)
    {
        int temp;
        temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;
        left++;
        right--;
    }
    

    
    cout<<"the reverse array is :";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i];
    }
    
    
    return 0;
}