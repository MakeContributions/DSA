// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

// Example 1:
// Input: board = 
// [["5","3",".",".","7",".",".",".","."],
//  ["6",".",".","1","9","5",".",".","."],
//  [".","9","8",".",".",".",".","6","."],
//  ["8",".",".",".","6",".",".",".","3"],
//  ["4",".",".","8",".","3",".",".","1"],
//  ["7",".",".",".","2",".",".",".","6"],
//  [".","6",".",".",".",".","2","8","."],
//  [".",".",".","4","1","9",".",".","5"],
//  [".",".",".",".","8",".",".","7","9"]]

// Output:
// [["5","3","4","6","7","8","9","1","2"],
//  ["6","7","2","1","9","5","3","4","8"],
//  ["1","9","8","3","4","2","5","6","7"],
//  ["8","5","9","7","6","1","4","2","3"],
//  ["4","2","6","8","5","3","7","9","1"],
//  ["7","1","3","9","2","4","8","5","6"],
//  ["9","6","1","5","3","7","2","8","4"],
//  ["2","8","7","4","1","9","6","3","5"],
//  ["3","4","5","2","8","6","1","7","9"]]


// Code Explanation: The input board is shown above and the only valid solution is shown below:

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool validChar(vector<vector<char> >& v, int n, int i, int j, char d){
    // Check for row and column.
    for(int k=0; k<n; k++){
        if(v[i][k]==d or v[k][j]==d){
            return false;
        }
    }
    
    // Check for sub-matrix.
    // rn is the square root of n.
    // Sx and Sy are the starting positions of the sub-matrix.
    int rn = sqrt(n);
    int Sx = (i/rn) * rn;
    int Sy = (j/rn) * rn;
    for(int i=Sx; i<(Sx+rn); i++){
        for(int j=Sy; j<(Sy+rn); j++){
            if(v[i][j]==d){
                return false;
            }
        }
    }
    return true;
}

void solve(vector<vector<char> >& v, int n, int i, int j){
    // Base Case
    // If we have reached the end of the board.
    if(i==n){
        for(int x=0; x<n; x++){
            for(int y=0; y<n; y++){
                cout<<v[x][y]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    // Case for end of row.
    if(j==n){
        solve(v, n, i+1, 0);
        return;
    }
    // Skip the pre-filled cells.
    if(v[i][j]!='.'){
        solve(v, n, i, j+1);
        return;
    }

    // Recursive Case
    for(int k=1; k<=9; k++){
        char d = k+'0';
        if(validChar(v, n, i, j, d)){ // validChar() is used to check, if the character is valid then we will place it at the current position and call the function for next position.
            v[i][j]=d;
            solve(v, n, i, j+1);
            v[i][j]='.';
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<char> > v(n, vector<char> (n));
    // vector<vector<int> > v(n, vector<int> (n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>v[i][j];
        }
    } 
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // // }
    // cout<<endl;
    solve(v, n, 0, 0); //calling the function to solve the problem.
    return 0;
}