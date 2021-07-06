//Topological sort to check order using dfs

#include<bits/stdc++.h>

using namespace std;

typedef struct node{

    
    int dest;

}node;
/*
Using graph class with vector of nodes to represent DAG(Directed acyclic graph)
adding edge and display functions in class along with Cycle to check for cycle
and if no cycle exits then print a topological sort.
*/
class Graph{

    int n=0;
    vector<node>* EdgeList;
    
    public:
    Graph(){
        n=0;
    }

    Graph(int s){                                                       //intialise edgelist as vector of nodes
        n=s;
        EdgeList= new vector<node>[n];
    }
    void addEdge(int src,int dest){                                         //add edges

        node newNode;
        newNode.dest=dest;
        
        EdgeList[src].push_back(newNode);
        
    }

    bool Cycle(int v,vector<int>&visited,vector<int>&rec){                  //Check cycle

        if(!visited[v]){
            
            visited[v]=1;
            rec[v]=1;
            
            for(auto it:EdgeList[v]){
            
            if(!visited[it.dest]&&Cycle(it.dest,visited,rec)) return true;
            
            else if(rec[it.dest]) return true;
                
            }
        }
        
        
        rec[v]=0;
        return false;
    }

    void TopSort(int v,vector<int>&visited,stack<int>&s){                   //Topological sorted elements added in stack

        visited[v]=1;

        for(auto it:EdgeList[v]){

            if(!visited[it.dest]) TopSort(v,visited,s);                     //visit graph in order(depth first) for topological

        }

        s.push(v);

    }

    
    void display(){                                                         //display edges
        
        for(int i=0;i<n;i++){
            for(auto it:EdgeList[i]){

                cout<<it.dest<<"\n";
            }
        }
        
    }
};

int main(){

    Graph g(4);
    int flag=0;
    vector<int>visited(4,0);                //stack to keep track of topological sort,visited vector to keep track of nodes visited and rec stack to detect cycle
    vector<int>rec(4,0);
    stack<int>s;
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    g.addEdge(1, 0);
    g.addEdge(2, 0);
    g.addEdge(3, 1);
    g.addEdge(3, 2);

    // g.display();

   

    for(int i=0;i<4;i++){
        if(g.Cycle(i,visited,rec)) {                        //check for cycle

            flag=1;
            break;
        }
    }

    if(flag) cout<<"Not DAG";                                   //if not cycle then find topological sort 

    else {

        fill(visited.begin(),visited.end(),0);

        for(int i=0;i<4;i++){
            if(!visited[i]) g.TopSort(i,visited,s);
        }
        
        cout<<"\n";

        while(!s.empty()){                                      //print stack contents

            cout<<s.top();
            s.pop();
        }
    }

}

