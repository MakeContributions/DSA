/*
Maximum Sum Rectangle
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input Format:
First line of input will contain T(number of test case), each test case follows as.
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output Format:
Output a single integer, maximum sum rectangle for each test case in a newline.
Constraints
1<=n,m<=100
-10^5 <= mat[i][j] <= 10^5

Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
Approach:
1) Calculate pre sum for every row of the matrix
   The above matrix will look like:
   1 3 2 -2 -22
   -8 -11 -7 -5 -4
   3 11 21 22 25
   -4 -5 -4 3 -3
2) Same approach as kadane algorithms take any two columns of the matrix and calculate maximum subarray sum in the row array.
for example between column 0 and 1, the row array will be,
   [4, -19, 14, -9]
   find max subarray sum.
3) Do it for every pair of column and find the maximum of all. And that will be the final answer.

Time Complexity: O(n*m*m)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>>mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (j > 0) {
                mat[i][j] += mat[i][j - 1];
            }
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            //array explained in point (2).
            vector<int>v(n, 0);
            v[0] = mat[0][j] - (i > 0 ? mat[0][i - 1] : 0);
            for (int k = 1; k < n; k++) {
                v[k] = mat[k][j] - (i > 0 ? mat[k][i - 1] : 0);
            }
            int cur = 0, mx = INT_MIN;
            for (auto p : v) {
                cur += p;
                if (cur > mx) {
                    mx = cur;
                }
                if (cur < 0) {
                    cur = 0;
                }
            }
            ans = max(ans, mx);
        }
    }
    cout << ans << endl;

}
