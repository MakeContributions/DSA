#include<bits/stdc++.h>
using namespace std;

//pick and don't pick algorithm
//recrsion to print all subsequence

void permute(string t, int i, int n, string s){
   if(i==n)
    {
     cout<<t<<endl;
    }
   else{
     permute(t,i+1,n,s);
     t = t + s[i];
     permute(t,i+1,n,s);
       }
 }
   int main(){
     string s = "abc";
     permute("", 0 , s.length() , s );
     return 0;
  }