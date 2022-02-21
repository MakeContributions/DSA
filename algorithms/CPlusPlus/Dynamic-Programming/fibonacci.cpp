/*
Fibonacci series- 0,1,1,2,3,5,...
Given a number n, we have to print the nth term of the fibonacci series
Example- if n=0, the answer will be 0
         if n=1, the answer will be 1
         if n=1, the answer will be 1 (sum of 0 and 1)
         if n=2, the answer will be 2 (sum of 1 and 1)
         and so on..

Time Complexity - O(n)
Space Complexity - O(1)
*/

class Solution {
public:
    int fib(int n) {
        
        if(n<2)        // if n<2, i.e, if n is 0 or 1 return n because 0th term is 0 and 1th term is 1
            return n;
        
        int prev1=1;  
        int prev2=0;
        
        for(int i=2; i<=n; i++)
        {
            int curr = prev1+prev2;  // the current term is sum of the two terms before it, here prev1 is (i-1)th term and prev2 is (i-2)th term
            prev2=prev1;
            prev1=curr;
        }
        
        return prev1;  //at the end prev1 will have the value of the nth term, so we will return it
        
    }
};
