using System;
using NUnit.Framework;
using System.Collections.Generic;

namespace Algorithms.Tests.Graph
{
    [TestFixture]
    public class DepthFirstSearch
    {
        static object[] DivideCasesForDFS =
        {
            new object[] { 5, 3, new List<Tuple<int, int>> {
                                 new Tuple<int, int>(1, 2),
                                 new Tuple<int, int>(1, 3),
                                 new Tuple<int, int>(2, 3),
                                 new Tuple<int, int>(4, 2),
                                 new Tuple<int, int>(1, 5)
                         }, "3 1 2 4 5"
            },
            new object[] { 5, 1, new List<Tuple<int, int>> {
                                 new Tuple<int, int>(1, 2),
                                 new Tuple<int, int>(1, 3),
                                 new Tuple<int, int>(4, 3),
                                 new Tuple<int, int>(3, 5)
                         }, "1 2 3 4 5"
            }
        };

        static object[] DivideCasesForCycleDetection =
        {
            new object[] { 5, new List<Tuple<int, int>> {
                                new Tuple<int, int>(1, 2),
                                new Tuple<int, int>(1, 3),
                                new Tuple<int, int>(2, 3),
                                new Tuple<int, int>(4, 2),
                                new Tuple<int, int>(1, 5)
                         }, true
            },
            new object[] { 5, new List<Tuple<int, int>> {
                                new Tuple<int, int>(1, 2),
                                new Tuple<int, int>(1, 3),
                                new Tuple<int, int>(4, 3),
                                new Tuple<int, int>(3, 5)
                         }, false
            }
        };


        [TestCaseSource(nameof(DivideCasesForDFS))]
        public void TestDFS_ShouldGetExpectedResult(int vertex, int source, List<Tuple<int, int>> edges, string expected)
        {
            List<int> result = Algorithms.Graph.DepthFirstSearch.DFS(vertex, source, edges);
            Assert.AreEqual(expected, string.Join(' ', result));
        }


        [TestCaseSource(nameof(DivideCasesForCycleDetection))]
        public void TestCycleDetection_ShouldGetExpectedResult(int vertex, List<Tuple<int, int>> edges, bool expected)
        {
            bool result = Algorithms.Graph.DepthFirstSearch.HasCycle(vertex, edges);
            Assert.AreEqual(expected, result);
        }
    }
}
