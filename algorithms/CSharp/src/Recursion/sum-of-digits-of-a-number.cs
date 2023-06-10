// Description : Given an interger number, the the sum of its digits is returned using recursion.
// Example:
// Input 123: Output 6
// Time Complexity = O(N), Space Complexity = O(N)

using System;

namespace Algorithms.Recursion
{
    public class SumOfDigitsOfANumber
    {
        public static int SumDigits(int number)
        {
            if (number != 0)
                return  number % 10 + SumDigits(number / 10);
            
            return 0;
        }
        
        public static void Main()
        {
            Console.WriteLine($"Sum of Digits in 123 is {SumDigits(123)}");
        }
    }
}