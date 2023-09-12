using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms.Tests.Recursion {
    
    [TestFixture]
    public class FibonacciTest {
        [TestCase(0, 0)]
        [TestCase(2, 1)]
        [TestCase(5, 5)]
        [TestCase(10, 55)]
        [TestCase(16, 987)]
        public void TestFactorial_ShouldGetExpectedResult(int number, int expected) {
            int result = Algorithms.Recursion.Factorial.FactorialUsingRecursion(number);
            Assert.AreEqual(expected, result);
        }
    }
}
