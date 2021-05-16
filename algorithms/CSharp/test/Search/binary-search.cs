using Algorithms.Search;
using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Algorithms.Tests.Search
{
    [TestFixture]
    public class BinarySearchTest
    {
        [TestCase(new int[]{ 1,2,3,4,5}, 4)]
        public void BinarySearch_GetIndexOfItem(int[] input, int item)
        {          
            var expected1 = BinarySearch.Search(input, item);       
            Assert.AreEqual(expected1, 3);
        }

        [TestCase(new int[] { 10, 21, 34, 46, 57, 68 }, 59)]
        public void BinarySearch_ItemNotFound(int[] input, int item)
        {
            var expected = BinarySearch.Search(input, item);
            Assert.AreEqual(expected, -1);
        }

        [TestCase(new int[] { 1, 2, 3, 4, 5 }, 4)]
        public void BuildInBinarySearch_GetIndexOfItem(int[] input, int item)
        {
            var expected = BinarySearch.BuiltInBinarySearch(input.ToList(), item);
            Assert.AreEqual(expected, 3);
        }
        [TestCase(new int[] { 1, 2, 3, 4, 5 }, 8)]
        public void BuildInBinarySearch_ItemNotFound(int[] input, int item)
        {
            var expected = BinarySearch.BuiltInBinarySearch(input.ToList(), item);
            Assert.AreEqual(expected, -1);
        }
    }
}
