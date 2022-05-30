#include <iostream>
using namespace std;

void WaveSort(int arr[], int n)
{
    for(int i=1;i<n;i+=2)
    {
        if(arr[i] > arr[i+1]  && i<=n-2)
        {
            int temp=arr[i];
            arr[i+1]=arr[i];
            arr[i]=temp;
        }
        if(arr[i] > arr[i-1])
        {
            int temp=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=temp;

        }
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    cout << "The array before sorting: " << endl;
    for(int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    WaveSort(arr, 8);
    cout << "The array after sorting: " << endl;
    for(int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;

    //Expected time complexity : O(nlogn);
    //Expected space complexity: O(1);
}

