#include<stdio.h>
int main()
{
int n,r,sum=0,t;
printf("Input the number to be checked: ");
scanf("%d",&n);
t=n;
while(n>0)
{
r=n%10;
sum=(sum*10)+r;
n=n/10;
}
if(t==sum)
printf("Input number is a Palindrome ");
else
printf("Input number is not Palindrome");
return 0;
}
