//Simple Title Search Example
#include<iostream>
#include<string>
using namespace std;
int BinarySearch(string Book[],int n , string target)
{
    int low =0;
    int high = n-1;

    while (low<=high)
    {
        int mid = low + (high-low)/2;

        if (Book[mid]==target)
        {
            return mid;
        }
        else if(Book[mid]<target)
        {
            low=mid+1;
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
    string Book[] = {
        "DAA",
        "DSA",
        "DataBase System",
        "English",
        "Math",
        "Operating System"
    };


    string target;
    cout<<"Enter the target or you want search book: ";
    getline(cin,target);

    int n = 6;
    int result = BinarySearch(Book,n,target);

    if (result!=-1)
    {
        cout<<"Book Found :"<<Book[result]<<endl;
    }
    else
    {
        cout<<"Book not found."<<endl;
    }
    return 0;
}
