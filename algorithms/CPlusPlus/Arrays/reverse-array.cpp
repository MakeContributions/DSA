#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0;
    int j=n-1;
    while(i<j){
        swap(arr[i++],arr[j--]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
    
}
