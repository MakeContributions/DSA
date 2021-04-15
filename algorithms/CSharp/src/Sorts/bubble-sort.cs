using System;

namespace Algorithms.Sorts
{
    public class BubbleSort
    {
        public static void Main()
        {
            int[] arr = { 800, 11, 50, 771, 649, 770, 240, 9 };
            Sort(arr);
            var result = string.Join(" ", arr);
            Console.WriteLine(result);
        }

        public static void Sort(int[] source)
        {
            for (int write = 0; write < source.Length; write++)
            {
                for (int sort = 0; sort < source.Length - 1; sort++)
                {
                    if (source[sort] > source[sort + 1])
                    {
                        var temp = source[sort + 1];
                        source[sort + 1] = source[sort];
                        source[sort] = temp;
                    }
                }
            }
        }
    }
}