#include<bits/stdc++.h>
using namespace std;

int unique(int a[],int n){
    int num=0;
    for(int i=0;i<n;i++){
        num=a[i]^num;
    }
    return num;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<unique(a,n);
}