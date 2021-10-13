/*
Description: find length of string using recursion.

Approach: To run the recursive call till the end of the string.
Maintaining a iterator variable which will increment at every recursive call
If we reach at the end of the string, return the value of the iterator variable
which will be the length of the string.

Time Complexity: O(n) where n is the length of the string
*/
#include <iostream>
using namespace std;

//function starts
int cal_length(string s, int i = 0)
{
    if (s[i] == '\0')
    {
        return i;
    }
    return cal_length(s, i + 1);
}

//main starts
int main()
{
    string s = "hello";
    cout << cal_length(s);
    return 0;
}

/*
Sample Input: hello
Output: 5

Sample Input: good
Output: 4

Sample Input: github
Output: 6
*/
