/* Program to check whether a number is abundant or not */
using System;

namespace abundant_number
{
    class Solution
    { 
        // function to check whether number is abundant or not
        public static bool Abudant(int num)
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
                return true;
            // it is not an abundant number
            else
                return false;
        }
        // driver code
        static void Main(string[] args)
        {
            int num;
            bool res;
            Console.WriteLine("Enter a number: ");
            // reading data and converting into into int to store that in num variable
            num = Convert.ToInt32(Console.ReadLine());
            res = Abudant(num);
            if (res)
                Console.WriteLine($"{num} is an abundant number");
            else
                Console.WriteLine($"{num} is not an abundant number");
        }

    }
}
