#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int arr[], int n, int key)
{
    int start = 0;
    int end = sqrt(n);          //the square root of array length
    while (arr[end] <= key && end < n)
    {
        start = end;            //if it is not correct block then shift block
        end += sqrt(n);
        if (end > n - 1)
            end = n;            //if right exceeds then bound the range
    }
    for (int pos = start; pos < end; pos++)
    { //perform linear search 
        if (arr[pos] == key)
            return pos;         //the correct position of the key
    }
    return -1;                  // if element is not found
}

int main()
{
    int n, key, loct;
    cout << "Enter the length of arr:\n";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of arr:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i]; // Taking input
    cout << "Enter search key: ";
    cin >> key;
    if ((loct = jumpSearch(arr, n, key)) != -1)             //Calling of jumpSearch function and getting a location back
        cout << "Element found at location: " << loct << endl;
    else
        cout << "Element does not exist in the array." << endl;
}