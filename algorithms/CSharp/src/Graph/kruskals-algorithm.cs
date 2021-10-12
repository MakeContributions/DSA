using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Algorithms.Graph
{
    public class KruskalsAlgorithm
    {
        public class DisjointSetUnion
        {
            private int[] parent, rank;
            public DisjointSetUnion(int totalNodes)
            {
                rank = Enumerable.Repeat(1, totalNodes + 1).ToArray();
                parent = Enumerable.Range(0, totalNodes + 1).ToArray();
            }

            public void Union(int nodeA, int nodeB)
            {
                int parentA = Find(nodeA);
                int parentB = Find(nodeB);

                if(rank[parentA] > rank[parentB])
                {
                    parent[parentB] = parentA;
                    rank[parentA] += rank[parentB];
                }
                else
                {
                    parent[parentA] = parentB;
                    rank[parentB] += rank[parentA];
                }
            }

            public int Find(int node)
            {
                if(parent[node] == node)
                {
                    return node;
                }

                return parent[node] = Find(parent[node]);
            }
        }

        public class Graph
        {
            private DisjointSetUnion _nodesTaken;
            private List<Tuple<int, int, int>> edges;
            public Graph(int totalNodes)
            {
                _nodesTaken = new DisjointSetUnion(totalNodes);
                edges = new List<Tuple<int, int, int>>();
            }

            public void AddEdge(int source, int destination, int weight) =>
                edges.Add(new Tuple<int, int, int>(source, destination, weight));
         

            public List<Tuple<int, int, int>> GetMST()
            {
                edges = (from edge in edges
                         orderby edge.Item3
                         select edge).ToList();

                List<Tuple<int, int, int>> results = new List<Tuple<int, int, int>>();
                foreach(var edge in edges)
                {
                    if(_nodesTaken.Find(edge.Item1) != _nodesTaken.Find(edge.Item2))
                    {
                        _nodesTaken.Union(edge.Item1, edge.Item2);
                        results.Add(new Tuple<int, int, int>(edge.Item1, edge.Item2, edge.Item3));
                    }
                }

                return results;
            }
        }

        public static Object KruskalDriver(int totalNodes, List<Tuple<int, int, int>> edges)
        {
            Graph graph = new Graph(totalNodes);

            foreach(var edge in edges)
            {
                graph.AddEdge(edge.Item1, edge.Item2, edge.Item3);
            }

            var results = graph.GetMST();
            int totalWeight = 0;

            foreach(var edge in results)
            {
                totalWeight += edge.Item3;
            }

            Object ret = new {
                weight = totalWeight,
                edges = results
            };

            return ret;
        }

        public static void Main()
        {
            List<Tuple<int, int, int>> edges = new List<Tuple<int, int, int>>()
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
            };

            var result = KruskalDriver(9, edges);
            var propertyInfo = result.GetType().GetProperty("weight");
            var weight = propertyInfo.GetValue(result, null);
            Console.WriteLine(weight);
        }
    }
}
