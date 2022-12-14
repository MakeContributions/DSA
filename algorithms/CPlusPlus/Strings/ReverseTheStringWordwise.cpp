// Description :- Given a string, the task is to reverse the order of the words in the given string. 
// Example :-
// Input 1:
//    A = "the sky is blue"
// Input 2:
//    A = "this is ib"
// Output 1:
//    "blue is sky the"
// Output 2:
//    "ib is this"


// Time Complexity = O(N), Space Complexity = O(N)

#include<bits/stdc++.h>
using namespace std;

string solve(string s) {
   vector<string>v;
        string str="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                str+=s[i];
            }
            else if(str!="" && s[i]==' '){
                v.push_back(str);
                str="";
            }
        }
        if(str!=""){
            v.push_back(str);
        }
        str="";
        for(int i=v.size()-1;i>0;i--){
                str+=v[i];
                str+=' ';
        }
        str+=v[0];
        return str;
}

int main()
{
    string s;
    getline(cin, s);
    cout<<solve(s);
    return 0;
}
