#include <iostream>
using namespace std;
int partition(int a[],int low,int high);
void quickSort(int a[], int low, int high);

// Driver Code
int main()
{
    cout<<"Enter the length of array"<<endl;
	int n;
	cin>>n;
	int *a = new int(n);
	// Getting elements of array
	cout<<"Enter the elements of array"<<endl;
	for (int i = 0; i < n; i++)
		cin>>a[i];
    cout << "Original array: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    quickSort(a, 0, n - 1);
    cout << "\nSorted array: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    delete (a);
    return 0;
}

// A utility function to swap two elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
aay, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition(int a[], int low, int high)
{
    int pivot = a[high]; 
    int i = (low - 1);   

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (a[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

/* The main function that implements QuickSort 
a[] --> array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, a[p] is now 
		at right place */
        int pi = partition(a, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

