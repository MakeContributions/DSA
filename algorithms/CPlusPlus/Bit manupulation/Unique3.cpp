#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int sum=0,num=0;
    for(int i=0;i<64;i++){
        sum=0;
        for(int j=0;j<n;j++){
            if(a[j]&(1<<i))
            sum++;
        }
        if(sum%3 !=0)
        num=(num|(1<<i));
    }
    cout<<num;
}
