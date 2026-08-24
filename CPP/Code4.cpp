#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the value of "<<i<< " index :";
        cin>>arr[i];
    }

    int i =0;
    
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];

        }
        
    }
    int newLength = i + 1;
    
    cout<<"New length of the array is "<<newLength<<endl;

    cout<<"New array after removal of duplicate: ";

    for (int k = 0; k < newLength; k++)
    {
        cout<<arr[k]<<" ";
    }
    
    
    return 0;
}