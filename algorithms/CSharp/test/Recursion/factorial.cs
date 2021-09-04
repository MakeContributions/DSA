using NUnit.Framework;

namespace Algorithms.Tests.Recursion
{
    [TestFixture]
    public class FactorialTest
    {
        [TestCase(0, 1)]
        [TestCase(7, 5040)]
        [TestCase(3, 6)]
        [TestCase(1, 1)]
        public void TestFactorial_ShouldGetExpectedResult(int number, int expected)
        {
            int result = Algorithms.Recursion.Factorial.FactorialUsingRecursion(number);
            Assert.AreEqual(expected, result);
        }
    }
}
