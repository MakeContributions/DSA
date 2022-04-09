using System;
using System.Collections.Generic;
using System.Linq;

namespace Algorithms.Search
{
    public class MinimaMaxima
    {
        public static void Main()
        {
            var numbers = new List<int>
            {
                3,1,2,5,6,7,4,6,9,10
            };

            var minimas = FindMinimas(numbers);
            var maximas = FindMaximas(numbers);

            foreach (var minima in minimas)
            {
                Console.WriteLine($"Local Minima: {minima}");
            }

            foreach (var maxima in maximas)
            {
                Console.WriteLine($"Local Maxima: {maxima}");
            }
        }

        public static List<int> FindMinimas(List<int> numbers)
        {
            var result = new List<int>();

            if (numbers.Count < 3)
            {
                result.Add(numbers.Min());
            }
            else
            {
                // Check first element
                if (numbers[0] < numbers[1])
                {
                    result.Add(numbers[0]);
                }

                //Loop middle elements
                for (int i = 1; i < numbers.Count - 1; i++)
                {
                    if (numbers[i - 1] >= numbers[i] && numbers[i] <= numbers[i + 1])
                    {
                        result.Add(numbers[i]);
                    }
                }

                //Check last elements
                if (numbers[^1] < numbers[^2])
                {
                    result.Add(numbers[^1]);
                }
            }

            return result;
        }

        public static List<int> FindMaximas(List<int> numbers)
        {
            var result = new List<int>();

            if (numbers.Count < 3)
            {
                result.Add(numbers.Max());
            }
            else
            {
                // Check first element
                if (numbers[0] > numbers[1])
                {
                    result.Add(numbers[0]);
                }
                    
                //Loop middle elements
                for (int i = 1; i < numbers.Count - 1; i++)
                {
                    if (numbers[i - 1] <= numbers[i] && numbers[i] >= numbers[i + 1])
                    {
                        result.Add(numbers[i]);
                    }
                }

                //Check last elements
                if (numbers[^1] > numbers[^2])
                {
                    result.Add(numbers[^1]);
                }
            }

            return result;
        }
    }
}
