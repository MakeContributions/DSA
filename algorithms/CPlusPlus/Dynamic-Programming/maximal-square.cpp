// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// Example 1:

// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 4
// Example 2:

// Input: matrix = [["0","1"],["1","0"]]
// Output: 1
// Example 3:

// Input: matrix = [["0"]]
// Output: 0

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 300
// matrix[i][j] is '0' or '1'.
// -------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<char>> matrix;

    int m, n;
    cout << "Enter the matrix Dimensions:-  ";
    cin >> m >> n;
    cout << "Enter the matrix elements:-  ";

    for (int i = 0; i < m; i++)
    {
        vector<char> v;
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            v.push_back(c);
        }
        matrix.push_back(v);
    }

    if (matrix.size() == 0)                    // if matrix is empty
        cout << "Area of largest Square is 0"; // return 0

    else
    {
        int maxx = 0;
        vector<vector<int>> v(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

        for (int i = 1; i <= matrix.size(); ++i)
        {
            for (int j = 1; j <= matrix[0].size(); ++j)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    v[i][j] = min({v[i - 1][j - 1], v[i - 1][j], v[i][j - 1]}) + 1;
                    maxx = max(maxx, v[i][j]);
                }
            }
        }
        cout << "Area of largest Square is-- " << maxx * maxx;
    }

    return 0;
}

// CONTRIBUTED BY ADWAITA RAJ MODAK