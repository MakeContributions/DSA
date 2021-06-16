/* Program to check whether a number is abundant or not */
using System;

namespace Abundant.Number
{
    class Abundant
    {
        // function to check whether number is abundant or not
        public static bool IsAbudant(int num)
          {
            int i, sum = 0;
            // loop run until it is less than or equal to half of the number
            for (i = 1; i <= num / 2; i++)
             {
                // if the remainder becomes 0 add that number to sum
                if (num % i == 0)
                    sum += i;
             }
            // if the sum is greater than num that means it is an abundant number
            if (sum > num)
             {
                return true;
             }
            else // it is not an abundant number
             {
                return false;
             }
          }

        // driver code
        static void Main(string[] args)
        {
            int num;
            bool res;
            Console.WriteLine("Enter a number: ");
            // reading data and converting into into int to store that in num variable
            num = Convert.ToInt32(Console.ReadLine());
            res = IsAbudant(num);
            if (res)
            {
                Console.WriteLine($"{num} is an abundant number");
            }
            else
            {
                Console.WriteLine($"{num} is not an abundant number");
            }
        }
    }
}
/*
Input: Enter a number: 54
Output: 54 is an abundant number
Time complexity: O(N/2) where is the num given by user
Space complexity: O(1)
*/
