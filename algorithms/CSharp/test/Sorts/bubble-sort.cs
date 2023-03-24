using NUnit.Framework;
using System;
using Algorithms.Sorts;

namespace algorithms.CSharp.Test.Sorts
{
    [TestFixture]
    internal class BubbleSortTests
    {
        private BubbleSort _sut = new BubbleSort();
        private int[] _unsortedArray;

        [SetUp]
        public void SetUp()
        { 
            _unsortedArray = new int[200];
            var rand = new Random(1);
            var maxInt = 12345;
            var minInt = -12345;
            for (int i = 0; i < _unsortedArray.Length; i++)
            {
                _unsortedArray[i] = rand.Next(minInt, maxInt + 1);
            }
        }

        [Test]
        public void Sort_UnorderedIntArray_ReturnsOrderedArray()
        {
            int[] sortedArray = _sut.Sort(_unsortedArray);
            for (int i = 0; i < sortedArray.Length-1; i++)
            {
                Assert.That(sortedArray[i], Is.AtMost(sortedArray[i + 1]));
            }
        }

        [Test]
        public void Sort_OutputArray_IsEqualLengthToInputArray()
        {
            int[] sortedArray = _sut.Sort(_unsortedArray);
            Assert.That(sortedArray.Length, Is.EqualTo(_unsortedArray.Length));
        }
    }
}