

#include <iostream>

using namespace std;

/**
 *   The Fibonacci Sequence is the series of numbers:
 *
 *   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
 *
 *   The next number is found by adding up the two numbers before it:, next number is the sum of previous two numbers
 *   for example 0,
 *   1, 1, 2, 3, 5, 8, 13, 21 etc. The first two numbers of fibonacci series are 0 and 1.
 *
 * */

class Fibonaccci {
public:

    void print_fibonaccci_no_R() {
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
    }

    void printFibonacci_R(int n) {
        if (n > 0) {
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
            cout << n3 << " ";
            printFibonacci_R(n - 1);
        }
    };

private:
    int n1 {0} ;
    int n2 {1} ;
    int n3  ;
    
};


int main() {
    Fibonaccci f;
    // f.print_fibonaccci_no_R();
    f.printFibonacci_R(8);
    return 0;
}





