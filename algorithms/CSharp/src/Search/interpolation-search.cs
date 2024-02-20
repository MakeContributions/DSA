using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Algorithms.Search
{
   public class InterpolationSearch
    {
        public static void Main()
        {
            var sortedArray = new int[] { 3, 4, 7, 10, 12, 18 };
            var item = 4;

            var resultIndex = Search(sortedArray, item);
            if (resultIndex != -1)
            {
                Console.WriteLine($"Item {item} was found at index {resultIndex} in the array");
            }
            else
            {
                Console.WriteLine($"Item {item} was not found in the array");
            }
        }

        // Array must be sorted
        // Returns index of item if it is present in sorted array, else return -1
        public static int Search(int[] arr, int item)
        {
            var left = 0;
            var right = arr.Length - 1;

            while (item >= arr[left] && item <= arr[right] && left <= right)
            {       
                // Probing index of item
                var probe = left + (right - left) * (item - arr[left]) / (arr[right] - arr[left]);
                if (item == arr[probe])
                {
                    return probe;
                }
                if (item < arr[probe])
                {
                    right = probe - 1;
                }
                else
                {
                    left = probe + 1;
                }               
            }
            return -1;
        }
    }
}
