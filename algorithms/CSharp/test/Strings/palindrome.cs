using NUnit.Framework;

namespace Algorithms.CSharp.Test.Strings
{
    [TestFixture]
    internal class Palindrome
    {
        [TestCase("abba", true)]
        [TestCase("abbccbbA", true)]
        [TestCase("Mr. Owl ate my metal worm", true)]
        [TestCase("asdfgasdfg", false)]
        public void PassString_ShouldGetExpectedResult(string text, bool expected)
        {
            var result = Algorithms.Strings.Palindrome.IsPalindrome(text);
            Assert.AreEqual(expected, result);
        }
    }
}