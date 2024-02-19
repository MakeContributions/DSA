using Algorithms.Search;
using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Algorithms.Tests.Search
{
    [TestFixture]
    public class InterpolationSearchTest
    {
        [TestCase(new int[]{ 1, 2, 3, 4, 5, 6, 7}, 3)]
        public void InterpolationSearch_GetIndexOfItem(int[] input, int item)
        {          
            var expected1 = InterpolationSearch.Search(input, item);       
            Assert.AreEqual(expected1, 2);
        }

        [TestCase(new int[] { 10, 21, 34, 46, 57, 68 }, 40)]
        public void InterpolationSearch_ItemNotFound(int[] input, int item)
        {
            var expected = InterpolationSearch.Search(input, item);
            Assert.AreEqual(expected, -1);
        }
    }
}
