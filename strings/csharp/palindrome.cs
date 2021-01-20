using System;
using System.Linq;
using System.Text.RegularExpressions;
                    
public class Program
{
    public static void Main()
    {
        bool result = false;
        result = IsPalindrome("abba");
        Console.WriteLine(result);
        result = IsPalindrome("abbccbbA");
        Console.WriteLine(result);
        result = IsPalindrome("Mr. Owl ate my metal worm");
        Console.WriteLine(result);
    }
    
    private static bool IsPalindrome(string source) {
        source = source.ToLower();
        source = Regex.Replace(source, @"[^0-9A-Za-z]", "");
        string reverse = new string(Enumerable.Range(1, source.Length).Select(i => source[source.Length - i]).ToArray());
        return reverse == source;
    }
}