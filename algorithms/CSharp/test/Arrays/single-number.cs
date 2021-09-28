using NUnit.Framework;
using System.Collections.Generic;

namespace Algorithms.Tests.Arrays
{
    [TestFixture]
    class SingleNumber
    {
        static object[] TestCasesForSingleNumber =
        {
            new object[]
            {
                new List<int> { 7, 2, 2, 1, 3, 7, 3},
                1
            },
            new object[]
            {
                new List<int> { 118 },
                118
            },
            new object[]
            {
                new List<int> { 11, 12, 13, 14, 13, 12, 11},
                14
            }
        };

        [TestCaseSource(nameof(TestCasesForSingleNumber))]
        public void TestSingleNumber_ShouldGetExpectedResult(List<int> numbers, int expected)
        {
            int result = Algorithms.Arrays.SingleNumber.DetermineSingleNumber(numbers);
            Assert.AreEqual(expected, result);
        }
    }
}
