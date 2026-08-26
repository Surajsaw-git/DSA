// 5. Rotate an array to the right by k steps.

#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int n;
    int k;

    cout<<"Enter the number of elements :";
    cin>>n;

    cout<<"Enter the value of k :";
    cin>>k;

    while (k <= 0 || k >= n - 1) {
    cout << "Invalid k. Enter again: ";
    cin >> k;
    }
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the "<<i<<" index value ";
        cin>>arr[i];
    }

    int left = 0;
    int right=n-1;
    
    while (left < right)
    {
        int temp;
        temp = arr[left];
        arr[left] = arr[right];
        arr[right]= temp;
        left++;
        right--;
    }
    cout<<"1st step : ";

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }

    left = 0;
    right = k-1;
    while (left < right)
    {
        int temp;
        temp = arr[left];
        arr[left] = arr[right];
        arr[right]= temp;
        left++;
        right--;
    }
    cout<<endl;
    cout<<"2nd step : ";

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    
    left = k;
    right = n-1;
    while (left < right)
    {
        int temp;
        temp = arr[left];
        arr[left] = arr[right];
        arr[right]= temp;
        left++;
        right--;
    }
    cout<<endl;
    cout<<"Final step : ";

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    return 0;
}