#include<bits/stdc++.h>
using namespace std;

int main(){
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(5);
    for(auto el:ms)
    cout<<el;
    cout<<endl;
    ms.erase(ms.find(1));
    for(auto el:ms)
    cout<<el;
    cout<<endl;
    ms.erase(5);
    ms.erase(1);
    for(auto el:ms)
    cout<<el;
    cout<<endl;
}