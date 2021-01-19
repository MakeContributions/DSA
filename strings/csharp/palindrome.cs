using System;
using System.Linq;
					
public class Program
{
	public static void Main()
	{
		bool result = false;
		result = IsPalindrome("abba");
		Console.WriteLine(result);
		result = IsPalindrome("abbccbba");
		Console.WriteLine(result);
	}
	
	private static bool IsPalindrome(string source) {
		string reverse = new string(Enumerable.Range(1, source.Length).Select(i => source[source.Length - i]).ToArray());
		return reverse == source;
	}
}