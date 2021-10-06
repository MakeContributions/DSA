using NUnit.Framework;
using System;
using System.Collections.Generic;

namespace Algorithms.Tests.Graph
{
    [TestFixture]
    public class FloydWarshallAlgorithm
    {
        static object[] TestCasesForAllPaiShortestPath =
        {
            new object[]
            {
                4,
                true,
                new List<Tuple<int, int, int>>()
                {
                    new Tuple<int, int, int>(1, 4, 10),
                    new Tuple<int, int, int>(1, 2, 5),
                    new Tuple<int, int, int>(2, 3, 3),
                    new Tuple<int, int, int>(3, 4, 1)
                },
                "0 5 8 9 INF 0 3 4 INF INF 0 1 INF INF INF 0"
            },

            new object[]
            {
                4,
                false,
                new List<Tuple<int, int, int>>()
                {
                    new Tuple<int, int, int>(1, 4, 10),
                    new Tuple<int, int, int>(1, 2, 5),
                    new Tuple<int, int, int>(2, 3, 3),
                    new Tuple<int, int, int>(3, 4, 1)
                },
                "0 5 8 9 5 0 3 4 8 3 0 1 9 4 1 0"
            },
        };

        [TestCaseSource(nameof(TestCasesForAllPaiShortestPath))]
        public void TestFloydWarshallAlgorithm_ShouldGetExpectedResult(int totalNode, bool isDirected, List<Tuple<int, int, int>> edges, string expected)
        {
            var results = Algorithms.Graph.FloydWarshallAlgorithm.AllPairShortestPath(totalNode, isDirected, edges);
            string distances = "";
            const int INFINITY = (int)1e9;

            for (int i = 1; i <= totalNode; i++)
            {
                for (int j = 1; j <= totalNode; j++)
                {
                    if (!(i == 1 && j == 1))
                    {
                        distances += " ";
                    }

                    distances += results[i, j] >= INFINITY ? "INF" : results[i, j].ToString();
                }
            }

            Assert.AreEqual(expected, distances);
        }
    }
}
