using NUnit.Framework;

namespace Algorithms.Tests.Maths
{
    [TestFixture]
    internal class Checker
    {
        [TestCase(1, true)]
        [TestCase(3, true)]
        [TestCase(4, false)]
        [TestCase(34, true)]
        [TestCase(70, false)]
        [TestCase(110, false)]
        public void FibonacciChecker_ShouldGetExpectedResult(int num, bool expected)
        {
            var result = Algorithms.Maths.Fibonacci.Checker(num);
            Assert.AreEqual(expected, result);
        }
    }
}
