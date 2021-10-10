using System;
using NUnit.Framework;
using System.Collections.Generic;

namespace Algorithms.Tests.Graph
{
    [TestFixture]
    public class BreadthFirstSearch
    {
        static object[] DivideCasesForBFS =
        {
            new object[] { 4, true, 3, new List<Tuple<int, int>>() {
                                    new Tuple<int, int>(1, 2),
                                    new Tuple<int, int>(1, 3),
                                    new Tuple<int, int>(2, 3),
                                    new Tuple<int, int>(3, 1),
                                    new Tuple<int, int>(3, 4),
                                    new Tuple<int, int>(4, 4),
                         }, "3->1->4->2"
                        
            },
        };

        [TestCaseSource(nameof(DivideCasesForBFS))]
        public void TestDFS_ShouldGetExpectedResult(int totalNodes, bool isDirected, int source, List<Tuple<int, int>> edges, string expected)
        {
            List<int> result = Algorithms.Graph.BreadthFirstSearch.BFSDriver(totalNodes, isDirected, source, edges);
            Assert.AreEqual(expected, string.Join("->", result));
        }
    }
}
