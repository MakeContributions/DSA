#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main(){
    int n,key;
    cout<<"Enter the number of elements\n";
    cin>>n;

    //Declaring the Array
    int A[n];

    cout<<"Enter the Elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cout<<"Enter the element to Search\n";
    cin>>key;

    //Linear Search
    for(int i=0;i<n;i++)
    {
        if(A[i]==key){
            cout<<"Element found at Location "<<i+1<<endl;
        }
    }

    //Linear Search In Vector
    int number;
    vector<int> V;
    cout<<"Enter the Number of Element to Insert in Vector\n";
    cin>>number;

    for(int i=0;i<number;i++){
        int element;
        cin>>element;
        V.push_back(element);
    }
    
    cout<<"Enter the element to Search\n";
    cin>>key;

    //Linear Search
    for(int i=0;i<n;i++)
    {
        if(V[i]==key){
            cout<<"Element found at Location "<<i+1<<" In Vector V"<<endl;
        }
    }

    return 0;
}
//This code is contributed by Amarjeet Singh