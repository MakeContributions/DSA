using System;

namespace Algorithms.NumberTheory
{
    public class BigMod
    {
        // (a ^ p) % m
        public static long Mod(long a, long p, long m)
        {
            if(p == 0)
            {
                return 1;
            }
            if(p % 2 == 1)
            {
               return ((a % m) * Mod(a, p - 1, m)) % m;
            }

            long temp = Mod(a, p / 2, m);
            return (temp * temp) % m;
        }

        public static void Main()
        {
            Console.WriteLine($"{Mod(4, 5, 3)}");
        }
    }
}
