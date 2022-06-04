#include<bits/stdc++.h>
using namespace std;

int reverse(int n){
    int ans=0,d;
    while(n>0){
        d=n%10;
        ans=ans*10 + d;
        n=n/10;
    }
    return ans;
}

int binary_addition(int a,int b){
    int add=0,carry=0;
    while(a>0 && b>0){

        if(a%2==1 && b%2==1){
            add=add*10 + carry;
            carry=1;
        }
        else if((a%2==1 && b%2==0) || (a%2==0 && b%2==1)){
            if(carry==1){
                add=add*10 + 0;
                carry=1;
            }
            else{
                add=add*10 + 1;
                carry=0;
            }
        }
        else{
            add = add*10 + carry;
            carry=0;
        }
        a=a/10;
        b=b/10;
    }
    while(a>0){
        if(a%2==1){
            if(carry==1){
                carry=1;
                add=add*10+0;
            }
            else{
                carry=0;
                add=add*10 + 1;
            }
        }
        else{
            add=add*10 +carry;
            carry=0;
        }
        a=a/10;
    }
    while(b>0){
        if(b%2==1){
            if(carry==1){
                carry=1;
                add=add*10+0;
            }
            else{
                carry=0;
                add=add*10 + 1;
            }
        }
        else{
            add=add*10 +carry;
            carry=0;
        }
        b=b/10;
    }
    if(carry==1){
        add=add*10 +1;
    }
    add=reverse(add);
    return add;
}

int main(){
    int a,b;
    cin>>a>>b;
    int add=binary_addition(a,b);
    cout<<add;
}