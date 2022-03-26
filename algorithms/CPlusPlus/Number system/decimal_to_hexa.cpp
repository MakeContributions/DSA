#include<bits/stdc++.h>
using namespace std;

string decimal_to_hexa(int n){
    int multiplier=1;
    while(multiplier<=n)
        multiplier*=16;
    multiplier/=16;
    string num="";
    int d;
    while(multiplier>=1){
        d=n/multiplier;
        if(d>9){
            char c='A'+(d-10);
            num= num + c;
        }
        else
        num=num + to_string(d);
        n=n-(d*multiplier);
        multiplier/=16;
    }
    return num;
}
int main(){
    int n;
    cin>>n;
    string hexa=decimal_to_hexa(n);
    cout<<hexa;
}