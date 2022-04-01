#include<bits/stdc++.h>
using namespace std;

int decimaltobinary(int n){
    int max=1;
    while(max<=n){
        max=max*2;
    }
    max/=2;             
    int num=0;
    while(max>=1){
        num=num*10 + n/max;
        n-=max*(n/max);
        max=max/2;        
    }
    return num;
}

int main(){
    int n;
    cin>>n;
    int binary=decimaltobinary(n);
    cout<<binary;
}