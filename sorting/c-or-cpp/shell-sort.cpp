#include <iostream> 
using namespace std; 
void shellSort(int a[], int n);

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
    shellSort(a,n);
    cout << "\nSorted array: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    delete (a);
    return 0;
} 

void shellSort(int a[], int n) 
{ 
	// Starting with a big gap, then reducing the gap 
	for (int gap = n/2; gap > 0; gap /= 2) 
	{ 
		// insertion sort for this gap size. 
		for (int i = gap; i < n; i += 1) 
		{ 
			// add a[i] to the elements that have been gap sorted 
			// save a[i] in temp and make a hole at position i 
			int temp = a[i]; 
            
			// shift earlier gap-sorted elements up until the correct 
			// location for a[i] is found 
			int j;			 
			for (j = i; j >= gap && a[j - gap] > temp; j -= gap) 
				a[j] = a[j - gap]; 
			
			// put temp (the original a[i]) in its correct location 
			a[j] = temp; 
		} 
	} 
} 



