using NUnit.Framework;

namespace Algorithms.Tests.Recursion
{
    [TestFixture]
    public class ArraySumTest
    {
        [TestCase(new int[] {1,3,5,7,8,4}, 28)]
        [TestCase(new int[] {1,3,5,1,-20,1}, -9)]
        [TestCase(new int[] {1,3}, 4)]
        [TestCase(new int[] {1,-2,5,-6,2}, 0)]
        public void TestArraySum_ShouldGetExpectedResult(int[] numbers, int expected)
        {
            int result = Algorithms.Recursion.ArraySum.SumUsingRecursion(numbers, 0);
            Assert.AreEqual(expected, result);
        }
    }
}
