//Find the second largest element in an array without sorting.
#include <iostream>
#include <vector>
using namespace std;
int main(){
vector<int> arr{10,10,5,10,10};
int i;
for(i =0; i<arr.size();i++){
    cout<<arr[i]<<" ";
}
cout<<endl;


int temp =arr[0];
int second_max=arr[0];

for(int i =1; i<arr.size();i++)
{
    if( temp<arr[i]){
        second_max=temp;
        temp = arr[i];
    }
    // else if(second_max < arr[i] && arr[i] < temp)
    // {
    //     second_max = arr[i];

    // }
    else if (arr[i] > second_max && arr[i] < temp)
    {
        second_max = arr[i];

    }

    

}
cout<<temp<<endl;

cout<<second_max<<endl;


    return 0;
}