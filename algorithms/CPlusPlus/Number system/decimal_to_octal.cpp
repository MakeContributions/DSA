#include<bits/stdc++.h>
using namespace std;

int decimal_to_octal(int n){
    int multiplier=1;
    while(multiplier<=n){
        multiplier*=8;
    }
    
    multiplier/=8;
    int num=0;
    while(multiplier>=1){
        num=num*10 + n/multiplier;
        n=n - multiplier*(n/multiplier);
        multiplier/=8;        
    }
    return num;
}
int main(){
    int n;
    cin>>n;
    int octal=decimal_to_octal(n);
    cout<<octal;
}