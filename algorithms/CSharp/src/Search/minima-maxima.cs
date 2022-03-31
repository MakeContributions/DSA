using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

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

            var lmins = GetLocalMinima(numbers);
            var lmaxs = GetLocalMaxima(numbers);

            foreach (var n in lmins)
                Console.WriteLine($"Local Minima: {n}");

            foreach (var n in lmaxs)
                Console.WriteLine($"Local Maxima: {n}");
        }

        public static List<int> GetLocalMinima(List<int> numbers)
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
                    result.Add(numbers[0]);

                //Loop middle elements
                for (int i = 1; i < numbers.Count - 1; i++)
                    if (numbers[i - 1] >= numbers[i] && numbers[i] <= numbers[i + 1])
                        result.Add(numbers[i]);

                //Check last elements
                if (numbers[^1] < numbers[^2])
                    result.Add(numbers[^1]);
            }

            return result;
        }

        public static List<int> GetLocalMaxima(List<int> numbers)
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
                    result.Add(numbers[0]);

                //Loop middle elements
                for (int i = 1; i < numbers.Count - 1; i++)
                    if (numbers[i - 1] <= numbers[i] && numbers[i] >= numbers[i + 1])
                        result.Add(numbers[i]);

                //Check last elements
                if (numbers[^1] > numbers[^2])
                    result.Add(numbers[^1]);
            }

            return result;
        }
    }
}
