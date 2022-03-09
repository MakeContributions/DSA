#include<bits/stdc++.h>
using namespace std;

int unique2(int a[],int n){
    int num=0;
    for(int i=0;i<n;i++)
        num=num^a[i];
    return num;    
}
int getbit(int n,int num){
    return (n&(1<<num));
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int num=unique2(a,n);
    int c=0;
    while(c<num){
        if(num&(1<<c))
        break;
        c++;
    }
    int n1=0;
    for(int i=0;i<n;i++){
        if(getbit(a[i],c))
         n1=n1^a[i];   
    }
    cout<<n1<<" "<<(n1^num);

}