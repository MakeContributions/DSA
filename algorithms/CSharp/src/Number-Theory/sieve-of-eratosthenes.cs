using System;
using System.Collections.Generic;
using System.Linq;

namespace Algorithms.NumberTheory
{
    public class SieveOfEratosthenes
    {
        // returns all the prime numbers from 1 to max
        public static List<int> GeneratePrimeNumbers(int max)
        {
            List<bool> isPrime = Enumerable.Repeat(true, max + 1).ToList();

            isPrime[0] = isPrime[1] = false;
            for(int i = 4; i <= max; i += 2)
            {
                isPrime[i] = false;
            }

            int squareRoot = (int)Math.Sqrt(max);
            for(int i = 3; i <= squareRoot; i += 2)
            {
                if(isPrime[i])
                {
                    for(int j = 2 * i; j <= max; j += i)
                    {
                        isPrime[j] = false;
                    }
                }
            }

            List<int> primeNumbers = isPrime.Select((value, index) => new { value, index })
                                            .Where(obj => obj.value == true)
                                            .Select(obj => obj.index)
                                            .ToList();

            return primeNumbers;
        }

        public static void Main()
        {
            List<int> primeNumbers = GeneratePrimeNumbers(100);
            Console.WriteLine(string.Join(", ", primeNumbers));
        }
    }
}
