#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(2);
    for(auto el:s)
    cout<<el;
    cout<<endl;
    for(auto el=s.begin();el!=s.end();el++)
    cout<<*el;
    cout<<endl;
    for(auto el=s.rbegin();el!=s.rend();el++)
    cout<<*el;
    cout<<endl;


    set<int,greater<int>> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(2);
    for(auto el:s1)
    cout<<el;
    cout<<endl;
}