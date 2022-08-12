using System;

namespace Algorithms.Sorts
{
    public class QuickSort
    {
        public static void Main()
        {
            int[] array = { 10, 7, 8, 9, 1, 5 };

            Sort(array, 0, array.Length - 1);
            PrintArray(array);
        }

        /// <summary>
        /// Sorts an array.
        /// </summary>
        /// <param name="array">Array to be sorted.</param>
        /// <param name="low">Starting index.</param>
        /// <param name="high">Ending index.</param>
        public static int[] Sort(int[] array, int low, int high)
        {
            if (low < high)
            {
                // Select a pivot
                int pivot = Partition(array, low, high);

                // Sort each subarray
                Sort(array, low, pivot - 1);
                Sort(array, pivot + 1, high);
            }

            return array;
        }

        /// <summary>
        /// This method takes the last element as pivot, places
        /// it at its correct position in sorted array, and
        /// places all smaller (smaller than pivot)
        /// to left of it and all greater elements to its right.
        /// </summary>
        /// <param name="array">Array to be sorted.</param>
        /// <param name="low">Starting index.</param>
        /// <param name="high">Ending index.</param>
        /// <returns></returns>
        private static int Partition(int[] array, int low, int high)
        {
            int pivot = array[high];
            int i = low - 1;

            for (int j = low; j <= high - 1; j++)
            {
                // If current element is smaller than the pivot
                if (array[j] < pivot)
                {
                    // Increment index of smaller element and swap them
                    i++;
                    Swap(array, i, j);
                }
            }

            Swap(array, i + 1, high);

            return (i + 1);
        }

        /// <summary>
        /// Swaps two elements.
        /// </summary>
        /// <param name="array">Array to be sorted.</param>
        /// <param name="i">An index.</param>
        /// <param name="j">Another index.</param>
        private static void Swap(int[] array, int i, int j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }

        static void PrintArray(int[] array)
        {
            Console.Write("Sorted array: ");

            for (int i = 0; i < array.Length; i++)
            {
                Console.Write($"{array[i]} ");
            }
                
            Console.WriteLine();
        }
    }
}

