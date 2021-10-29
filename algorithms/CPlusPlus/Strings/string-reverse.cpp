/*
Description: A C++ program to reverse the given string

*/

#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
string reverse_string(string str)//Function returns reversed string 
{
	char ch;
	int j=str.length()-1;//storing length of string 
	for(int i=0;i<j;i++)//Iterating from both sides of string i.e from start and from end
	{
		ch=str[i];
		str[i]=str[j];//swapping two characters in the string
		str[j]=ch;
		j--;
	}
	return str;
}
int main() {
    string s;
    cin>>s;
	s=reverse_string(s);//calling reverse_string function and passing string as parameter
	cout<<s;
return 0;

}
