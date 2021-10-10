using NUnit.Framework;

namespace Algorithms.Tests.NumberTheory
{
    [TestFixture]
    public class BigMod
    {
        [TestCase(4, 5, 3, 1)]
        [TestCase(100001, 122, 13, 12)]
        [TestCase(10000, 1000, 118, 36)]
        [TestCase(333, 31, 17, 12)]
        [TestCase(411, 56, 107, 9)]
        [TestCase(100000, 0, 100, 1)]
        [TestCase(99999999, 99999, 13, 5)]
        public void BigMod_ShouldReturnExpectedResult(long a, long p, long m, long expected)
        {
            long result = Algorithms.NumberTheory.BigMod.Mod(a, p, m);
            Assert.AreEqual(expected, result);
        }
    }
}
