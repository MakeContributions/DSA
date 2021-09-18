/*
Description: A C++ program to print first letter of every word in a string
*/


//importing c++ libraries
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//function
string firstAlphabet(string s){
  //declaring an output string 'o'
string o;
//inserting 1st letter in the output string
	  o+=s[0];
    //iterating over the string from index 1
    //if space is found, then the next character is appended in the output string
	  for(int i=1;i<s.size();i++){
	      if(s[i]==' '){
	          o+=s[i+1];
	      }
	  }
	    return o;
}

//main starts
int main() {
  std::cout << "Enter a string: \n";
  string s;
  getline(cin,s);
  cout<<firstAlphabet(s);  
}