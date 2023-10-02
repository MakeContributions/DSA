// N-Queens problem, Given N no. of Queens and we need to place all Queens in ("n x n" matrix)(we will deal with a matrix without actual formation of it.) in a way such that they do not attack each other.
// i.e.,
// No two Queens should be in same vertical and horizontal column and neither in two diagonals(left and right diagonals).

// Example:
// Input: 4
// Output:
/*
            . Q . .
            . . . Q
            Q . . .
            . . Q .
*/


#include<iostream>
#include<vector>
using namespace std;

void solve(int n, vector<int>& pos, int r, vector<vector<string> >& ans){
    // Base case.
    if(r==n){
        vector<string> help; //stores the current solution.
        for(int i=0; i<pos.size(); i++){
            string s(n, '.');
            s[pos[i]] = 'Q';
            help.push_back(s);
        }
        ans.push_back(help); //pushing the current solution to the vector of all possible solutions.
        return;
    }

    // Recursive case.
    for(int i=0; i<n; i++){
        bool validPos = true; //to check if the position is valid or not.
        for(int j=0; j<r; j++){
            //i-(r-j) and i+(r-j) are the positions of left and right diagonals respectively.
            if(pos[j]==i or pos[j]==i-(r-j) or pos[j]==i+(r-j)){
                validPos = false;
                break;
            }
        }
        if(validPos){
            // if the position is valid then we will place the queen at that position and call the function for next row.
            pos[r]=i;
            solve(n, pos, r+1, ans);
        }
    }
}

int main(){
    int n; //number of rows and columns.
    cin>>n;

    vector<vector<string> > ans; //stores all possible solutions.
    vector<int> pos(n); //stores the position of queens in each row.

    solve(n, pos, 0, ans); //calling the function to solve the problem.

    //printing all possible solutions returneds.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            string s = ans[i][j];
            for(int k=0; k<n; k++){
                cout<<s[k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}