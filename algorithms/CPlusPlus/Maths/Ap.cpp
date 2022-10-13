#include<iostream>
using namespace std;
int main()
{ int n;
cout<<"Enter number of terms : ";
cin>>n;
cout<<"Enter first term and common difference: "<<endl;
int a,d;
cin>>a>>d;
cout<<"The terms are: ";
for(int i=0;i<n;i++)
{ cout<<a+i*d<<",";
}  
return 0;
}