//sort array

#include<iostream>
using namespace std;
int PartitionAarry(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low -1;

    for(int j = low;j<high;j++)
    {
        if (arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);   
        }
        
    }
    swap(arr[i+1],arr[high]);
    return i +1;
}
void quicksort(int arr[],int low, int high)
{
    if (low<high)
    {
        int pivotindex = PartitionAarry(arr,low,high);
        quicksort(arr,low,pivotindex-1);
        quicksort(arr,pivotindex+1,high);
    }
    
}
int main()
{
    int n; // number of element in the array.
    cout<<"Enter the value of n:";
    cin>>n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the "<<i<<" index value : ";
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    cout<<"Display sorted array :";

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
    
    
}