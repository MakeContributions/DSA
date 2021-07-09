//Topological sort to check order using dfs

#include<bits/stdc++.h>

using namespace std;

/*
Using graph class with vector of nodes to represent DAG(Directed acyclic graph)
adding edge and display functions in class along with Cycle to check for cycle
and if no cycle exits then print a topological sort.
*/
class Graph {

  int n = 0;
  vector < int > * EdgeList;

  public:
    Graph() {
      n = 0;
    }

  Graph(int s) { //initialize edgelist as vector of nodes
    n = s;
    EdgeList = new vector < int > [n];
  }
  void addEdge(int src, int dest) { //add edges

    EdgeList[src].push_back(dest);

  }

  bool Cycle(int v, vector < int > & visited, vector < int > & rec) { //Check cycle

    if (!visited[v]) {

      visited[v] = 1;
      rec[v] = 1;

      for (auto it: EdgeList[v]) {

        if (!visited[it] && Cycle(it, visited, rec)) return true;

        else if (rec[it]) return true;

      }
    }

    rec[v] = 0;
    return false;
  }

  void TopSort(int v, vector < int > & visited, stack < int > & s) { //Topological sorted elements added in stack

    visited[v] = 1;
    vector < int > ::iterator it;
    for (it = EdgeList[v].begin(); it != EdgeList[v].end(); it++) {

      if (!visited[ * it]) TopSort( * it, visited, s); //visit graph in order(depth first) for topological

    }

    s.push(v);

  }

};

int main() {

  int flag = 0, n, k, src, dest;
  cout << "\nEnter no. of nodes\n"; //input number of nodes
  cin >> n;
  Graph g(n);
  vector < int > visited(n, 0); //stack to keep track of topological sort,visited vector to keep track of nodes visited and rec stack to detect cycle
  vector < int > rec(n, 0);
  stack < int > s;

  for (int i = 0; i < n; i++) {
    cout << "Enter 1 to add edge from node " << i << ",0 to exit" << "\n"; //take input
    cin >> k;
    while (k) {

      cout << "\nEnter dest\n";
      cin >> dest;
      g.addEdge(i, dest);

      cout << "Enter 1 to add edge from node " << i << ",0 to exit" << "\n";
      cin >> k;
    }
  }

  for (int i = 0; i < n; i++) {
    if (g.Cycle(i, visited, rec)) { //check for cycle

      flag = 1;
      break;
    }
  }

  if (flag) cout << "Not DAG"; //if not cycle then find topological sort 

  else {

    fill(visited.begin(), visited.end(), 0);

    for (int i = 0; i < n; i++) {
      if (!visited[i]) g.TopSort(i, visited, s);
    }
    cout << "\nOne topological sorted order: ";
    while (!s.empty()) { //print stack contents

      cout << s.top() << " ";
      s.pop();
    }
  }

  return 0;
}

/*

Time Complexity-O(V+E)
Space Complexity-O(V)

Enter no. of nodes
6
Enter 1 to add edge from node 0,0 to exit
0
Enter 1 to add edge from node 1,0 to exit
0
Enter 1 to add edge from node 2,0 to exit
1

Enter dest
3
Enter 1 to add edge from node 2,0 to exit
0
Enter 1 to add edge from node 3,0 to exit
1

Enter dest
1
Enter 1 to add edge from node 3,0 to exit
0
Enter 1 to add edge from node 4,0 to exit
1

Enter dest
0
Enter 1 to add edge from node 4,0 to exit
1

Enter dest
1
Enter 1 to add edge from node 4,0 to exit
0
Enter 1 to add edge from node 5,0 to exit
1

Enter dest
0
Enter 1 to add edge from node 5,0 to exit
1

Enter dest
2
Enter 1 to add edge from node 5,0 to exit
0
One Topological sorted order: 5 4 2 3 1 0
*/
