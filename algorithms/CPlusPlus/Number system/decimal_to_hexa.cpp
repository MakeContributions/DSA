#include<bits/stdc++.h>
using namespace std;

string decimal_to_hexa(int n){
    int multipler=1;
    while(multipler<=n)
        multipler*=16;
    multipler/=16;
    string num="";
    int d;
    while(multipler>=1){
        d=n/multipler;
        if(d>9){
            char c='A'+(d-10);
            num= num + c;
        }
        else
        num=num + to_string(d);
        n=n-(d*multipler);
        multipler/=16;
    }
    return num;
}
int main(){
    int n;
    cin>>n;
    string hexa=decimal_to_hexa(n);
    cout<<hexa;
}