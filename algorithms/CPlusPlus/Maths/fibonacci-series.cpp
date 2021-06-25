#include <iostream>

using namespace std;

class Fibonacci 
{
    /**
     *   The Fibonacci Sequence is the series of numbers:
     *
     *   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
     *
     *   The next number is found by adding up the two numbers before it:, next number is the sum of previous two numbers
     *   for example 0,
     *   1, 1, 2, 3, 5, 8, 13, 21 etc. 
     *   The first two numbers of fibonacci series are 0 and 1.
     *   Time complexity: O(n)
     * */
public:
    /*
     *   Example 1: the number of elements is introduced by the user via command prompt.
     */
    void print_fibonacci_no_R() 
    {
        int num1 = 0, num2 = 1, num3, i, number;
        cout << "Enter the number of elements: ";
        cin >> number;
        cout << num1 << " " << num2 << " "; //printing 0 and 1

        for (i = 2; i < number; ++i) //loop starts from 2 because 0 and 1 are already printed
        {
            num3 = num1 + num2;
            cout << num3 << " ";
            num1 = num2;
            num2 = num3;
        }
        cout << "\n\n"; //printing 0 and 1
    }

    /*
     *   Example 2: the number of elements is introduced by the user via function input parameter.
     */
    void printFibonacci_R(int n) 
    {
        if (n > 2)
        { // n finishes at 2 because 0 and 1 are already printed
            if (n1 == 0) cout << n1 << " " << n2 << " "; //printing 0 and 1
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
            cout << n3 << " ";
            printFibonacci_R(n - 1);
        }
    }

private:
    int n1{0};
    int n2{1};
    int n3;

};


int main()
{
    Fibonacci f;
    f.print_fibonacci_no_R();
    f.printFibonacci_R(8);
    return 0;
}