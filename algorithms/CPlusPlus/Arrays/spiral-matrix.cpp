// Write C++ code to print a matrix in spiral order
// Input:  1    2   3   4
//         5    6   7   8
//         9   10  11  12
//         13  14  15  16

// Output: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

// Algorithm: 
/*
1. Create four variables to store the starting row index, ending row index, starting column index and ending column index.
2. Traverse the matrix from the starting row index to the ending row index and from the starting column index to the ending column index.
3. Increment the starting row index.
4. Decrement the ending column index.
5. Decrement the ending row index.
6. Increment the starting column index.
7. Repeat steps 2 to 6 until the starting row index is less than or equal to the ending row index and the starting column index is less than or equal to the ending column index.
*/

#include <iostream>
using namespace std;

void printSpiral(int a[][4], int m, int n)
{
    int i, k = 0, l = 0;

    while (k < m && l < n)
    {
        for (i = l; i < n; ++i)
        {
            cout << a[k][i] << " ";
        }
        k++;

        for (i = k; i < m; ++i)
        {
            cout << a[i][n - 1] << " ";
        }
        n--;

        if (k < m)
        {
            for (i = n - 1; i >= l; --i)
            {
                cout << a[m - 1][i] << " ";
            }
            m--;
        }

        if (l < n)
        {
            for (i = m - 1; i >= k; --i)
            {
                cout << a[i][l] << " ";
            }
            l++;
        }
    }
}

int main()
{
    int a[4][4] = { { 1, 2, 3, 4 },
                    { 5, 6, 7, 8 },
                    { 9, 10, 11, 12 },
                    { 13, 14, 15, 16 } };

    printSpiral(a, 4, 4);
    return 0;
}
