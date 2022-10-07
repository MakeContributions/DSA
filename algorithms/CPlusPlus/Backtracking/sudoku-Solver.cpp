/*
Code Contributed by MOHIT KUMAR SUMAN to MakeContributions/DSA Github repository

Below the cpp code displays all the possible Solutions of Sudoku Solver

Problem : Given a paritally filled 9X9 2D array 'grid[9][9]', the goal is to assign digits (from 1 to 9) to the empty cells so that every row, column, and subgrid of size 3X3 contains exactly one instance of the digits from 1 to 9

Input:
grid = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} }
Output:
          3 1 6 5 7 8 4 9 2
          5 2 9 1 3 4 7 6 8
          4 8 7 6 2 9 5 3 1
          2 6 3 4 1 5 9 8 7
          9 7 4 8 6 3 1 2 5
          8 5 1 7 9 2 6 4 3
          1 3 8 9 4 7 2 5 6
          6 9 2 3 5 1 8 7 4
          7 4 5 2 8 6 3 1 9
Explanation: Each row, column and 3*3 box of 
the output matrix contains unique numbers.

Time Complexity :- O(9^(n*n))
Space Complexity :- O(n*n)

Approach:
1) Sudoku can be solved by one by one assigning numbers to empty cells, Before assigning a number, check whether it is safe to assign or not.

2) Check that the number is not present in the current roe, current column and current 3X3 subgrid.

3) After checking for safety, assign the number, and recursively check whether the assignerd number leads to the solution or not.

5) if no then try next number for the current empty cell
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//UNASSIGNED is used for empty cells
#define UNASSIGNED 0
// N is used for the size of sudoku grid
#define N 9

bool findUnassignedLocation(int grid[N][N], int &row, int &col){
   for(row = 0; row < N; row++){
      for(col = 0; col < N; col++){
         if(grid[row][col] == UNASSIGNED){
            return true;
         }
      }
   }
   return false;
}

// find that the element exist in 3X3 row or not
bool usedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num){
   for(int row = 0; row < 3; row++){
      for(int col = 0; col < 3; col++){
         if(grid[row + boxStartRow][col + boxStartCol] == num){
            return true;
         }
      }
   }
   return false;
}

// find that the element exist in the entire row or not
bool usedInRow(int grid[N][N], int row, int num){
   for(int col = 0; col < N; col++){
      if(grid[row][col] == num){
         return true;
      }
   }
   return false;
}


// find that the element exist in the entire col or not
bool usedInCol(int grid[N][N], int col, int num){
   for(int row = 0; row < N; row++){
      if(grid[row][col] == num){
         return true;
      }
   }
   return false;
}

bool isSafe(int grid[N][N], int row, int col, int num){
   return !usedInRow(grid, row, num) && !usedInCol(grid, col, num) && !usedInBox(grid, row-row%3, col-col%3, num) && grid[row][col] == UNASSIGNED;
}

bool SolveSudoku(int grid[N][N]){
   int row, col;
   // if there is no unassigned location then we are done
   if(!findUnassignedLocation(grid, row, col)){
      return true;
   }

   for(int i = 1; i <= 9; i++){
      if(isSafe(grid, row, col, i)){
         grid[row][col] = i;
         if(SolveSudoku(grid)){
            return true;
         }
         // backtrack
         grid[row][col] = UNASSIGNED;
      }
   }
   return false;
}

void printGrid(int grid[N][N]){
   for(int row = 0; row < N; row++){
      for(int col = 0; col < N; col++){
         cout<<grid[row][col]<<" ";
      }
      cout<<endl;
   }
}

int main(){
   int grid[N][N] = {{3,0, 6, 5, 0, 8, 4, 0, 0 },
                  {5, 2, 0, 0, 0, 0, 0, 0, 0 },
                  {0, 8, 7, 0, 0, 0, 0, 3, 1 },
                  {0, 0, 3, 0, 1, 0, 0, 8, 0 },
                  {9, 0, 0, 8, 6, 3, 0, 0, 5 },
                  {0, 5, 0, 0, 9, 0, 6, 0, 0 },
                  {1, 3, 0, 0, 0, 0, 2, 5, 0 },
                  {0, 0, 0, 0, 0, 0, 0, 7, 4 },
                  {0, 0, 5, 2, 0, 6, 3, 0, 0 } };
   if(SolveSudoku(grid) == true){
      printGrid(grid);
   }else{
      cout<<"No Solution Exists";
   }
   return 0;
}

// to compile
// g++ .\sudokuSolver.cpp
// .\a.exe



