using Priority_Queue;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Algorithms.Graph
{
    public class Dijkstra
    {
        class Graph
        {
            private int _totalNodes;
            private bool _directedGraph;
            private Dictionary<int, List<Tuple<int, int>>> _edges;
            private const int INFINITY = (int)1e9;
            
            public Graph(int totalNodes, bool directedGraph)
            {
                _totalNodes = totalNodes;
                _directedGraph = directedGraph;
                _edges = new Dictionary<int, List<Tuple<int, int>>>();
            }

            public void AddEdge(int source, int destination, int weight)
            {
                if(!_edges.ContainsKey(source))
                {
                    _edges.Add(source, new List<Tuple<int, int>>());
                }
                _edges[source].Add(new Tuple<int, int>(destination, weight));

                if(!_directedGraph)
                {
                    if(!_edges.ContainsKey(destination))
                    {
                        _edges.Add(destination, new List<Tuple<int, int>>());
                    }
                    _edges[destination].Add(new Tuple<int, int>(source, weight));
                }
            }

            public Object ShortestPath(int source, int destination)
            {
                List<int> parent = Enumerable.Repeat(-1, _totalNodes + 1).ToList();
                List<int> distance = Enumerable.Repeat(INFINITY, _totalNodes + 1).ToList();
                List<bool> visited = Enumerable.Repeat(false, _totalNodes + 1).ToList();
                
                SimplePriorityQueue<int> pq = new SimplePriorityQueue<int>();
                pq.Enqueue(source, 0);
                distance[source] = 0;

                while(pq.Count > 0)
                {
                    int u = pq.Dequeue();

                    if(visited[u] == true || !_edges.ContainsKey(u))
                    {
                        continue;
                    }

                    foreach(var edge in _edges[u])
                    {
                        if(!visited[edge.Item1] && distance[edge.Item1] > distance[u] + edge.Item2)
                        {
                            distance[edge.Item1] = distance[u] + edge.Item2;
                            pq.Enqueue(edge.Item1, distance[edge.Item1]);
                            parent[edge.Item1] = u;
                        }
                    }

                    visited[u] = true;
                }

                List<int> shortestPath = new List<int>();
                int finalDestination = destination;

                if(distance[destination] != INFINITY)
                {
                    while (true)
                    {
                        shortestPath.Add(finalDestination);
                        finalDestination = parent[finalDestination];

                        if (finalDestination == -1)
                        {
                            break;
                        }
                    }

                    shortestPath.Reverse();
                }

                Object result = new
                {
                    distance = distance[destination] == INFINITY ? -1 : distance[destination],
                    path = shortestPath
                };
                
                return result;
            }
        }

        public static Object RunDijkstra(int totalNodes, bool isDirected, int source, int destination, List<Tuple<int, int, int>>  edges)
        {
            Graph graph = new Graph(totalNodes, isDirected);
            foreach(var edge in edges)
            {
                graph.AddEdge(edge.Item1, edge.Item2, edge.Item3);
            }

            return graph.ShortestPath(source, destination);
        }

        public static void Main()
        {
            var result = RunDijkstra(5, true, 1, 5, new List<Tuple<int, int, int>> {
                new Tuple<int, int, int>(1, 2, 2),
                new Tuple<int, int, int>(2, 5, 8),
                new Tuple<int, int, int>(2, 3, 4),
                new Tuple<int, int, int>(4, 1, 1),
                new Tuple<int, int, int>(3, 4, 3),
                new Tuple<int, int, int>(3, 5, 1)
            });

            int distance = (int)result.GetType().GetProperty("distance").GetValue(result, null);
            List<int> path = (List<int>)result.GetType().GetProperty("path").GetValue(result, null);

            Console.WriteLine($"Distance: {distance}");
            Console.WriteLine($"Path: {string.Join("->", path)}");
        }
    }
}
