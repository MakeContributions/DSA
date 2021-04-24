/* Program to find whether a number is kaprekar or not */

#include<iostream>
class Kaprekar
{
    // number private member variable
    int number;
public:
    //constructor to initialize n in number
    Kaprekar(int n)
    {
        number=n;
    }

// Function to calculate the total number of digits in the number.
int total_digits()
{
    int total_count=0,copy=number;
    //until the copy is not equal to 0 run the loop
    while(copy)
    {
        //divide copy by 10 and assign it to copy
        copy=copy/10;
        //increment total_count by 1
        total_count++;
    }
return total_count;
}
//Function to check whether the number is Kaprekar or not.
int is_kaprekar(int total_count,int square,int number)
{
int i=0,arr[total_count],left=0,right=0,copy=square;
//until copy is not equal to 0 run loop
while(copy!=0)
{
    // assign copy%10 in arr[i]
 arr[i]=copy%10;
  //divide copy by 10 and assign it to copy
  copy=copy/10;
  //increment i by 1
  i++;
}
/* assign total_count-1 in i and until i is greater and equal to
total_count-(total_count/2) run the loop and decrement i by 1 */
for(i=total_count-1;i>=total_count-(total_count/2);i--)
{
   //assign left*10+arr[i] in left
   left=left*10+arr[i];
}
//now until i is not equal to 0 run the loop
while(i>=0)
{
// assign right*10+arr[i] in right
right=right*10+arr[i];
// decrement i by 1
i--;
}
// checking whether the left+right sum is equal to number
if(left+right==number)
    return 1;
else
    return 0;
}
};
//driver code
int main(int argc,char *argv[])
{
    int number,total_count,result,square;
    std::cout<<"Enter a number: ";
    //taking input in number
    std::cin>>number;
    square=number*number;
    Kaprekar k(square);
    //calling function k.total_digit() to get the total digit of number
    total_count=k.total_digits();
    //calling is_kaprekar function to check whether the number is kaprekar or not
    result=k.is_kaprekar(total_count,square,number);
    //printing the result which contain 1(kaprekar) or 0(not Kaprekar)
    if(result)
        std::cout<<number<<" is a kaprekar number"<< std::endl;
    else
        std::cout<<number<<" is not a kaprekar number"<< std::endl;
    return 0;

}
/*
Input: Enter a number: 9
Output:9 is a kaprekar number
*/
