using System;

namespace Algorithms.Sorts
{
    public class InsertionSort
    {
        public static void Main()
        {
            int[] arr = { 800, 11, 50, 771, 649, 770, 240, 9 };
            Sort(arr);
            var result = string.Join(" ", arr);
            Console.WriteLine(result);
        }

        public static void Sort(int[] source)
        {
            int n = source.Length;
            for (int i = 1; i < n; ++i)
            {
                int key = source[i];
                int j = i - 1;

                // Move elements of arr[0..i-1], 
                // that are greater than key, 
                // to one position ahead of 
                // their current position 
                while (j >= 0 && source[j] > key)
                {
                    source[j + 1] = source[j];
                    j = j - 1;
                }
                source[j + 1] = key;
            }
        }
    }
}