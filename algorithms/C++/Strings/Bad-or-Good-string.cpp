/*
Program to check whether a string is bad or good
Criteria:
1: If a string contain 3 more than three constant or more than 5 vowels continuously than it is a bad string else good
2: '?' can  be replaced by any alphabets means it can be both constant and vowel
*/
#include<iostream>
#include <string>
using namespace std;

//Function to check whether the character is not vowel
int isVowel(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
    return 1;
    else
    return 0;
}
// Function to check whether the entered string is good or bad
int Bad_or_Good(string s1)
{
// Initializing all variable with 0
int vowel=0,res=0,constant=0;
// until the i is less than s1 length run the loop
for(int i=0; i<s1.length(); i++)
    {
    //if i th character of string is vowel
    if(isVowel(s1[i]))
    {
    // assign 0 to constant
    constant=0;
    // increment vowel
    vowel++;
    // check whether a bad string if yes assign 1 to res and break
    if(vowel>5)
    {
    res=1;
    break;
    }
    //assign 0 to res
    else
    res=0;
    }
    // if s[i]th character is '?'
else if(s1[i] == '?')
    {
     //add 1 in both constant and vowel
     constant++;
     vowel++;
     // check whether it touch the bad string criteria or not
     if(constant>3||vowel>5)
    {
     res=1;
     break;
    }
     else res=0;
    }
    // if the s[i]th character is not a vowel nor '?' that means it is a constant
    else
    {
     //assign 0 to vowel and increment constant
     vowel = 0;
     constant++;
     // check whether the string touch the bad string criteria or not
     if(constant>3)
    {
     res=1;
     break;
    }
     else
     res=0;
    }
    }
return res;
}
//driver code
int main()
{
	int t,res;
	string s1;
	cout<<"Enter the number of test case: ";
	cin>>t;
	//cleaning buffer and going to a new line
	cin.ignore(1, '\n');
	// until t is not equal to 0
	while(t--)
    {
        cout<<"Enter string: ";
        //taking input
	    getline(cin, s1);
	    //calling Bad_or_Good Function to check whether the string is bad or good
        res=Bad_or_Good(s1);
	    if(res==1)
	    cout<<0<<endl;
	    else
	    cout<<1<<endl;
	}
	return 0;

}
/*
Input: Enter string: aeiou??
Output: 0(bad string)
Time complexity: O(N)
*/
