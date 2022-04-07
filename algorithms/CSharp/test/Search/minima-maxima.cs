using Algorithms.Search;
using NUnit.Framework;
using System.Linq;

namespace Algorithms.Tests.Search
{
    [TestFixture]
    public class MinimaMaximaTest
    {

        [TestCase(new int[] { 3, 1, 2, 5, 6, 7, 4, 6, 9, 10 }, new int[] { 1, 4 })]
        public void PassIntegerList_ShouldGetExpectedMinimas(int[] input, int[] result)
        {
            var expected1 = MinimaMaxima.FindMinimas(input.ToList());
            Assert.AreEqual(expected1, result);
        }

        [TestCase(new int[] { 3, 1, 2, 5, 6, 7, 4, 6, 9, 10 }, new int[] { 3, 7, 10 })]
        public void PassIntegerList_ShouldGetExpectedMaximas(int[] input, int[] result)
        {
            var expected1 = MinimaMaxima.FindMaximas(input.ToList());
            Assert.AreEqual(expected1, result);
        }
    }
}
