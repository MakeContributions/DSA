// Program to find whether a number and word is palindrome or not.

#include<iostream>				//header file
#include<ctype.h>
using namespace std;
int main()						//Main function
{
	string num_str = "";		//define variable
	cin >> num_str;			//taking input from user
	string new_str = "";		//define a new variable

	
	string test_str = "";		//define new variables for cleaning the input
	string low = "";
	char temp;
	int i;

	for(i = 0; i < num_str.size(); i++){				//make num_str all lower case and remove all punctuation and spaces
		temp = num_str[i];
		if(isalnum(temp)){
			low = char(tolower(temp));			//converting the character to be lower case
			test_str.append(low);				//adding that lowercase character to the new string
		}
	}
	for(int x = (test_str.size()-1); x >= 0; x--){		//for loop started
		new_str += test_str[x];							//assigning the value input by user to new variable in reverse order
	}													//for loop end
	
	string pal = "";
	if(test_str == new_str){	//checking if the variables are equal and setting a string according to the result
		pal = "palindrome";
	}else{
		pal = "Non-palindrome";
	}
	cout << pal;			//printing if it is a palindrome or non-palindrome

	return 0;					//returning the main function
}

//complexity of the program is O(n)
//test cases:- 101,pop,asdfgfdsa,123454321,obobo,nancyiycnan etc.
//additional test cases: "Sit o,n a 'potat+o pan, Otis", "Sit on a potato pan, Otis"
