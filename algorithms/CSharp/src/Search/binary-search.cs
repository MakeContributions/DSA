using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Algorithms.Search
{
   public class BinarySearch
    {
        public static void Main()
        {
            var sortedArray = new int[] { 2, 4, 7, 9, 23 };
            var item = 9;

            var resultIndex = Search(sortedArray, item);
            if (resultIndex != -1)
            {
                Console.WriteLine($"item {item} found at index {resultIndex} into array");
            }
            else
            {
                Console.WriteLine($"item {item} not found into array");
            }
        }

        ///Prerequisite: Array must be sorted
        //Returns index of item if it is present in sorted array, else return -1
        public static int Search(int[] sortedArr, int item)
        {
            var arrLength = sortedArr.Length;
            if (arrLength == 0)
            {
                return -1;
            }

            var left = 0;
            var right = arrLength -1;

            while (left <= right)
            {               
                var mid = (left + right) / 2;  
                if (item == sortedArr[mid])
                {
                    return mid;
                }
                if (item < sortedArr[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }               
            }
            return -1;
        }

        public static int BuiltInBinarySearch(List<int> input, int item)
        {
            var sortedList = input.OrderBy(x => x).ToList();
            var index = sortedList.BinarySearch(item);
            return index < 0 ? -1 : index;
        }
    }
}
