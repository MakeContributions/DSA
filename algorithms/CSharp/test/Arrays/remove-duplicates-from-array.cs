using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Algorithms.Tests.Arrays
{
    [TestFixture]
    class remove_duplicates_from_array
    {
        static object[] TestCasesForRemoveDuplicatesFromArray =
       {
            new object[]
            {
                new int[] { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4},
                new int[] { 0, 1, 2, 3, 4 }
            },
            new object[]
            {
                new int[] { 1, 1, 2},
                new int[] { 1, 2}
            },
        };

        [TestCaseSource(nameof(TestCasesForRemoveDuplicatesFromArray))]
        public void TestSingleNumber_ShouldGetExpectedResult(int[] numbers, int[] expected)
        {
            int i = Algorithms.Arrays.RemoveDuplicatesFromArray.RemoveDuplicates(numbers);

            int[] result = numbers
                .ToList()
                .Take(i)
                .ToArray();

            Assert.AreEqual(expected, result);
        }
    }
}
