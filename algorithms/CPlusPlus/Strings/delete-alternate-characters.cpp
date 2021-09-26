/*
Description: To delete alternate characters in a string
Approach: To iterate over string and append the alternate characters in the output string
*/

#include <iostream>
#include <string>
using namespace std;

//function
string delAlternate(string S) {
  // declaring an output string
  string r;
  //iterating over string and incrementing i by 2 to take alternate characters
  for(int i=0;i<S.length();i+=2) {
        r+=S.at(i);
    }
  return r;
  }

//main starts
int main() {
  std::cout << "Enter a string: \n";
  string s;
  cin>>s;
  cout<<delAlternate(s);
}

/*
Sample Input: 
Enter a string:
hello
output:
hlo
*/