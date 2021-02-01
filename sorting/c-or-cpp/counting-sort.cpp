#include <iostream>
#include <algorithm>
using namespace std;

//function to find the max element from the array
int getMax(int a[], int size)
{
    int max = a[1];
    for (int i = 2; i <= size; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
void countSort(int *a, int size);

int main()
{
    cout << "Enter the length of array" << endl;
    int n;
    cin >> n;
    int *a = new int(n + 1);
    // Getting elements of array
    cout << "Enter the elements of array" << endl;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << "Original array: \n";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    countSort(a, n);
    cout << "\nSorted array: \n";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    delete (a);
    return 0;
}

void countSort(int *a, int size)
{
    int output[size + 1];
    int max = getMax(a, size);
    int count[max + 1]; //create count array (max+1 number of elements)
    for (int i = 0; i <= max; i++)
        count[i] = 0; //initialize count array to all zero
    for (int i = 1; i <= size; i++)
        count[a[i]]++; //increase number count in count array.
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1]; //find cumulative frequency
    for (int i = size; i >= 1; i--)
    {
        output[count[a[i]]] = a[i];
        count[a[i]] -= 1; //decrease count for same numbers
    }
    for (int i = 1; i <= size; i++)
        a[i] = output[i]; //store output array to main array
}