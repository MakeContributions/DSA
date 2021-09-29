/*
Description: A C++ program to print first letter of every word in a string
*/

//importing c++ libraries
#include <iostream>
#include <string>
using namespace std;

//function
string firstAlphabet(string s){
  //declaring an output string 'o'
  string o;

  //inserting 1st letter in the output string if it's not starting with space
  if (s[0] != ' ')  {
    o += s[0];
  }
  //iterating over the string from index 1
  //if space is found, then the next character is appended in the output string
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ' && s[i + 1] != ' ')  {
      o += s[i + 1];
    }
  }

  //returning the string
  return o;
}

//main starts
int main()  {
  std::cout << "Enter a string: \n";
  string s;
  getline(cin, s);
  cout << firstAlphabet(s);
}

/*
Sample Input:
Enter a string:
Hello everyone, it's Jamie!

Output:
HeiJ
*/
