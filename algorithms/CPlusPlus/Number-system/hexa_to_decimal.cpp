#include<bits/stdc++.h>
using namespace std;

int hexa_to_decimal(string n){
    int l=n.size();
    l=l-1;
    int ans=0,x=1;
    while(l>=0){
        if(n[l]>='0' && n[l]<='9')
            ans+=(n[l]-'0')*x;
        else   
            ans+=x*(n[l]-'A'+10);
        x*=16;
        l--;     
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    int decimal=hexa_to_decimal(s);
    cout<<decimal;
}