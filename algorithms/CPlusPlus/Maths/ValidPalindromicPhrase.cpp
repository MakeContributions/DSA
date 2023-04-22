//O(n) time complexity; O(1)->space complexity
//A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing 
//all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include 
//letters and numbers.

#include<iostream>
#include<algorithm>

using namespace std;

bool isPalindrome(string s) 
    {
        if(s.length()==1)
         return true;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int l=0;
        int h=s.length()-1;
        while(l<h)
        {
            while(!((s[l]>='a' && s[l]<='z') || (s[l]>='0' && s[l]<='9')))
            {
               if(l<s.length()-1) 
                l++;                 // to ignore all non-alphanumeric symbols 
                else
                return true;
            }
            while(!((s[h]>='a' && s[h]<='z') || (s[h]>='0' && s[h]<='9')))
            {
                if(h>0)
                h--;    // to ignore all non-alphanumeric symbols 
                else return true;
            }
            if(s[l]!=s[h])
             return false;//since the alphaumeric character is not equal. therefore it is not a palindrome
             l++;
             h--;
        } 
        return true;
    }
 int main()
 {
   string s;
   cout<<"Enter String:"<<endl;
   cin>>s;
   cout<<isPalindrome(s)<<endl;// returns 1 if true, else return false
   return 0;
 }
