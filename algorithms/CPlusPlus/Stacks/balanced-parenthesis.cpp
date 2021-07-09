/*
Program to check whether the Parenthesis are balanced or not
*/
#include<bits/stdc++.h>

using namespace std;
bool isBalanced(string s) {
  stack < char > st;
  char data;
  int i;
  /*
      Logic
      1. Create a stack of char data type,i of int type and data of char type
      2. Run a loop till i is less than size
      3. Assign x[i]th index value in data
      4. If stack is not empty as well st.top()+2 ==(int) data (we will assume that st.top '[' or '}' so by adding two in it should
         be ']' pr '}' ) or st.top+1 (we will assume that st.top be '(' so +1 would be ')')
      5. If the 4 step didn't run then push data in it
      6. Run the step 4 and 5 till the i is less than x size
      7. If stack is empty that means the expression is balanced so return 1
      8. If the 7 step didn't run then return 0 means the expression is not balanced
      */
  for (i = 0; i < s.size(); i++) {
    data = s[i];
    if ((st.empty() != 1) && ((int)(st.top() + 2) == (int) data || (int)(st.top() + 1) == (int) data))
      st.pop();
    else
      st.push(data);
  }
  return (st.empty());
}
int main() {
  int t;
  string a;
  cout << "Enter the number of test cases ";
  cin >> t;
  // run loop till t is not equal to 0
  while (t--) {
    cout << "Enter the expression ";
    cin >> a;
    if (isBalanced(a))
      cout << "Expression " << a << " is balanced" << endl;
    else
      cout << "Expression " << a << " is not balanced" << endl;
  }
}
/*
Input: Enter the number of test cases: 1
Enter the expression: ([{}])
Output:
Expression ([{}]) is balanced

Time Complexity: O(| x |);
Space Complexity: O(| x |);
*/
