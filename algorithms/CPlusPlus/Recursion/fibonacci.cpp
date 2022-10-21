/*
    Description: Program to calculate fibonacci using recursion

    Time complexity: O(2^n) where n is the number
*/
#include <iostream>
using namespace std;

//Recursive function with integer parameter
int RecursiveFibonacci(int number)
{
    if(number == 0 || number == 1)
        return 1;

    if(number >= 2)
        return RecursiveFibonacci(number - 1) + RecursiveFibonacci(number - 2);
        
    return 0;
}

//Main function
int main(int argc, char *argv[])
{
    int number = 10;
    int result = RecursiveFibonacci(number);
    cout <<"Fibonacci of " <<number <<": " << result << "\n";
    return 0;
}