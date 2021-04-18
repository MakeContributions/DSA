#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void bucketSort(float a[], int n);

// Driver Code
int main()
{
	float a[] = {0.971, 0.565, 0.420, 0.123, 0.315, 0.696};
	int n = sizeof(a) / sizeof(a[0]);
	cout << "Original array:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	bucketSort(a, n);
	cout << "\nSorted array:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}

void bucketSort(float a[], int n)
{
	// Create n empty buckets
	vector<float> b[n];
	//Put array elements in different buckets
	for (int i = 0; i < n; i++)
	{
		int ib = n * a[i]; // Index in bucket
		b[ib].push_back(a[i]);
	}
	//Sort individual buckets
	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());
	//Concatenate all buckets into a[]
	int in = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			a[in++] = b[i][j];
}