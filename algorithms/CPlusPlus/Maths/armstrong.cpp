#include <iostream>
using namespace std;
int main() {
int num, i=0,r,sum=0,s;
//cout <<"enter a number to check it is Armstrong no. or not ";
cin>>num; 
s=num;
while (i<num)
{
    r=num%10;
    sum =sum+(r*r*r);
    num =num/10;
}
if(sum==s)
cout <<"it is a Armstrong number ";
else 
cout <<"it is not a Armstrong number ";
    return 1;
}