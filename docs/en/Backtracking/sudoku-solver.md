# Sudoku Solver

Sudoku Solver is a backtracking problem. Given a 9×9 incomplete sudoku, our task is to solve it such that it becomes valid sudoku. 
Valid sudoku has the following properties.
1. All the rows should be filled with numbers(1 – 9) exactly once.
2. All the columns should be filled with numbers(1 – 9) exactly once.
3. Each 3×3 submatrix should be filled with numbers(1 – 9) exactly once.

## Steps

1. The main recursive function(solveSudoku()) is going to just do a plain matrix traversal of the sudoku board. we find an empty cell, we pause and try to put all available numbers(1 – 9) in that particular empty cell.
2. We need another loop to do that. But wait, we forgot one thing – the board has to satisfy all the conditions, right? So, for that we have another function(isValid()) which will check whether the number we have inserted into that empty cell will not violate any conditions.
3. If it is violating, we try with the next number. If it is not, we call the same function recursively, but this time with the updated state of the board. Now, as usual it tries to fill the remaining cells in the board in the same way.
4. Now we’ll come to the returning values. If at any point we cannot insert any numbers from 1 – 9 in a particular cell, it means the current state of the board is wrong and we need to backtrack. An important point to follow is, we need to return false to let the parent function(which is called this function) know that we cannot fill this way. This will serve as a hint to that function, that it needs to try with the next possible number.

(https://lh6.googleusercontent.com/K6GqbUp1oiY3S01bZtxY6S7N8GCiLBke55d46BJ0fm2Eia8EDU284lyfWHoJ4kE_T0xpPh-ZU-GwNiCZ6Z9RtPDWqUJSBSHYp3PQFLulvIufpuI5dQnoz3Mr1TWZ4nF9S0idTtwM)

5. If a recursive call returns true, we can assume that we found one possible way of filling and we simply do an early return.

### Validating Board

1. Now, let’s see how we are validating the sudoku board. After determining a number for a cell(at i’th row, j’th col), we try to check the validity. As we know, a valid sudoku needs to satisfy 3 conditions, we can use three loops. But we can do within a single loop itself. Let’s try to understand that.
2. We loop from 0 to 8 and check the values – board[i][col](1st condition) and board[row][i](2nd condition), whether the number is already included. For the 3rd condition – the expression (3 * (row / 3) + i / 3) evaluates to the row numbers of that 3×3 submatrix and the expression (3 * (col / 3) + i % 3) evaluates to the column numbers.
3. For eg, if row= 5 and col= 3, the cells visited are
   
(https://lh5.googleusercontent.com/GnjFYRHaRovFUhHEOxNU5cAwvSnJ1rZGxNB_0Iax5h4O5fX12kb5DPKbZn0lvej1NS_0AW4Khl4NYrpcA0hKpTwP5CafGGUpUZDLCrG8yxzN2jr0XdElxirzRqiWjyx1TlRthrLv)

## Example

(https://lh5.googleusercontent.com/k78fKDRjAJU3CIBgMRYCDEG93ndte0k85JLWYK6IumRreKBRv5zcKDkc1Ms_E6Bi_2M4twPY5GWos_0kQNkZO9AXRtowc5sKe5KZMJpcCqKddtXDr7xuA-HZDIttJ_-5RE30NlDJ)

The empty cells are filled with the possible numbers. There can exist many such arrangements of numbers. The above solution is one of them. Let’s see how we can fill the cells below.

## Implementation

[C++](../../../algorithms/CPlusPlus/Backtracking/sudoku-solver.cpp)

## Time Complexity & Space Complexity

**Time Complexity**: O(9(n<sup>2</sup>)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.

**Space Complexity**: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.

