/* Program to find whether a number is kaprekar or not */

#include<iostream>
class Kaprekar
{
    // num private member variable
    int num;
public:
    //constructor to initialize n in num
    Kaprekar(int n)
    {
        num=n;
    }

// Function to calculate the total number of digits in the number.
int total_digits()
{
    int t=0,s=num;
    //until the s is not equal to 0 run the loop
    while(s)
    {
        //divide s by 10 and assign it to s
        s=s/10;
        //increment t by 1
        t++;
    }
return t;
}
//Function to check whether the number is Kaprekar or not.
int is_kaprekar(int total,int n)
{
int i=0,arr[total],a=0,b=0,s=num;
//until s is not equal to 0 run loop
while(s!=0)
{
    // assign s%10 in arr[i]
 arr[i]=s%10;
  //divide s by 10 and assign it to s
  s=s/10;
  //increment i by 1
  i++;
}
/* assign total digit in num variable in i and until i is greater and equal to
total-(total/2) run the loop and decrement i by 1 */
for(i=total-1;i>=total-(total/2);i--)
{
   //assign a*10+arr[i] in a
   a=a*10+arr[i];
}
//now until i is not equal to 0 run the loop
while(i>=0)
{
// assign b*10+arr[i] in b
b=b*10+arr[i];
// decrement i by 1
i--;
}
// checking whether the number is kaprekar
if(a+b==n)
    return 1;
else
    return 0;
}
};
//driver code
int main(int argc,char *argv[])
{
    int n,total,res,s;
    std::cout<<"Enter a number: ";
    //taking input in n
    std::cin>>n;
    s=n*n;
    Kaprekar k(s);
    //calling function k.total_digit() to get the total digit of number n
    total=k.total_digits();
    //calling is_kaprekar function to check whether the number is kaprekar or not
    res=k.is_kaprekar(total,n);
    //printing the res which contain 1(kaprekar) or 0(not Kaprekar)
    if(res)
        std::cout<<n<<" is a kaprekar number"<< std::endl;
    else
        std::cout<<n<<" is not a kaprekar number"<< std::endl;
    return 0;
	
}
/*
Input: Enter a number: 9
Output:9 is a kaprekar number
*/