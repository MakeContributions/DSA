using System;
using NUnit.Framework;
using System.Collections.Generic;

namespace Algorithms.Tests.Graph
{
    [TestFixture]
    public class Dijkstra
    {
        static object[] TestCasesForDijkstra =
        {
            new object[]
            {
                5, false, 1, 5, new List<Tuple<int, int, int>> {
                    new Tuple<int, int, int>(1, 2, 2),
                    new Tuple<int, int, int>(2, 5, 5),
                    new Tuple<int, int, int>(2, 3, 4),
                    new Tuple<int, int, int>(1, 4, 1),
                    new Tuple<int, int, int>(4, 3, 3),
                    new Tuple<int, int, int>(3, 5, 1) 
                },
                5
            },
            new object[]
            {
                5, true, 1, 5, new List<Tuple<int, int, int>> {
                    new Tuple<int, int, int>(1, 2, 2),
                    new Tuple<int, int, int>(2, 5, 8),
                    new Tuple<int, int, int>(2, 3, 4),
                    new Tuple<int, int, int>(4, 1, 1),
                    new Tuple<int, int, int>(3, 4, 3),
                    new Tuple<int, int, int>(3, 5, 1)
                },
                7
            },
            new object[]
            {
                3, false, 1, 3, new List<Tuple<int, int, int>> {
                    new Tuple<int, int, int>(1, 2, 1)
                },
                -1
            },
        };

        [TestCaseSource(nameof(TestCasesForDijkstra))]
        public void TestDijkstra_ShouldGetExpectedResult(int totalNodes, bool isDirected, int source, int destination, List<Tuple<int, int, int>> edges, int expected)
        {
            var result = Algorithms.Graph.Dijkstra.RunDijkstra(totalNodes, isDirected, source, destination, edges);
            int distance = (int)result.GetType().GetProperty("distance").GetValue(result, null);

            Assert.AreEqual(expected, distance);
        }
    }
}
