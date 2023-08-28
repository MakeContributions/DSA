/*
Count no of setbits in an integer
*/

#include<bits/stdc++.h>

using namespace std;

int Kernighans(int n) {
  int count = 0;
  while(n) {
    n &= (n-1);
    count++;
  }
}

int main() {
  int n;
  cout << "\nEnter no "; //Input
  cin >> n;
  cout << "\nNo of setbits in the entered no is";
  cout << Kernighans(n); // Output
  return 0;
}

/*
Time and space complexity-
Time Complexity- O(no of setbits)
Space Complexity- O(1)

SAMPLE INPUT-
Enter no 3
No of setbits in the entered no is 2

*/