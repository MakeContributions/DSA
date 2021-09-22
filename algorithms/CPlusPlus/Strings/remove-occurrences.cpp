/*
Description: A C++ program to remove occurrence of characters of 2nd string from the 1st string

*/

#include <string>
#include <iostream>
using namespace std;

string removeChars(string s1, string s2) {
    
    string out;
    //checking if the character of 2nd string is present in the 1st string
    //if not present, appending the character in the output string
    for (char c : s1) {
  
        if (s2.find(c) == string::npos) {
      
            out += c;
        }
    }
    return out;
}

//main starts
int main() {

    string s1, s2;
    cout << "Enter string 1: \n";
    getline(cin, s1);
    cout << "Enter string 2: \n";
    getline(cin, s2);
    string output = removeChars(s1, s2);
    cout << output;
    return 0;
}

/*
Sample input
Enter string 1: 
computer
Enter string 2: 
cat

output:
ompuer
(removed c,a,t)
*/
