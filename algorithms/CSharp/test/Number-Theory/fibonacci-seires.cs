using System.Collections.Generic;
using NUnit.Framework;

namespace Algorithms.Tests.Number_Theory {
    [TestFixture]
    public class fibonacci_seires {
        
        [TestCase(34, 0, 1, 1, 2, 3, 5, 8, 13, 21, 34)]
        
  
        
        
        public void CalculateFibonacciSeriesTest(int value, int[] expected) {
            var result = Algorithms.Maths.fibonacci_series.FibonacciSeries(value);
            Assert.AreEqual(expected, result);
        }

    }
}