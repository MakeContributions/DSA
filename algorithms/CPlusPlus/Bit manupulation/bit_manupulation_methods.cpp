#include<bits/stdc++.h>
using namespace std;

int setbit(int n,int pos){
    return (n|(1<<pos));
}
int getbit(int n,int pos){
    return (( n &(1<<pos) )!=0);
}
int removebit(int n,int pos){
    return (n &(~(1<<pos)));
}
int updatebit(int n,int pos,int val){
    int a=n & (~(1<<pos));
    return (a|(val<<pos));
}

int main(){
    int n,p,v;
    cin>>n>>p;
    cout<<getbit(n,p)<<endl;
    cout<<setbit(n,p)<<endl;
    cout<<removebit(n,p)<<endl;
    cin>>v;
    cout<<updatebit(n,p,v)<<endl;
}