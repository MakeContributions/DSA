using System;

namespace Algorithms.Recursion
{
    public class ArraySum
    {
        public static int SumUsingRecursion(int[] numbers, int start)
        {
            if(numbers.Length - 1 == start)
            {
                return numbers[start];
            }

            return numbers[start] + SumUsingRecursion(numbers, start + 1);
        }

        public static void Main()
        {
            Console.WriteLine($"Summation of [1,3,5,7,8,4] is: {SumUsingRecursion(new int[] {1,3,5,7,8,4}, 0)}");
        }
    }
}

/*
 * [1,3,5,7,8,4] = (n - 1) + (n - 2) + .... + 5 + 3 + 1
 * we have used int here but for larger number, int will not be enough
 */