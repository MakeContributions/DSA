#include<bits/stdc++.h>
using namespace std;

int octal_to_decimal(int n){
    int num=0,r,multiplier=1;
    while(n>0){
        r=n%10;
        num=num + (r*multiplier);
        n=n/10;
        multiplier=multiplier*8;  
    }
    return num;
}

int main(){
    int n;
    cin>>n;
    int decimal=octal_to_decimal(n);
    cout<<decimal;
}