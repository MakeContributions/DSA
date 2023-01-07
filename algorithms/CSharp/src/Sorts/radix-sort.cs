using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms.Sorts
{
    public class RadixSort
    {
        public static List<int> Sort(List<int> numbers)
        {
            int max = numbers.Max();

            for (int exp = 1; max / exp > 0; exp *= 10)
            {
                numbers = CountingSort(numbers, exp);
            }

            return numbers;
        }

        public static List<int> CountingSort(List<int> numbers, int exp)
        {
            int[] counts = new int[10];
            List<int> result = new List<int>(new int[numbers.Count]);

            for (int i = 0; i < numbers.Count; i++)
            {
                counts[(numbers[i] / exp) % 10]++;
            }

            for (int i = 1; i < counts.Length; i++)
            {
                counts[i] += counts[i - 1];
            }

            for (int i = numbers.Count - 1; i >= 0; i--)
            {
                result[counts[(numbers[i] / exp) % 10] - 1] = numbers[i];
                counts[(numbers[i] / exp) % 10]--;
            }

            return result;
        }

        public static void Main()
        {
            List<int> numbers = new List<int> { 100, 10, 1, 1000, 10000 };
            List<int> sortedNumbers = Sort(numbers);

            Console.WriteLine(string.Join(", ", sortedNumbers)); // 1, 10, 100, 1000, 10000
        }
    }
}
