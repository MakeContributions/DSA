using System;
using System.Collections.Generic;

namespace Algorithms.Arrays
{
    public class SingleNumber
    {
        public static int DetermineSingleNumber(List<int> numbers)
        {
            int single = numbers[0];
            for(int i = 1; i < numbers.Count; i++)
            {
                single ^= numbers[i];
            }

            return single;
        }

        public static void Main()
        {
            List<int> numbers = new List<int> { 7, 1, 2, 3, 1, 7, 2 };
            Console.WriteLine(DetermineSingleNumber(numbers));
        }
    }
}


/*
 * Given a non-empty list of integers, every element except one appears twice
 * Find out the single one
 * Time complexity: O(n)
 * Space complexity: O(1)
 */