/*
Description: Given a string 's', return the index of the first unique character from the string. If not found, return -1

Time Complexity: O(n) where n is the length of the string
*/
#include <iostream>
#include <map>
using namespace std;

//function starts
int firstUniqChar(string s)
{
    //declare a map to store the frequency of the character
    map<char, int> m;
    //storing the character and its frequency in the map for every character in the string
    for (char c : s)
    {
        m[c]++;
    }
    //the frequency of the non-repreating or unique character will be 1
    //1 indicates that it had appeared only once in the string
    //since we want to search from the beginning of the string
    //use for loop from beginning of the string
    //to check if that character appeared for a single time
    //if yes, return the index
    for (int i = 0; i < s.size(); i++)
    {
        if (m[s[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}

//main starts
int main()
{
    string s;
    cout << "Enter a string: \n";
    getline(cin, s);
    cout << firstUniqChar(s);
    return 0;
}

/*
Example 1:

Input: s = "leetcode"
Output: 0

Example 2:

Input: s = "loveleetcode"
Output: 2

Example 3:

Input: s = "aabb"
Output: -1
*/