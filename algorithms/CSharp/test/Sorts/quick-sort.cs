using NUnit.Framework;

namespace Algorithms.Tests.Sorts
{
    [TestFixture]
    public class QuickSort
    {
        static readonly object[] TestCasesForQuickSort =
        {
            new object[] {
                new int[] { 0, 19, 12, 22, 107, 118, 0, 1, 2},
                "0, 0, 1, 2, 12, 19, 22, 107, 118"
            },

            new object[] {
                new int[] { 10, 11, 19, 0, -1, -19, -12, 1, 2, 1, 16, -100},
                "-100, -19, -12, -1, 0, 1, 1, 2, 10, 11, 16, 19"
            },

            new object[] {
                new int[] { -1, -2, -3, -4, -5, -10},
                "-10, -5, -4, -3, -2, -1"
            },

            new object[] {
                new int[] { -1 },
                "-1"
            }
        };

        [TestCaseSource(nameof(TestCasesForQuickSort))]
        public void TestQuickSort_ShouldGetExpected(int[] array, string expected)
        {
            var results = Algorithms.Sorts.QuickSort.Sort(array, 0, array.Length - 1);

            Assert.That(expected, Is.EqualTo(string.Join(", ", results)));
        }
    }
}
