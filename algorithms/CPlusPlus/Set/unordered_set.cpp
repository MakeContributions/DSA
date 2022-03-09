#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<int> us;
    us.insert(2);
    us.insert(1);
    us.insert(4);
    us.insert(5);
    for(auto el:us)
    cout<<el;
    cout<<endl;
}