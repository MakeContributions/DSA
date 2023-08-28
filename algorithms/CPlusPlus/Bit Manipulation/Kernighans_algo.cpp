/*
Count no of setbits in an integer- Brian Kernighan's Algorithm
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
Enter no 9
No of setbits in the entered no is 2

Explanation-
   n =  9 (1001)
   count = 0

   Since 9 > 0, subtract by 1 and do bitwise & with (9-1)
   n = 9&8  (1001 & 1000)
   n = 8
   count  = 1

   Since 8 > 0, subtract by 1 and do bitwise & with (8-1)
   n = 8&7  (1000 & 0111)
   n = 0
   count = 2

   Since n = 0, return count which is 2 now.

*/