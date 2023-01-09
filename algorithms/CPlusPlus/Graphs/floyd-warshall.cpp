#include <bits/stdc++.h>

using namespace std;
const int N = 500, OO = 1e9;

int dist[N][N];

//Initialize the distance matrix with infinities to indicate that there is no edge between nodes
void initialize_dist(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = OO;
            if (i == j) {
                dist[i][j] = 0;
            }
        }
    }
}

//Take Edge input and update the distance matrix
void input(int m) {
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
    }
}

//Perform Floyd-Warshall algorithm to calculate all shortest paths
int floyd(int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

//Take queries and output the shortest distance for each query
void output(int q) {
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << dist[x][y] << endl;
    }
}

int main() {
    int n, m, q;
    cin >> n; // Number of nodes
    initialize_dist(n);
    cin >> m; // Number of edges
    input(m);
    floyd(n);
    cin >> q; // Number of queries
    output(q);
    return 0;
}

/*
Time Complexity: O(n^3)
Memory Complexity: O(n^2)
*/

/*
Example:
    5 // Number of nodes
    10 // Number of edges
    0 1 5 // Edge from Node 0 to Node 1 with Weight 5
    0 2 3
    0 3 4
    0 4 1
    1 2 4
    1 3 1
    1 4 1
    2 3 1
    2 4 2
    3 4 4
    10 // Number of Queries
    0 1 // Print Minimum Path between Nodes 0 and 1
    0 2
    0 3
    0 4
    1 2
    1 3
    1 4
    2 3
    2 4
    3 4

Output:
    2 //Minimum path from 0 to 1
    3 //Minimum path from 0 to 2
    3 //Minimum path from 0 to 3
    1 //Minimum path from 0 to 4
    2 //Minimum path from 1 to 2
    1 //Minimum path from 1 to 3
    1 //Minimum path from 1 to 4
    1 //Minimum path from 2 to 3
    2 //Minimum path from 2 to 4
    2 //Minimum path from 3 to 4
 */
