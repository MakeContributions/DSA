# N-Queens Problem

N-Queens is a backtracking problem. Given a N x N chess board, our task is to arrange N queens in a way such that no two queens attack each other. Two queens are attacking each other if they are in same row, same column or diagonal. Minimum chess board size should be 4x4.

## Steps

1. Each row contains 1 queen
2. For each row, keep track of the valid columns for queen placement. # (NOTE in a clever way)
3. DFS, start from the first row, try each valid column and backtrack if necessary.
4. Note that we can encode left/right diagonals as indexes in the following way:
For any (r, c),
 - its top-left to the bottom-right diagonal index is r – c, ∈ (-n, n)
  - its bottom-left to the top-right diagonal index is r + c, ∈ [0, 2n)
5. Each (r, c) takes the r-th row, c-th column, and the two diagonal indexes encoded above.
6. Now we can use 4 sets to indicate whether those row/col/diagonal have been taken, if yes, a queen cannot be placed at (r, c).
7. Moreover, if we search via dfs, proceeding row by row, we can avoid keeping # the row set, getting away with 3 sets only (column, and 2 diagonals).
8. Each set indicates whether the column/diagonal with the specified index has been taken.

## Example

Given size of Chessboard: **N=4**

2 solutions exists. They are:
![4-Queens solution image](https://tse3.mm.bing.net/th?id=OIP.9CG0udqpuL95M7-dksk1ZwHaDc&pid=Api&P=0)

## Time Complexity

O(N!)

## Implementation

- [C++](../../../algorithms/CPlusPlus/Backtracking/n-queens.cpp)

## Video URL

[Youtube Video explaining N-queens problem](https://youtu.be/xFv_Hl4B83A)

