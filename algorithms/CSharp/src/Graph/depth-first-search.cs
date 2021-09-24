using System;
using System.Collections.Generic;
using System.Linq;

namespace Algorithms.Graph
{
    public class DepthFirstSearch
    {
        class Graph
        {
            private int _vertex;
            private bool _cycleFound;
            private List<List<int>> _adjacencyList;
            private List<int> _parent;
            private List<int> _visited;
            private List<int> _traversal;

            public const int WHITE = 0;
            public const int GREY = 1;
            public const int BLACK = 2;

            public Graph(int vertex)
            {
                _vertex = vertex;
                _traversal = new List<int>();
                _adjacencyList = new List<List<int>>(vertex + 1);

                for (int i = 0; i <= vertex; i++)
                {
                    _adjacencyList.Add(new List<int>());
                }
            }

            public void AddEdge(int start, int end)
            {
                _adjacencyList[start].Add(end);
            }

            public List<int> DFS(int source)
            {
                _parent = Enumerable.Repeat(-1, _vertex + 1).ToList();
                _visited = Enumerable.Repeat(WHITE, _vertex + 1).ToList();
                _traversal.Clear();

                DFSRecursive(source);
                return _traversal;
            }


            public bool HasCycle()
            {
                _parent = Enumerable.Repeat(-1, _vertex + 1).ToList();
                _visited = Enumerable.Repeat(WHITE, _vertex + 1).ToList();
                _traversal.Clear();

                DFSRecursive(1);
                return _cycleFound;
            }

            private void DFSRecursive(int source)
            {
                _visited[source] = GREY;
                _traversal.Add(source);

                foreach (int destination in _adjacencyList[source])
                {
                    if (_visited[destination] == WHITE)
                    {
                        _parent[destination] = source;
                        DFSRecursive(destination);
                    }

                    else if (_visited[destination] == GREY && destination != _parent[source])
                    {
                        _cycleFound = true;
                    }
                }

                _visited[source] = BLACK;
            }

        }


        public static List<int> DFS(int vertex, int src, List<Tuple<int, int>> edges)
        {
            Graph graph = new Graph(vertex);
            foreach (var edge in edges)
            {
                graph.AddEdge(edge.Item1, edge.Item2);
                graph.AddEdge(edge.Item2, edge.Item1);
            }

            return graph.DFS(src);
        }

        public static bool HasCycle(int vertex, List<Tuple<int, int>> edges)
        {
            Graph graph = new Graph(vertex);
            foreach (var edge in edges)
            {
                graph.AddEdge(edge.Item1, edge.Item2);
                graph.AddEdge(edge.Item2, edge.Item1);
            }

            return graph.HasCycle();
        }

        public static void Main()
        {
            List<Tuple<int, int>> edges = new List<Tuple<int, int>>();
            edges.Add(new Tuple<int, int>(1, 2));
            edges.Add(new Tuple<int, int>(1, 3));
            edges.Add(new Tuple<int, int>(4, 3));
            edges.Add(new Tuple<int, int>(3, 5));

            List<int> traversal = DFS(5, 1, edges);
            foreach (int v in traversal)
            {
                Console.Write($"{v} ");
            }

            Console.WriteLine($"Has Cycle: {HasCycle(5, edges)}");
        }
    }
}

/*
 * depth first search for an undirected graph
 * also cycles are detected
 */