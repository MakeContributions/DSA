#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int temp,j;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {   // Moving the elements of array that are greater than temp, to one position ahead of their current position
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    int n;
    cout << "Enter the length of array:\n";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];     // Taking input
    insertionSort(arr, n); //Calling of insertionSort function
    cout << "Sorted array elements:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " "; //Printing out elements
    return 0;
}
