using System;
using System.Linq;

namespace Algorithms.Arrays
{
    
    public class RemoveDuplicatesFromArray
    {
        public static int RemoveDuplicates(int[] nums)
        {

            int i = 1;

            foreach (int n in nums)
            {
                if (nums[i - 1] != n) nums[i++] = n;
            }

            return i;
        }

        public static void Main()
        {
            int[] numbers = new int[] { 7, 1, 2, 3, 1, 7, 2 };

            int arrayLength = RemoveDuplicates(numbers);

            Console.WriteLine(numbers.ToList().Take(arrayLength));
        }
    }
}

/*
 * Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
 * The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
 */
