using NUnit.Framework;
using System.Collections.Generic;

namespace Algorithms.Tests.Sorts
{
    [TestFixture]
    class MergeSort
    {
        static object[] TestCasesForMergeSort =
        {
            new object[] {
                new List<int>{ 0, 19, 12, 22, 107, 118, 0, 1, 2},
                "0, 0, 1, 2, 12, 19, 22, 107, 118"
            },

            new object[] {
                new List<int>{ 10, 11, 19, 0, -1, -19, -12, 1, 2, 1, 16, -100},
                "-100, -19, -12, -1, 0, 1, 1, 2, 10, 11, 16, 19"
            },

            new object[] {
                new List<int>{ -1, -2, -3, -4, -5, -10},
                "-10, -5, -4, -3, -2, -1"
            },

            new object[] { 
                new List<int>{ -1 },
                "-1"
            }
        };

        [TestCaseSource(nameof(TestCasesForMergeSort))]
        public void TestMergeSort_ShouldGetExpected(List<int> numbers, string expected)
        {
            List<int> results = Algorithms.Sorts.MergeSort.Sort(numbers);
            Assert.AreEqual(string.Join(", ", results), expected);
        }
    }
}
