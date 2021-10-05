/*
Description: Given a list of names, display the longest name.

Approach: To use length() method for every array element
Keeping the index of maximum length string in max variable

Time Complexity: O(n)
*/

#include <iostream>

using namespace std;
//function starts
string longest(string names[], int n) { //storing the index of max-length string
  int max = 0;

  for (int i = 1; i < n; i++) {
    if (names[i].length() > names[max].length()) {
      max = i;
    }
  }
  //returning the string at max index   
  return names[max];
}

//main starts  
int main() {
  //names array
  string names[] = {
    "hi",
    "hello",
    "helloall",
    "helloeveryone"
  };
  //calculating size of the array
  int n = sizeof(names) / sizeof(names[0]);
  cout << "The longest string in the array is: " << longest(names, n);
  return 0;
}

/*
names=["hi","hello","helloall","helloeveryone"]

Output: 
The longest string in the array is: helloeveryone
*/
