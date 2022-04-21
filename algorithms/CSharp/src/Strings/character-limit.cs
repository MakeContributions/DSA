using System;
using System.Linq;

//Time Complexity: O(N)
namespace Algorithms.Strings
{
    public class TextHelper
    {
        public static void Main()
        {
            Console.WriteLine("Please enter a string");
            string input = Console.ReadLine();

            while (input == "")
            {
                Console.WriteLine("Please enter a string");
                input = Console.ReadLine();
            }

            Console.WriteLine("Please enter the number of characters you want to show");
            string input2 = Console.ReadLine();

            while (!input2.All(char.IsDigit) || input2.All(char.IsWhiteSpace))
            {
                Console.WriteLine("The number you have entered is invalid. Please try again:");
                input2 = Console.ReadLine();
            }

            int num = Convert.ToInt32(input2);
            Console.WriteLine(CharacterLimit(input, num));
        }

        //Limits the the amount of characters shown in a string.
        public static string CharacterLimit(string input, int num)
        {
            //converts a string to a character array
            char[] ch = input.ToCharArray();

            //loops through the array from the last element to the first, and replaces each element with a "."
            for (int i = ch.Count(); i > num; i--)
            {
                ch[i - 1] = '.';
            }

            //converts character array back to string to be returned by the method
            string output = new string(ch);
            return output;
        }
    }
}