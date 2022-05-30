#include <bits/stdc++.h>
using namespace std;
int nextGap(int gap);
void combSort(int a[], int n);

// Driver program
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
    cout << "Original array: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    combSort(a, n);
    cout << "\nSorted array: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    delete (a);
    return 0;
}

int nextGap(int gap)
{
    // Shrink gap by Shrink factor
    gap = (gap * 10) / 13;
    if (gap < 1)
        return 1;
    return gap;
}

void combSort(int a[], int n)
{
    // Initialize gap
    int gap = n;

    // Initialize swapped as true to make sure that
    // loop runs
    bool isSwapped = true;

    // Keep running while gap is more than 1 and last
    // iteration caused a swap
    while (gap != 1 || isSwapped == true)
    {
        // Find next gap
        gap = nextGap(gap);

        // Initialize swapped as false so that we can
        // check if swap happened or not
        isSwapped = false;

        // Compare all elements with current gap
        for (int i = 0; i < n - gap; i++)
        {
            if (a[i] > a[i + gap])
            {
                swap(a[i], a[i + gap]);
                isSwapped = true;
            }
        }
    }
}
