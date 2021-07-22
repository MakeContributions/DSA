using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using Algorithms.Search;

namespace Algorithms.Tests.Search
{
    [TestFixture]
    class LinearSearchTest
    {
        int[] numbers = { 1, 2, 3, 4, 5 };

        [Test]
        [TestCase(4, 3)]
        [TestCase(5, 4)]
        public void Should_Return_Index_Of_Matching_Element_In_Array(int searchNumber, int expectedIndexOfSearchTerm)
        {
            int actualIndexOfSearchTerm = LinearSearch.Search(numbers, searchNumber);
            Assert.AreEqual(expectedIndexOfSearchTerm, actualIndexOfSearchTerm);
        }

        [Test]
        [TestCase(6)]
        [TestCase(0)]
        public void Should_Return_Negative_One_If_No_Matching_Element_Exists(int searchNumber)
        {
            int actualIndexOfSearchTerm = LinearSearch.Search(numbers, searchNumber);
            Assert.AreEqual(-1, actualIndexOfSearchTerm);
        }
    }
}
