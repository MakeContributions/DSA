using System;

namespace Algorithms.Recursion
{
    public class Factorial
    {
        public static int FactorialUsingRecursion(int number)
        {
            if(number == 0 || number == 1)
            {
                return 1;
            }

            return number * FactorialUsingRecursion(number - 1);
        }

        public static void Main()
        {
            Console.WriteLine($"Factorial of 7 is: {FactorialUsingRecursion(17)}");
        }
    }
}

/*
 * n! = n * (n - 1) * (n - 2) * .... * 3 * 2 * 1
 * we have used int here but for larger number, int will not be enough
 */