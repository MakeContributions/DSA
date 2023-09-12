using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms.Recursion {
    public class Fibonacci {

        public static int FibonacciUsingRecursion(int number) {

            if ( (number == 0) || (number == 1) ) {
                return number;
            }

            return FibonacciUsingRecursion(number - 1) + FibonacciUsingRecursion(number - 2);

        }

        public static void Main() {

            Console.WriteLine($"The Fibonacci of 10 is: {FibonacciUsingRecursion(10)}");

        }

    }
}
