#include <iostream>
using namespace std;
void heapify(int a[], int n, int i);
void heapSort(int a[], int n);

// Driver code
int main()
{
    cout << "Enter the length of array" << endl;
    int n;
    cin >> n;
    int *a = new int(n);
    // Getting elements of array
    cout << "Enter the elements of array" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Original array:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    heapSort(a, n);
    cout << "\nSorted array:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    delete (a);
    return 0;
}

// To heapify a subtree rooted with node i which is an index in a[]
void heapify(int a[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    // If left child is larger than root
    if (l < n && a[l] > a[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && a[r] > a[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(a[i], a[largest]);
        // Recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }
}


void heapSort(int a[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(a[0], a[i]);
        // call max heapify on the reduced heap
        heapify(a, i, 0);
    }
}
