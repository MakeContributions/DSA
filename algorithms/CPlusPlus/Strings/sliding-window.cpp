/*
Description: A program to find target sub string in given string 

Approach: Using sliding window technique to compare every possible substring with the target string.
It also supports variable length target inputs since we are initialising window size with size of target

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
            notfound = false;
        }
    }
    if(notfound)
        cout<<"Target Not found";
}

int main() {
    string target="Ipsum";
    string s = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsu";
    sliding(s,target);
    
    cout<<"\nenter the target string:";
    cin>>target;

    sliding(s,target);
    
    return 0;
}