#include <iostream>
#include <vector>
#include <valarray>
using namespace std;
bool flag {false}; 
//given m colors return true or false if they can colored or not =

#define N 4 // N vertices
//m colors, v= starting vertex, adjMatrix and color, pos


int chromatic_number{-1}; 

bool bfun(int pos, vector<vector<int>> adjMatrix, vector<int> color, int c) {
    for(int i = 0; i<N;i++) {//checking each adjacent vertex
        if(adjMatrix[pos][i]==1 && c==color[i]) //if vertex is adjacent and the color filled is c then return false
            return false;
    }
    return true;
}

void printConfig(vector<int> color) {
    for(int i = 0; i<N; i++) {
        cout<<"vertex "<<i<<" is assigned "<<color[i]<<"\n";
    }
}

void graphColoring(vector<vector<int>> adjMatrix, int m, vector<int> color, int pos) {
    if(pos==N){
        printConfig(color); 
        cout<<"\n";
        flag = true;
        return; 
    }
    for(int i = 0; i<m; i++) {//trying every color
        if(bfun(pos, adjMatrix, color, i)) {
            color[pos] = i; 
            graphColoring(adjMatrix, m, color,pos+1); 
            color[pos] = -1; 
        }
    }
    if(!flag)
        printf("there doesnt exist any solution");
}
//bounding function will be if there's a color already filled 
//adjacent to the node 
//dont fill the color
vector<vector<int>> adjMatrix = {{0, 1, 0, 1}, {1,0,1,0}, {0,1,0,1}, {1,0,1,0}};
 



int main() {
    vector<int>color(N,-1);
    graphColoring(adjMatrix, 2, color, 0);
    return 0;
}