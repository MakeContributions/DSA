#include<bits/stdc++.h>
using namespace std;
int binarytodecimal(int n){
    int two=1,r,num=0;
    while(n>0){
        r=n%10;
        num=num + two*r;
        two*=2;
        n/=10;
    }
    return num;
}
int main(){
    int n;
    cin>>n;
    int decimal=binarytodecimal(n);
    cout<<decimal;
}