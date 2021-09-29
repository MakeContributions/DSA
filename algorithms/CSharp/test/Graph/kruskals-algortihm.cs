using System;
using NUnit.Framework;
using System.Collections.Generic;

namespace Algorithms.Tests.Graph
{
    [TestFixture]
    class KruskalsAlgortihm
    {
        static Object[] TestCasesForKruskalsAlgorithm =
        {
            new object[]
            {
                9,
                new List<Tuple<int, int, int>>()
                {
                    new Tuple<int, int, int>(1, 2, 4),
                    new Tuple<int, int, int>(1, 8, 8),
                    new Tuple<int, int, int>(2, 8, 11),
                    new Tuple<int, int, int>(2, 3, 8),
                    new Tuple<int, int, int>(3, 9, 2),
                    new Tuple<int, int, int>(8, 9, 7),
                    new Tuple<int, int, int>(8, 7, 1),
                    new Tuple<int, int, int>(7, 9, 6),
                    new Tuple<int, int, int>(3, 4, 7),
                    new Tuple<int, int, int>(3, 6, 4),
                    new Tuple<int, int, int>(6, 7, 2),
                    new Tuple<int, int, int>(4, 6, 14),
                    new Tuple<int, int, int>(4, 5, 9),
                    new Tuple<int, int, int>(5, 6, 10)
                },
                37
            },

            new object[]
            {
                4,
                new List<Tuple<int, int, int>>()
                {
                    new Tuple<int, int, int>(1, 2, 4),
                    new Tuple<int, int, int>(1, 3, 1),
                    new Tuple<int, int, int>(1, 4, 2),
                    new Tuple<int, int, int>(2, 3, 6),
                    new Tuple<int, int, int>(2, 4, 1),
                    new Tuple<int, int, int>(3, 4, 7)
                },
                4
            }
        };

        [TestCaseSource(nameof(TestCasesForKruskalsAlgorithm))]
        public void TestKruskal_ShouldGetExpectedResult(int totalNodes, List<Tuple<int, int, int>> edges, int expected)
        {
            var result = Algorithms.Graph.KruskalsAlgorithm.KruskalDriver(totalNodes, edges);
            var propertyInfo = result.GetType().GetProperty("weight");
            var weight = propertyInfo.GetValue(result, null);

            Assert.AreEqual(expected, weight);
        }
    }
}
