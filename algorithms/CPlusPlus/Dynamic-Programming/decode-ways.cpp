/*
Given a string s containing only digits, return the number of ways to decode it.

A message containing letters from A-Z can be encoded into numbers using the following mapping:
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"

To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6)
*/


int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n+1);
    dp[n] = 1;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == '0') 
            dp[i] = 0;
        else {
            dp[i] = dp[i+1];
            if(i < n-1 && (s[i] == '1'|| (s[i] == '2' && s[i+1] < '7'))) 
                dp[i] += dp[i+2];
        }
    }
    return s.empty() ? 0 : dp[0];   
}

