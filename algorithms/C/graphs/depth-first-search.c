/* Depth-first search (DFS) is an algorithm for traversing or searching tree or graph data structures. 
The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph) and 
explores as far as possible along each branch before backtracking.*/

#include <stdio.h>

// Adjacency Matrix
int G[][5] = {
    {0, 1, 1, 1, 0},
    {1, 0, 1, 0, 0},
    {1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0}};

int start = 0, n = 5;

void DFSTraversal(int G[][5], int start, int n)
{
    static int visited[5] = {0};
    int j;
    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;
        for (j = 1; j < n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0){
                DFSTraversal(G, j, n);
            }
        }
    }
}

int main()
{
    DFSTraversal(G, start, n);
    return 0;
}

/*
Output:
0 1 2 4 3 
*/