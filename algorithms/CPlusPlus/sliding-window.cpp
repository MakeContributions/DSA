/*
Description: A program to find target sub string in given string 

Approach: Using sliding window technique to compare every possible substring with the target string.
Also Implementing the variable length sliding window algorithm where user can give size of window and target string of same size

Time complexity: O(n)
*/


#include <iostream>
#include <string>

using namespace std;

void sliding(string s,string target){
    int window_size=target.size();
    bool notfound=true;
    for(int i=0;i<s.size();i++){
        
        string value = s.substr(i,window_size);
       
        if(target==value){
            cout<<target<<" found at "<<i<<" and "<<i+window_size<<endl;
        }
    }
    if(notfound)
        cout<<"Target Not found";
}

void sliding_with_variable_length(string s,string target,int wins){
    int window_size=wins;
    bool notfound=true;
    for(int i=0;i<s.size();i++){
        
        string value = s.substr(i,window_size);
       
        if(target==value){
            cout<<target<<" found at "<<i<<" and "<<i+window_size<<endl;
        }
    }
    if(notfound)
        cout<<"Target Not found";
}


int main() {
    string target="Ipsum";
    string s = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsu";
    sliding(s,target);
    
    int wins;
    cout<<"\nenter the target string:";
    cin>>target;
    wins = target.size();
    sliding_with_variable_length(s,target,wins);
    
    return 0;
}