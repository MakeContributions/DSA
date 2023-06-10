using NUnit.Framework;

namespace Algorithms.Tests.Recursion
{
    [TestFixture]
    public class SumOfDigitsOfANumberTest
    {
        [TestCase(0, 1)]
        [TestCase(571, 13)]
        [TestCase(13, 4)]
        [TestCase(1, 1)]
        public void TestSumOfDigitsOfANumber_ShouldGetExpectedResult(int number, int expected)
        {
            int result = Algorithms.Recursion.SumOfDigitsOfANumber.SumDigits(number);
            Assert.AreEqual(expected, result);
        }
    }
}