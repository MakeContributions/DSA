// Program to find whether a number and word is palindrome or not.

#include<iostream>				//header file
using namespace std;
int main()						//Main function
{
	string num_str = "";		//define variable
	cin >> num_str;				//taking input from user
	string new_str = "";		//define a new variable

	for(int x = (num_str.size()-1); x >= 0; x--){		//for loop started
		new_str += num_str[x];							//assigning the value input by user to new variable in reverse order
	}													//for loop end

	cout << (num_str == new_str ? "palindrome" : "Non-palindrome");			//checking whether the value assigned to both variables is equal or not using ternary operator and printing whether it's palindrome or non-palindrome

	return 0;					//returning the main function
}

//complexity of the program is O(n)
//test cases:- 101,pop,asdfgfdsa,123454321,obobo,nancyiycnan etc.