/*
    Description: Program to calculate fibonacci using recursion
*/
#include <iostream>
using namespace std;

int RecursiveFibonacci(int number)
{
    if(number == 1 || number == 2)
        return 1;

    if(number >= 3)
        return RecursiveFibonacci(number - 1) + RecursiveFibonacci(number - 2);
        
    return 0;
}

int main(int argc, char *argv[])
{
    int number = 10;
    int result = RecursiveFibonacci(number);
    cout <<"Fibonacci of " <<number <<": " << result << "\n";
    return 0;
}