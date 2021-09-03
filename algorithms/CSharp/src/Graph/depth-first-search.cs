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
            private bool _isCycle;
            private List<List<int>> _adjacencyList;
            private List<int> _parent;
            private List<int> _visited;
            private List<int> _traversal;

            public const int WHITE = 0;
            public const int BROWN = 1;
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

            private void DFSRecursive(int source)
            {
                _visited[source] = BROWN;
                _traversal.Add(source);

                foreach (int destination in _adjacencyList[source])
                {
                    if (_visited[destination] == WHITE)
                    {
                        _parent[destination] = source;
                        DFSRecursive(destination);
                    }
                }

                _visited[source] = BLACK;
            }
        }


        public static List<int> DFS(int vertex, int src, List<Tuple<int, int>> edges)
        {
            Graph graph = new Graph(vertex);
            foreach(var edge in edges)
            {
                graph.AddEdge(edge.Item1, edge.Item2);
                graph.AddEdge(edge.Item2, edge.Item1);
            }

            return graph.DFS(src);
        }

        public static void Main()
        {
            List<Tuple<int, int>> edges = new List<Tuple<int, int>>();
            edges.Add(new Tuple<int, int>(1, 2));
            edges.Add(new Tuple<int, int>(1, 3));
            edges.Add(new Tuple<int, int>(2, 3));
            edges.Add(new Tuple<int, int>(4, 2));
            edges.Add(new Tuple<int, int>(1, 5));

            List<int> traversal = DFS(5, 3, edges);
            foreach(int v in traversal)
            {
                Console.Write($"{v} ");
            }
        }
    }
}
