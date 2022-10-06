/* Fibonacci Checker - A program to check whether a number is in the Fibonacci sequence.
This sequence is defined by: Fn = Fn-1 + Fn-2 (to find Fn, you add the previous two numbers. The program calculates the Fibonacci sequence up to and including the given number. */
using System;

namespace Algorithms.Maths
{
    public class Fibonacci
    {
        public static bool Checker(int num)
        {
            if (num == 2 || num == 3)
            {
                return true;
            }
            var num1 = 0;
            var num2 = 1;
            var num3 = 1;

            for (var i = 0; i <= num; i++)
            {
                if (num1 == num)
                {
                    return true;
                }
                num1 = num2;
                num2 = num3;
                num3 = num1 + num2;
            }
            return false;
        }
    }
}
