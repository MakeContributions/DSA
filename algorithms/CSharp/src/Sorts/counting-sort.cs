using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Algorithms.Sorts
{
    public class CountingSort
    {
        public static List<int> Sort(List<int> numbers)
        {
            int maxNumber = 0, minNumber = 0;
            foreach(int number in numbers)
            {
                maxNumber = number > maxNumber ? number : maxNumber;
                minNumber = number < minNumber ? number : minNumber;
            }

            int[] mx = Enumerable.Repeat(0, maxNumber + 1).ToArray();
            int[] mn = Enumerable.Repeat(0, minNumber * -1 + 1).ToArray();

            foreach(int number in numbers)
            {
                if(number >= 0)
                {
                    mx[number]++;
                }

                else
                {
                    mn[number * -1]++;
                }
            }

            List<int> sortedList = new List<int>();

            if(minNumber < 0)
            {
                for (int i = minNumber; i < 0; i++)
                {
                    while(mn[i * -1] > 0)
                    {
                        sortedList.Add(i);
                        mn[i * -1]--;
                    }
                }
            }

            for(int i = 0; i <= maxNumber; i++)
            {
                while(mx[i] > 0)
                {
                    sortedList.Add(i);
                    mx[i]--;
                }
            }

            return sortedList;
        }

        public static void Main()
        {
            List<int> numbers = new List<int> { 9, 1, -1, 10, 12, 2, 0, 0, -2, -9 };
            List<int> answer = Sort(numbers);

            Console.WriteLine(string.Join(", ", answer));
        }
    }
}
