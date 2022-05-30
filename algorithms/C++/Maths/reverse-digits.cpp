/*
Description: A program to reverse the digits of a number.

Approach: Running a while loop over number till it becomes 0
Multiplying the result variable to 10 each time.
Taking the modulus of number at every iteration and adding it to the final result to generate the reverse.
Dividing the number by 10 at every iteration.
*/

#include <iostream>
using namespace std;

//function
long reverse_digit(long n)
{
    //result variable
    long num = 0;
    while (n != 0)
    {
        //storing the last digit of n in temp variable
        long temp = n % 10;
        //multiplying the num variable into 10 and adding temp value to it
        num = num * 10 + temp;
        //Dividing n by 10 at each iteration
        n = n / 10;
    }
    return num;
}

//main starts
int main()
{
    cout << "Enter a number\n";
    long n;
    cin >> n;
    cout << "Reverse number is: ";
    cout << reverse_digit(n);
}

/*
Input: 
Enter a number
1234

Output:
Reverse number is: 4321
*/