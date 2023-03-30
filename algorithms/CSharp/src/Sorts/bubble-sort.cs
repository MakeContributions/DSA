using System;

namespace Algorithms.Sorts
{
    public class BubbleSort
    {
        public static void Main()
        {
            int[] unsortedArray = GenerateRandomUnsortedArray();
            int[] sortedArray = Sort(unsortedArray);
            var result = string.Join(" ", sortedArray);
            Console.WriteLine(result);
        }

        public static int[] GenerateRandomUnsortedArray(int arrayLength = 200, int maxValue = 12345, int minValue = -12345)
        {
            int[] unsortedArray = new int[arrayLength];
            var rand = new Random();
            for (int i = 0; i < unsortedArray.Length; i++)
            {
                unsortedArray[i] = rand.Next(minValue, maxValue + 1);
            }

            return unsortedArray;
        }

        public static int[] Sort(int[] inputArray)
        {
            int[] sortedArray = new int[inputArray.Length];
            Array.Copy(inputArray, sortedArray, inputArray.Length);
            bool isSwapRequired;
            for (int i = 0; i < sortedArray.Length; i++)
            {
                isSwapRequired = false;
                for (int sortIdx = 0; sortIdx < sortedArray.Length - 1; sortIdx++)
                {
                    if (sortedArray[sortIdx] > sortedArray[sortIdx + 1])
                    {
                        var temp = sortedArray[sortIdx + 1];
                        sortedArray[sortIdx + 1] = sortedArray[sortIdx];
                        sortedArray[sortIdx] = temp;
                        isSwapRequired = true;
                    }
                }

                if (!isSwapRequired)
                {
                    break;
                }
            }

            return sortedArray;
        }
    }
}