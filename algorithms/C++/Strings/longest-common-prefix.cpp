/*
Description: Given two strings, return the longest common prefix from both of the strings.
Longest common prefix means returning the starting characters which are common in both the strings.
For e.g., 
s1 = "hello"
s2 ="heat"
Longest common prefix will be "he" 
Because only two characters from the starting are common between them.

Time Complexity: O(n) where n is the length of the string
*/
#include <iostream>
using namespace std;

//function starts
string lcp(string s1, string s2)
{
    string ans = "";
    if (s1.size() == 0 || s2.size() == 0)
    {
        return ans;
    }
    //in 'm' variable, we are storing the smallest string's size from s1 and s2
    //because the prefix will always be at most the size of the smallest string
    int m = s1.size() < s2.size() ? s1.size() : s2.size();
    for (int i = 0; i < m; i++)
    {
        //if both the starting characters are not same, then break from the for loop
        if (s1[i] != s2[i])
        {
            break;
        }
        //else if they are same, add the character in the answer string
        else
        {
            ans += s1[i];
        }
    }
    return ans;
}

//main starts
int main()
{
    string s1;
    string s2;
    cout << "Enter string-1 : \n";
    getline(cin, s1);
    cout << "Enter string-2: \n";
    getline(cin, s2);
    cout << "Longest common prefix is: " << lcp(s1, s2);
    return 0;
}

/*
Sample Input:
 string s1 = "flower"
string s2 = "flight"

Output
Longest common prefix is: fl
*/