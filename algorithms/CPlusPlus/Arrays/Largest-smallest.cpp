#include <iostream>
#include <algorithm>
using namespace std;

//simple approach:
//sort the array in ascending order.
//the first element would be the smallest and the last element would be the largest

int main()
{
    int a;
    int arr[20];
    cin>> a;
    for (i=0;i<a;i++){
        cin>>arr[i];
    }
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
    sort(arr,arr+n);//sorting the array
    //sort(a,a+n)-->a is the name of the array and n is the size of array a
    cout<<arr[0]<<" --> smallest number "<<endl;
    cout<<arr[n-1]<<" --> largest number "<<endl;

    return 0;
}