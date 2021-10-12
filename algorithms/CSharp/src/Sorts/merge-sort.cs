using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms.Sorts
{
    public class MergeSort
    {
        public static List<int> Sort(List<int> numbers)
        {
            Divide(numbers, 0, numbers.Count - 1);
            return numbers;
        }

        public static void Merge(List<int> numbers, int left, int mid, int right) 
        {
            List<int> leftPartition = new List<int>();
            List<int> rightPartition = new List<int>();

            for(int i = left; i <= mid; i++)
            {
                leftPartition.Add(numbers[i]);
            }

            for(int i = mid + 1; i <= right; i++)
            {
                rightPartition.Add(numbers[i]);
            }

            int l = 0, r = 0;
            int size1 = leftPartition.Count, size2 = rightPartition.Count;

            for(int i = left; i <= right; i++)
            {
                if((l < size1 && r >= size2) || (l < size1 && r < size2 && leftPartition[l] < rightPartition[r]))
                {
                    numbers[i] = leftPartition[l++];
                }
                else
                {
                    numbers[i] = rightPartition[r++];
                }
            }
        }

        public static void Divide(List<int> numbers, int left, int right)
        {
            if(left < right)
            {
                int mid = (left + right) / 2;

                Divide(numbers, left, mid);
                Divide(numbers, mid + 1, right);

                Merge(numbers, left, mid, right);
            }
        }

        public static void Main()
        {
            List<int> numbers = new List<int> { 9, 1, -1, 10, 12, 2, 0, 0, -2, -9 , 107};
            List<int> answer = Sort(numbers);

            Console.WriteLine(string.Join(", ", answer));
        }
    }
}
