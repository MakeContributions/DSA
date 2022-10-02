class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int n=s.size(); 
        
        //dp[i][j] will be false if substring s[i..j] is not palindrome, Else true
        vector<vector<bool>> dp(n, vector<bool> (n,false));
        
        //All substrings of length 1 are palindromes
        for(int i=0; i<n; i++) dp[i][i]=true;
        
        int start=0, lenMax=1;
        
        // check for sub-string of length 2.
        for(int i=0; i<n-1; i++) 
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1] = true;
                start = i;
                lenMax = 2;
            }
        }
        
        // Check for sub-string of length greater than 2.
        for(int k=3; k<=n; k++)  // k is length of substring
        {
            for(int i=0; i<n-k+1; i++) // Fix the starting index
            {
                int j=i+k-1; // Get the ending index of substring from starting index i and length k
                
                // checking for sub-string from ith index to jth index if s[i+1] to s[j-1] is a palindrome
                if(dp[i+1][j-1]==true && s[i]==s[j])
                {
                    dp[i][j] = true;
                    
                    if(k>lenMax)
                    {
                        lenMax = k;
                        start=i;
                    }
                }
            }
        }
        
        return s.substr(start, lenMax); //print sub-string from start to lenMax
    }
};
