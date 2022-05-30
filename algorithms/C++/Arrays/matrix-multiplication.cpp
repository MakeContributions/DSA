//given two matrices of sizes n*m and n1*m1 
//find multiplication of the two matrices and print it
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,n1,m1;
   // cout<<"Enter the dimensions of first matrix\n";
    cin>>n>>m;
    int a[n][m];
   // cout<<"Enter the elements of first matrix\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    //cout<<"Enter the dimensions of Second matrix\n";
    cin>>n1>>m1;
    int b[n1][m1];
    //cout<<"Enter the elements of second matrix\n";
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<m1;j++)
        {
            cin>>b[i][j];
        }
    }
    if(m!=n1)
    {
        cout<<"Multiplication of the matrices is not possible";
    }
    else
    {
        int c[n][m1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m1;j++)
            {
                c[i][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m1;j++)
            {
                for(int k=0;k<n1;k++)
               {
                  c[i][j]+=a[i][k]*b[k][j];
               }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m1;j++)
            {
                cout<<c[i][j]<<" ";
            }
            cout<<"\n";
        }
    }    
    return 0;
}
//INPUT
//2 3
//1 2 1
//3 4 1
//3 2
//1 2 
//1 1
//3 7
//OUTPUT
//6 11 
//10 17 
//TIME COMPLEXITY OF THE PROGRAM
//O(n^3)
