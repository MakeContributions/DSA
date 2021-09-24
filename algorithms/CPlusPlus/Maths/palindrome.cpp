#include<iostream>
using namespace std;
int main()
{
	string num_str = "";
	cin >> num_str;
	string new_str = "";

	for(int x = (num_str.size()-1); x >= 0; x--){
		new_str += num_str[x];
	}

	cout << (num_str == new_str ? "palindrome" : "Non-palindrome");

	return 0;
}