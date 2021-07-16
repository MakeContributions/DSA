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
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements: " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    WaveSort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

/*
// Alternate method by using the index as 0!!
// Lower to higher wave!!
#include <iostream>
#include <string>
using namespace std;


void swap(int arr[], int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void wavesort(int arr[], int n)
{
    for(int i=1;i<n;i+=2)
    {
        if(arr[i] < arr[i-1])
        {
            swap(arr,i,i-1);
        }
        if(arr[i] < arr[i+1] && i<=n-2)
        {
            swap(arr,i,i+1);
        }
    }
}


int main()
{
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements: " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    wavesort(arr,n);
    cout << "Sorted array: ";
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
*/