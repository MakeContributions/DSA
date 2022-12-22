#include <iostream>
#include <algorithm>
using namespace std;

//simple approach:
//sort the array in ascending order.
//the first element would be the smallest and the last element would be the largest

int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
    sort(arr,arr+n);//sorting the array
    //sort(a,a+n)-->a is the name of the array and n is the size of array a
    cout<<arr[0]<<" --> smallest number "<<endl;
    cout<<arr[n-1]<<" --> largest number "<<endl;

    return 0;
}