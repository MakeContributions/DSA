using NUnit.Framework;
using System.Collections.Generic;

namespace Algorithms.Tests.Number_Theory
{
    [TestFixture]
    public class BitwiseSieveOfEratosthenes
    {
        [TestCase(10, "2, 3, 5, 7")]
        [TestCase(25, "2, 3, 5, 7, 11, 13, 17, 19, 23")]
        [TestCase(100, "2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97")]
        public void BitwiseSieveOfEratosthenes_ShouldReturnExpected(int max, string expected)
        {
            List<int> primeNumbers = Algorithms.NumberTheory.BitwiseSieveOfEratosthenes.GeneratePrimeNumbers(max);
            Assert.AreEqual(expected, string.Join(", ", primeNumbers));
        }
    }
}
