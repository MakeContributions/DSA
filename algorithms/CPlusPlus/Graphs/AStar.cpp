/* Find Shortest Distance from source to destination using AStar Algorithm*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

const int INF = 1e9;

// Structure to represent a node in the graph
struct Node
{
    int id;        // Node ID
    int distance;  // Shortest distance from the source
    int heuristic; // Heuristic value

    Node(int id, int distance, int heuristic) : id(id), distance(distance), heuristic(heuristic) {}

    // Comparison operator for priority queue
    bool operator<(const Node &other) const
    {
        return distance + heuristic > other.distance + other.heuristic;
    }
};

// A* algorithm to find the shortest path
void astar(const std::vector<std::vector<std::pair<int, int>>> &graph, int source, int destination, std::vector<int> &distances)
{
    int n = graph.size();
    distances.resize(n, INF);
    std::priority_queue<Node> pq;
    pq.push(Node(source, 0, 0));
    distances[source] = 0;

    while (!pq.empty())
    {
        Node current = pq.top();
        pq.pop();
        int u = current.id;
        int dist = current.distance;

        if (u == destination)
        {
            break; // Reached the destination, terminate early
        }

        if (dist > distances[u])
        {
            continue; // Ignore outdated entries in the priority queue
        }

        for (const auto &neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            int newDist = dist + weight;

            if (newDist < distances[v])
            {
                int heuristic = 0; // Calculate the heuristic value for each node here
                distances[v] = newDist;
                pq.push(Node(v, newDist, heuristic));
            }
        }
    }
}

int main()
{
    int n = 6; // Number of nodes in the graph
    std::vector<std::vector<std::pair<int, int>>> graph(n);

    // Add edges to the graph
    graph[0].emplace_back(1, 2);
    graph[0].emplace_back(2, 4);
    graph[1].emplace_back(2, 1);
    graph[1].emplace_back(3, 7);
    graph[2].emplace_back(4, 3);
    graph[3].emplace_back(4, 1);
    graph[3].emplace_back(5, 5);
    graph[4].emplace_back(5, 2);

    std::vector<int> distances;
    astar(graph, 0, 5, distances);

    // Print shortest distance to the destination
    std::cout << "Shortest distance from node 0 to node 5: " << distances[5] << std::endl;

    return 0;
}
