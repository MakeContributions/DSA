using NUnit.Framework;
using System.Collections.Generic;

namespace Algorithms.Tests.NumberTheory
{
    [TestFixture]
    public class SieveOfEratosthenes
    {
        [TestCase(100, "2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97")]
        public void SieveOfEratosthenes_ShouldReturnExpected(int max, string expected)
        {
            List<int> primeNumbers = Algorithms.NumberTheory.SieveOfEratosthenes.GeneratePrimeNumbers(max);
            Assert.AreEqual(expected, string.Join(", ", primeNumbers));
        }
    }
}
