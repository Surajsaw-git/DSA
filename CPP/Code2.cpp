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
    vector<int> arrReverse(m);

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the value "<<i<<" index value of array : ";
        cin>>arr[i];
    }

    for (int i = 0; i <m; i++)
    {
        arrReverse[i]=arr[n-1];
        n--;
    }
    cout<<"the reverse array is :";
    for (int i = 0; i < m; i++)
    {
        cout<<arrReverse[i];
    }
    
    
    return 0;
}

/*Using Two different array SC increase the SC is O(N), but we can solve this O(1) using two pointers.
To do this in-place (which means a space complexity of $O(1)$), you don't need a second array at all. Instead, you can use a concept called the Two-Pointer Technique.
*/
