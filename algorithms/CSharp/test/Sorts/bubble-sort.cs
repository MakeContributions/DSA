using NUnit.Framework;

namespace algorithms.CSharp.Test.Sorts
{
    [TestFixture]
    internal class BubbleSort
    {
        [Test]
        public void SortTheArray_ShouldGetExpectedString()
        {
            int[] array = { 800, 11, 50, 771, 649, 770, 240, 9 };
            Algorithms.Sorts.BubbleSort.Sort(array);
            var result = string.Join(" ", array);
            Assert.AreEqual("9 11 50 240 649 770 771 800", result);
        }
    }
}