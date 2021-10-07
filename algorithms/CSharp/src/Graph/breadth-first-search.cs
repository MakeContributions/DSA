using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Algorithms.Graph
{
    public class BreadthFirstSearch
    {
        public class Graph
        {
            private List<List<int>> _edges;
            private bool _isDirected;
            private int _totalNodes;

            public Graph(int totalNodes, bool isDirected)
            {
                _isDirected = isDirected;
                _totalNodes = totalNodes;
                _edges = new List<List<int>>();
                for(int i = 0; i <= totalNodes; i++)
                {
                    _edges.Add(new List<int>());
                }
            }

            public void AddEdge(int source, int destination)
            {
                _edges[source].Add(destination);
                if(!_isDirected)
                {
                    _edges[destination].Add(source);
                }
            }

            public List<int> BFS(int source)
            {
                List<int> path = new List<int>();
                Queue<int> q = new Queue<int>();
                bool[] visited = Enumerable.Repeat(false, _totalNodes + 1).ToArray();
               
                q.Enqueue(source);
                visited[source] = true;

                while(q.Count() > 0)
                {
                    int u = q.Dequeue();
                    path.Add(u);

                    foreach(int v in _edges[u])
                    {
                        if(!visited[v])
                        {
                            q.Enqueue(v);
                            visited[v] = true;
                        }
                    }
                }

                return path;
            }
        }

        public static List<int> BFSDriver(int totalNodes, bool isDirected, int source, List<Tuple<int, int>> edges)
        {
            Graph graph = new Graph(totalNodes, isDirected);
            foreach(var edge in edges)
            {
                graph.AddEdge(edge.Item1, edge.Item2);
            }

            return graph.BFS(source);
        }

        public static void Main()
        {
            List<Tuple<int, int>> edges = new List<Tuple<int, int>>()
            {
                new Tuple<int, int>(1, 2),
                new Tuple<int, int>(1, 3),
                new Tuple<int, int>(2, 3),
                new Tuple<int, int>(3, 1),
                new Tuple<int, int>(3, 4),
                new Tuple<int, int>(4, 4),
            };

            var results = BFSDriver(4, true, 3, edges);
            Console.WriteLine(string.Join("->", results));
        }
    }
}
