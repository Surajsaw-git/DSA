// binary search

#include<iostream>
using namespace std;

int binarysearch(int arr[],int n,int target)
{
    int low=0;
    int high=n-1;
    

    while (low<=high)
    {
        int mid = low + (high-low)/2;
        if (arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]<target)
        {
            low = mid+1;
        }
        else
        {
            high=mid-1;
        }

    
    }
    return -1;
    
    
}
int main()
{
    int target;
    cout<<"Enter the value of target : ";
    cin>>target;
    int arr[] = {10,20,30,40,50,60,70,80,90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarysearch(arr,n,target);

    if (result!=-1)
    {
        cout<<"The index of target is :"<<result<<endl;
    }
    else
    {
        cout<<"Element not found"<<endl;
    }

    return 0;
    
}