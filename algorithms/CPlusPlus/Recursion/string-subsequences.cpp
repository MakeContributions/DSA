/*
Description: Recursion Program to find subsequences of a string.

Example:
Original String = "abc"
Output = {"", "c" , "b", "bc", "a", "ac", "ab", "abc"}

Appraoch:
Subsequences are the every possible sequences that can be formed from a string
from a empty string to every character in the string.

In the below code we return the array size which contains our subsequences.
In every recursion call the function get the double subsequences of what it was
before by adding single character to the previous call.
*/

#include <iostream>
#include <string>
using namespace std;
int str_subsequences(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    string subStr = input.substr(1);
    int smallOutputSize = str_subsequences(subStr, output);
    for (int i = 0; i < smallOutputSize; i++)
    {
        output[i + smallOutputSize] = input[0] + output[i];
    }
    return 2 * smallOutputSize;
}

int main()
{
    string s = "abc";
    string *out = new string[1000];
    int c = str_subsequences(s, out);
    for (int i = 0; i < c; i++)
    {
        cout << out[i] << endl;
    }
    return 0;
}