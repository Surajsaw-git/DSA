// Binary search itrative 
#include<iostream>
using namespace std;
int BinarySearch(int arr[],int low, int high, int target)
{
    if (high<low)
    {
        return -1;
    }

    int mid = low + (high - low)/2;

    if (arr[mid]==target)
    {
        return mid;
    }
    

    if (arr[mid]>target)
    {
        return BinarySearch(arr ,low,mid-1,target);
    }
    else
    {
        return BinarySearch(arr,mid+1,high,target);
    }
    
}
int main()
{
    int arr[]={10,20,30,40,50,60,70,80,90};
    int n=sizeof(arr)/sizeof(arr[0]);

    int target;
    cout<<"Enter the value you want to search: ";
    cin>>target;

    int result = BinarySearch(arr, 0,n-1,target);

    if (result!=-1)
    {
        cout<<"Element found at index :"<<result<<endl;
    }
    else
    {
        cout<<"Element not found"<<endl;
    }

    return 0;
}