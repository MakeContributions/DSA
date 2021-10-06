using System;
using System.Collections.Generic;
using System.Linq;

namespace Algorithms.NumberTheory
{
    public class BitwiseSieveOfEratosthenes
    {
        public static bool CheckBit(int number, int position) =>
            (number & (1 << position)) != 0;

        public static int SetBit(int number, int position) =>
            number | (1 << position);

        public static List<int> GeneratePrimeNumbers(int max)
        {
            int[] status = Enumerable.Repeat(0, max / 32 + 1).ToArray();
            int squareRoot = (int)Math.Sqrt(max * 1.0);

            for(int i = 3; i <= squareRoot; i += 2)
            {
                if(!CheckBit(status[i / 32], i % 32))
                {
                    for(int j = 2 * i; j <= max; j += i)
                    {
                        status[j / 32] = SetBit(status[j / 32], j % 32);
                    }
                }
            }

            List<int> primeNumbers = new List<int>();
            primeNumbers.Add(2);

            for(int i = 3; i <= max; i += 2)
            {
                if(!CheckBit(status[i / 32], i % 32))
                {
                    primeNumbers.Add(i);
                }
            }

            return primeNumbers;
        }

        public static void Main()
        {
            List<int> primeNumbers = GeneratePrimeNumbers(100);
            Console.WriteLine(string.Join(", ", primeNumbers));
        }
    }
}

/*
 * Bitwise Sieve is an optimized version of the Sieve of Eratosthenes
 * Instead of keeping the status of a number in a single number, we use a bit
 * We use 32 bit integers
 * e.g: 0 has the status of 0-31, 1 has the status of 32-63, etc.
 */