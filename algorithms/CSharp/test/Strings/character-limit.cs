using NUnit.Framework;

namespace Algorithms.CSharp.Test.Strings
{
    [TestFixture]
    internal class Character_Limit
    {
        [TestCase("Hello", "Hel..")]
        [TestCase("World", "Wor..")]
        [TestCase("How Ya", "How...")]
        [TestCase("Doin", "Doi.")]
        public void PassString_ShouldGetExpectedResult(string text, string expected)
        {
            string result = Algorithms.Strings.TextHelper.CharacterLimit(text, 3);
            Assert.AreEqual(expected, result);
        }
    }
}