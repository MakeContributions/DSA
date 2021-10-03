using System;
using System.Collections.Generic;

namespace Algorithms.Graph
{
    public class FloydWarshallAlgorithm
    {
        const int INFINITY = (int)1e9;

        public static int[,] AllPairShortestPath(int totalNode, bool isDirected, List<Tuple<int, int, int>> edges)
        {
            int[,] distance = new int[totalNode + 1, totalNode + 1];

            for (int i = 1; i <= totalNode; i++)
            {
                for (int j = 1; j <= totalNode; j++)
                {
                    distance[i, j] = i == j ? 0 : INFINITY;
                    distance[j, i] = i == j ? 0 : INFINITY;
                }
            }

            foreach (var edge in edges)
            {
                distance[edge.Item1, edge.Item2] = Math.Min(edge.Item3, distance[edge.Item1, edge.Item2]);
                distance[edge.Item2, edge.Item1] = isDirected ? distance[edge.Item2, edge.Item1] : Math.Min(edge.Item3, distance[edge.Item2, edge.Item1]);
            }

            for (int k = 1; k <= totalNode; k++)
            {
                for (int i = 1; i <= totalNode; i++)
                {
                    for (int j = 1; j <= totalNode; j++)
                    {
                        distance[i, j] = Math.Min(distance[i, j], distance[i, k] + distance[k, j]);
                    }
                }
            }

            return distance;
        }

        public static void Main()
        {
            List<Tuple<int, int, int>> edges = new List<Tuple<int, int, int>>()
            {
                new Tuple<int, int, int>(1, 4, 10),
                new Tuple<int, int, int>(1, 2, 5),
                new Tuple<int, int, int>(2, 3, 3),
                new Tuple<int, int, int>(3, 4, 1)
            };

            var results = AllPairShortestPath(4, true, edges);
            for (int i = 1; i <= 4; i++)
            {
                for (int j = 1; j <= 4; j++)
                {
                    if (results[i, j] >= INFINITY)
                    {
                        Console.Write("inf ");
                    }
                    else
                    {
                        Console.Write($"{results[i, j]} ");
                    }
                }

                Console.WriteLine();
            }
        }
    }
}
