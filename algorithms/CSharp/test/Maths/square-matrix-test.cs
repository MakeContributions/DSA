using NUnit.Framework;
using System.Collections.Generic;

namespace Algorithms.Tests.Maths
{
    [TestFixture]
    class Matrix
    {
        static object[] TestCasesForDiagonalDifference =
        {
            new object[]
            {
                new List<List<int>> { new List<int> { 1, 2, 3 }, new List<int> { 4, 5, 6 }, new List<int> { 7, 8, 9 } },
                0
            },
            new object[]
            {
                new List<List<int>> { new List<int> { -1, -2, -3 }, new List<int> { -4, -5, -6 }, new List<int> { -7, -8, -9 } },
                0
            },
            new object[]
            {
                new List<List<int>> { new List<int> { 1, -2, 3 }, new List<int> { -4, 5, -6 }, new List<int> { 7, -8, 9 } },
                12
            },
            new object[]
            {
                new List<List<int>> { new List<int> { 1 }, new List<int> { 2 } },
                0
            },
            new object[]
            {
                new List<List<int>> { },
                0
            }
        };

        [TestCaseSource(nameof(TestCasesForDiagonalDifference))]
        public void TestDiagonalDifference_ShouldGetExpectedResult(List<List<int>> arr, int expected)
        {
            int result = Algorithms.Maths.Matrix.diagonalDifference(arr);
            Assert.AreEqual(expected, result);
        }
    }
}
