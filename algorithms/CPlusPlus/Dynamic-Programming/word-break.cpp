/*

Given a string A and a dictionary of n words B. find out if A can be segmented into a 
space-seprated sequence of dicrionary words.


Note: From the dictionary B each word can be taken any number of times
and in any order 

Example 1:

N = 12
B = {"i", "like", "sam", "sung", "samsung", "mobile", "ice", "icecream", "man",
"man", "go", "mango"}
A = "ilike"

Ouput:  1 (True)
Explanation:
String can be segmented as "i like"


TOPICS: Dynamic Programing; Matrix Chain Multiplication Algo. 

*/


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Utility function to find if a string exist in dictionary (find in vector of string)
inline bool findVec(vector<string>& vec, string str)
{
    return (find(vec.begin(), vec.end(), str) != vec.end());
}

// rec_fun with dictionary, indices of start and end of substring A and array to store previous rec. calls
int rec_fun(string A, vector<string>& B, int start, int end, int** dp)
{
    
    string partial_string = A.substr(start, end - start + 1);
    if(dp[start][end] != -1)
        return dp[start][end];
    if(findVec(B, partial_string))  // if substring found in the dictionary
    {
        dp[start][end] = 1;
        return dp[start][end];
    }
    if(start == end)    // Base case with substring of size 1 and the substring not present in dictionary
    {
        dp[start][end] = 0;
        return dp[start][end];
    }
    
    // Using Matrix Chain Multiplication fundamentals to partition string
    // from k= start +1 to k = end
    for(int k= start +1; k<=end; k++)
    {
        int l_subcall = rec_fun(A, B, start, k-1, dp);
        if(!l_subcall)  // if left partition substring's recursive call not found in dictionary try different value of k
            continue;
        int r_subcall = rec_fun(A, B, k, end, dp);

        if(l_subcall & r_subcall) // if both left and right subcalls are valid partitions then given string partition found in dictionary
        {
            dp[start][end] = 1;
            return dp[start][end];
        }

    }

    dp[start][end] = 0;
    return dp[start][end];

}


bool wordBreak(string A, vector<string>& B )
{
    //dp array used for memoizing the recursive calls 
    int end = A.size() -1;
    int** dp = new int*[end+1];
    for(int i=0; i<=end; i++)
    {
        dp[i] = new int[end+1];
        for(int j=0; j<=end; j++)
            dp[i][j] = -1;  // initializing array with -1;
    }
    int start = 0;
    return rec_fun(A, B, start, end, dp);
}

int main()
{
    int t ;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<string> dict;
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            dict.push_back(s);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<endl;
    }

}