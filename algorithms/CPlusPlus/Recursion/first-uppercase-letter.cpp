/*
Description: Program to print the first uppercase letter in a string

Approach: Use a variable to iterate over the string
Increment the iterator by 1 at every recursive call
If the value of iterator reaches till the length of the string, return '\0

Time Complexity: O(n) where n is the length of the string
*/

#include <iostream>
using namespace std;

//function starts
char upper(string s, int i, int len)
{
    //base case
    //if the value of i reaches till length of the string
    //that means we have not found any uppercase letter
    //return '\0
    if (i == len)
    {
        return '\0';
    }
    //if uppercase letter found
    //return it
    if (s[i] >= 'A' and s[i] <= 'Z')
    {
        return s[i];
    }
    //recursive function call
    //the iterator i starts from 0 and increments by 1 at each function call
    return upper(s, i + 1, len);
}

//main starts
int main()
{
    string s = "helloalL";
    int len = s.size();
    char c = upper(s, 0, len);
    cout << c;
    return 0;
}

/*
Sample Input: helloalL
Output: L

Sample Input: hELLOaLL
Output: E
*/