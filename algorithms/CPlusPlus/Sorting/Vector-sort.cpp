#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size,pos,start,end,n,i,a,j;
    cin>>n;
    vector<int>v;
    for(i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }   
    cin>>pos>>start>>end;
    v.erase(v.begin()+(pos-1));
    v.erase(v.begin()+start-1,v.begin()+end-1);
    size=v.size();
    cout<<size<<endl;
    for(j=0;j<size;j++)
    {
        cout<<v[j]<<" ";
    }
return 0;
}
