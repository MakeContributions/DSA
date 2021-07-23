using System;

namespace Algorithms.Search
{
    public class LinearSearch
    {
        public static void Main()
        {
            int[] numbers = { 1, 2, 3, 4, 5 };
            int searchNumber = 3;
            int indexOfSearchNumber = Search(numbers, searchNumber);

            if (indexOfSearchNumber == -1)
            {
                Console.WriteLine("The number you are searching for does not exist in this list.");
            }
            else
            {
                Console.WriteLine("The number you are searching for is at index: " + indexOfSearchNumber);
            }
        }
        public static int Search(int[] numbers, int searchNumber)
        {
            int indexOfSearchNumber = -1;

            for(int index = 0; index < numbers.Length; index++)
            {
                if (numbers[index] == searchNumber)
                {
                    indexOfSearchNumber = index;
                }
            }
            return indexOfSearchNumber; 
        }
    }
}
