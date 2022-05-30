// Given two strings 's1' and 's2' and below operations that can performed on 's1'.
// 1.Insert
// 2.Remove
// 3.Replace
//Find minimum number of edits (operations) required to convert ‘s1’ into ‘s2’.  

// NOTE: All above operations are of equal cost
// Input:   s1 = "car", s2 = "cars"
// Output:  1
// We can convert s1 into s2 by inserting a 's'.

//Program using Dynamic Programming
//TIME COMPLEXITY: O(m*n) 

#include <iostream>
#include <vector>
using namespace std;
 
// Utility function to find the minimum of three numbers
int min(int x, int y, int z) { return min(min(x, y), z); }
 
int editDistDP(string s1, string s2, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
 
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i == 0)
                dp[i][j] = j; // Min. operations = j
 
            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i
 
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
 
            // If the last character is different, consider
            // all possibilities and find the minimum
            else
                dp[i][j]
                    = 1
                      + min(dp[i][j - 1], // Insert
                            dp[i - 1][j], // Remove
                            dp[i - 1][j - 1]); // Replace
        }
    }
 
    return dp[m][n];
}
 
int main()
{
    string s1, s2;
    cout << "Enter 1st string: " << '\n'; 
    cin >> s1;
    cout << "Enter 2nd string: " << '\n';
    cin >> s2;
    int n = s1.length();
    int m = s2.length();
    cout << editDistDP(s1, s2, n, m);
    return 0;
}

// s1: food
// s2: money
// output: 4
