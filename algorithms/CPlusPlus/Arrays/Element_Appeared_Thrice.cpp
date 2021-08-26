#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Taking input as number of elements in array
    int n;
    cin>>n;
    //Declaring the array of n elements
    int a[n];
    //Declaring a map for storing Number of occurences of every element
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    //If no element is appearing thrice then we will print -1
    //If element is present then we will assign that number to res
    // And we will break out from the loop
    int res=-1;
    for(int i=0;i<n;i++)
    {
        if(mp[a[i]]==3)
        {
            res=a[i];
            break;
        }
    }
    //After breaking out from the loop we print res
    cout<<res;
    return 0;
}