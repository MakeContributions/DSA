// Time Complexity : O(8^(n^2))
// There are N2 Cells and for each, we have a maximum of 8 possible moves to choose from
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Display(vector<vector<int>> &arr)
{
    for (auto row : arr)
    {
        for (auto num : row)
        {
            if (num)
                cout << "K ";
            else
                cout << "x ";
        }
        cout << endl;
    }
    cout << endl;
}
bool IsValid(vector<vector<int>> &arr, int row, int col)
{
    if (row >= 0 && row < arr.size() && col >= 0 && col < arr.size())
    {
        return true;
    }
    return false;
}
bool IsSafe(vector<vector<int>> &arr, int row, int col)
{
    if (IsValid(arr, row - 2, col - 1) == 1)
    {
        if (arr[row - 2][col - 1] == 1)
            return false;
    }
    if (IsValid(arr, row - 2, col + 1) == 1)
    {
        if (arr[row - 2][col + 1] == 1)
            return false;
    }
    if (IsValid(arr, row + 1, col + 2) == 1)
    {
        if (arr[row + 1][col + 2] == 1)
            return false;
    }
    if (IsValid(arr, row - 1, col + 2) == 1)
    {
        if (arr[row - 1][col + 2] == 1)
            return false;
    }
    if (IsValid(arr, row + 2, col - 1) == 1)
    {
        if (arr[row + 2][col - 1] == 1)
            return false;
    }
    if (IsValid(arr, row + 2, col + 1) == 1)
    {
        if (arr[row + 2][col + 1] == 1)
            return false;
    }
    if (IsValid(arr, row + 1, col - 2) == 1)
    {
        if (arr[row + 1][col - 2] == 1)
            return false;
    }
    if (IsValid(arr, row - 1, col - 2) == 1)
    {
        if (arr[row - 1][col - 2] == 1)
            return false;
    }
    return true;
}

void Knight(vector<vector<int>> &board, int row, int col, int knights)
{
    if (knights == 0) // If all knights are places than show the board
    {
        Display(board);
        return;
    }
    if (row == board.size() - 1 && col == board.size())
    {
        return; // out of bounds
    }
    if (col == board.size())
    {
        Knight(board, row + 1, 0, knights); // switching rows
        return;
    }
    if (IsSafe(board, row, col))
    {
        board[row][col] = true; // Placing the knight
        Knight(board, row, col + 1, knights - 1);
        board[row][col] = false; // Backtraking
    }
    Knight(board, row, col + 1, knights);
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr =
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}};
    // Display(arr);
    Knight(arr, 0, 0, 5);

    return 0;
}
