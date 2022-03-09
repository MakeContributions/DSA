#include<bits/stdc++.h>
using namespace std;

int check2power(int n){
    
    return ((n & (n-1))==0);
}

int main(){
    int n;
    cin>>n;
    cout<<check2power(n);
}