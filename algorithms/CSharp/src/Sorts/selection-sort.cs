using System;

namespace Algorithms.Sorts
{
    public class SelectionSort
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

            // One by one move boundary of unsorted subarray 
            for (int i = 0; i < n - 1; i++)
            {
                // Find the minimum element in unsorted array 
                int min_idx = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (source[j] < source[min_idx])
                    {
                        min_idx = j;
                    }
                }

                // Swap the found minimum element with the first 
                // element 
                int temp = source[min_idx];
                source[min_idx] = source[i];
                source[i] = temp;
            }
        }
    }
}