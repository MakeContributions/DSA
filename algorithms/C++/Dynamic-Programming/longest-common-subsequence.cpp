/*
Printing longest common subseqeunce from 2 subsequences using dp bottom-up approach
*/

#include<bits/stdc++.h>

using namespace std;

void longestCommonSubsequence(vector < int > a, vector < int > b) {
  int n = a.size();
  int m = b.size();
  int i, j;
  vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0)); //creating lookup table to keep track of subsequnces 
  vector < int > result; //result vector
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) //iterating through all subsequences, if common then increment value of dp[i][j] else consider max from previous
    {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }
  i = n, j = m;

  while (i > 0 && j > 0) { //traversing dp vector and finding the same elements in both to print result
    if (a[i - 1] == b[j - 1]) {
      result.push_back(a[i - 1]);
      i--;
      j--;
    } else if (dp[i][j - 1] > dp[i - 1][j]) {
      j--;
    } else
      i--;

  }

  cout << "Length of lcs " << result.size() << '\n';
  reverse(result.begin(), result.end()); //reversing to get correct order
  cout << "\nLongest common subsequence ";
  for (auto it: result) {
    cout << it;
  }
  cout << "\n";
}

int main() {

  int n, m;
  cout << "\nEnter no of elements in first sequence"; //Input and output
  cin >> n;
  cout << "\nEnter no of elements in second sequence";
  cin >> m;
  vector < int > a(n);
  vector < int > b(m);
  cout << "\nEnter elements in first sequence\n";
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << "\nEnter elements in second sequence\n";
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  longestCommonSubsequence(a, b);

  return 0;
}

/*
Time and space complexity for subsequence-O(m*n)

SAMPLE INPUT-
Enter no of elements in first sequence5

Enter no of elements in second sequence3

Enter elements in first sequence
1 2 3 4 5

Enter elements in second sequence
1 3 4
Length of lcs 3

Longest common subsequence 134

*/