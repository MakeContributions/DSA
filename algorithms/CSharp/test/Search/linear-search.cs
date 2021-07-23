using NUnit.Framework;
using Algorithms.Search;

namespace Algorithms.Tests.Search
{
    [TestFixture]
    class LinearSearchTest
    {
        int[] numbers = { 1, 2, 3, 4, 5 };

        [TestCase(4, 3)]
        [TestCase(5, 4)]
        public void GivenASearchNumber_ShouldGetMatchingIndexInList(int searchNumber, int expectedIndexOfSearchTerm)
        {
            int actualIndexOfSearchTerm = LinearSearch.Search(numbers, searchNumber);
            Assert.AreEqual(expectedIndexOfSearchTerm, actualIndexOfSearchTerm);
        }

        [TestCase(6)]
        [TestCase(0)]
        public void GivenASearchNumberNotInTheList_ShouldReturnNegativeOne(int searchNumber)
        {
            int actualIndexOfSearchTerm = LinearSearch.Search(numbers, searchNumber);
            Assert.AreEqual(-1, actualIndexOfSearchTerm);
        }
    }
}
