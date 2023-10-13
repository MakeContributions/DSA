# Prim's Algorithm Documentation
Prim's algorithm is a greedy algorithm used for finding the minimum spanning tree (MST) of a weighted graph. It starts with an arbitrary vertex and grows the tree by adding the minimum weight edge that connects a vertex in the tree to a vertex outside of the tree. The algorithm continues until all vertices are included in the tree.

## Key Features of Prim's Algorithm

- Greedy approach: Prim's algorithm follows a greedy approach by always selecting the edge with the minimum weight that connects a vertex in the tree to a vertex outside of the tree.

- Minimum spanning tree: Prim's algorithm produces a minimum spanning tree, which is a tree that spans all vertices in the graph and has the minimum total edge weight among all such trees.

## Algorithm Steps
1. Start with an arbitrary vertex as the root of the tree.

2. Maintain a set of vertices in the tree and a set of vertices outside of the tree.

3. Find the minimum weight edge that connects a vertex in the tree to a vertex outside of the tree, and add the edge and the new vertex to the tree.

4. Repeat step 3 until all vertices are included in the tree.

## Time and Space Complexity
The time complexity of Prim's algorithm is O(E log V), where E is the number of edges and V is the number of vertices. The space complexity is O(V), as the algorithm only needs to store the vertices that are in the tree and outside of the tree.


## Implementation 
- [C](../../../algorithms/C/Graphs/Prim's-algorithm.c)
- [C++](../../../algorithms/CPlusPlus/Graphs/prim's_algorithm.cpp)
- [Java](../../../algorithms/Java/graphs/Prims.java)

## Video URL
[Youtube Video about Prims Algorithm ](https://www.youtube.com/watch?v=ZtZaR7EcI5Y)

## Others
[Wikipedia](https://en.wikipedia.org/wiki/Prim%27s_algorithm)