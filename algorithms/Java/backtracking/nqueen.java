//The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.

// Algorithm Type: Backtracking
// Time Complexity: O(n!)

import java.util.*;
import java.util.Scanner;

class nqueen
{
    //Array to store left diagonal elements to check if queen can be placed in left diagonal
    static int []LeftDiagonal = new int[50];

    //Array to store right diagonal elements to check if queen can be places in right diagonal
    static int []RightDiagonal = new int[50];

    //Array to store row-wise elements to check if queen can be placed in row
    static int []cl = new int[50];

    //Function to return true and print if feasible solution is obtained else return false
    static boolean solveNQueen()
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of N for NxN chess board:\t");
        int n = sc.nextInt();
        int[][] chessBoard = new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                chessBoard[i][j]=0;
            }
        }

        if (NQueen(chessBoard, 0,n) == false)
        {
            System.out.printf("Solution does not exist");
            return false;
        }

        printChessBoard(chessBoard,n);
        return true;
    }
    //A recursive approach to solve N queens problem
    static boolean NQueen(int chessBoard[][], int column,int N)
    {
        if (column >= N) //If all queens are placed, then return true
            return true;

        for (int i = 0; i < N; i++) //placing queens in all rows of that particular column
        {
            //Check while placing a queen is not attacked by left and right diagonal elements
            if ((LeftDiagonal[i - column + N - 1] != 1 &&
                    RightDiagonal[i + column] != 1) && cl[i] != 1)
            { //If the above condition is true then place the queen
                chessBoard[i][column] = 1;
                LeftDiagonal[i - column + N - 1] =
                        RightDiagonal[i + column] = cl[i] = 1;

                if (NQueen(chessBoard, column + 1,N))
                    return true;

                //If placing this queen in chessBoard doesn't lead to a correct & safe position then remove queen from chessBoard
                //going back through BACKTRACKING
                chessBoard[i][column] = 0;
                LeftDiagonal[i - column + N - 1] =
                        RightDiagonal[i + column] = cl[i] = 0;
            }
        }
        return false; //If queen not placed in any row of this column then return false
    }

    //Function to print chess board
    static void printChessBoard(int chessBoard[][],int N)
    {
        System.out.printf("\n%d queens can be placed in the following order:\n",N);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++) {
                System.out.printf(" %d ", chessBoard[i][j]);
            }
            System.out.printf("\n");
        }
    }
    public static void main(String[] args)
    {
        nqueen obj = new nqueen();
        obj.solveNQueen();
    }
}
