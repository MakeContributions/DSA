                                                          // ***** SUDOKU SOLVER ALGORITHM******** \\ (CONTRIBUTED BY : SHAWAIZ SIDDIQUI (github: @Shawaiz22))


//THIS IS THE ALGORITHM USING BACKTRACKING FOR SOLVING SUDOKU. 

// SUDOKU IS A VERY POPULAR PUZZLE GAME IN WHICH WE HAVE A 9X9 GRID IN WHICH WE HAVE TO FILL DIGITS (1-9) IN SUCH A MANNER THAT NO DIGIT IS REPEATED IN THE SAME ROW, 
// OR IN THE SAME COLUMN OR THE INSIDE THE SMALL GRID ( THE SMALL GRID IS A 3x3 GRID, WHICH IS A PART OF THIS 9X9 GRID, THERE ARE SUCH 9 GRIDS IN THE BIGGER GRID). 
// SO OUR TASK IS TO FILL THE NUMBERS IN THE BLANK SPACES (SOME SPACES WILL ALREADY BE FILLED WHICH CAN'T BE CHANGED), SUCH THAT IT MATCHES ALL THE CONDITIONS. WE USE 
// BACKTRACKING ALGORITHM HERE, WHICH SOLVES THIS PROBLEM IN VARIOUS HIT AND TRIALS AND FINALLY GIVES THE OUTPUT AS THE RESULTANT SOLUTION.


//*****************ALGORITHM INFORMATION******************\\

// Time complexity: O (9^ (n*n)). For every unassigned index, there are 9 possible options so the time complexity is O (9^ (n*n))

//*********************************************************\\



public class Sudoku_Solver {

    public static boolean sudokuSolution(int[][] sudoku, int row, int col){


        // base case:
        if(row==9){     //case when we have checked all the rows and crosed the last row
            return true;
        }

        int nextRow=row, nextCol=col+1;

        if(col+1==9){
            nextRow=row+1;
            nextCol=0;
        }

        if(sudoku[row][col]!=0){  /// condition when my sudoku is not blank
            return sudokuSolution(sudoku,nextRow,nextCol);
        }

        for(int digit=1;digit<=9;digit++){


         if(isSafe(sudoku,row,col,digit)){
             sudoku[row][col]=digit;
             // if it is safe to place the digit, then place it and call the recursive function for next row and next col!

             if(sudokuSolution(sudoku,nextRow,nextCol)){
                 return true;     //if solution exists for the next row and col too, then return true to the previous levels in call stack
             }
             // if it is not true, then I will backtrack and set zero at current position, because due to the previous placement of digit
                // solution does not exists,
           
           // backtrack
             sudoku[row][col]=0;
         }

        }

//        else if no digit fits here, then it has no solution, so return false from here
        return false;
    }


    public static boolean isSafe(int[][] sudoku, int row, int col, int digit){

        // row wise check
        for(int i=0;i<9;i++){
            if(sudoku[row][i]==digit){
                return false;
            }
        }

        // col wise check
        for(int i=0;i<9;i++){
            if(sudoku[i][col]==digit){
                return false;
            }
        }

        // grid check
      // here we find the start row and start cols of the grid using the formula, then travesing in the grid(3x3), we check for the digits
      
        int sr = (row/3)*3;
        int sc = (col/3)*3;

        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(sudoku[i][j]==digit){
                    return false;
                }
            }
        }

        return true;
    }

    public static void printSudoku(int[][] sudoku){
        System.out.println("_____________________");
        for(int i=0;i<sudoku.length;i++){
            System.out.print("| ");
            for(int j=0;j<sudoku[0].length;j++){
                System.out.print(sudoku[i][j]+" ");
            }
            System.out.print("| ");
            System.out.println();
        }
        System.out.println("_____________________");
    }

    public static void main(String[] args) {
        int[][] sudoku = {{5,6,8,0,9,3,0,0,7},
                          {3,4,0,0,0,7,0,0,5},
                          {0,9,7,5,0,4,6,0,3},
                          {7,0,0,0,1,2,5,0,0},
                          {0,1,9,0,0,8,7,6,0},
                          {0,8,0,7,0,0,0,3,0},
                          {0,2,0,0,3,5,8,0,0},
                          {0,5,1,2,0,6,3,0,0},
                          {0,0,0,9,0,0,0,0,0}};

        boolean res = sudokuSolution(sudoku,0,0);

        if(res){
            System.out.println("SOLVED SUDOKU IS: ");
            printSudoku(sudoku);
        }
        else{
            System.out.println("SOLUTION DOES NOT EXIST");
        }
    }
}

 


//************************************ (CODE CONTRIBUTED BY :  SHAWAIZ SIDDIQUI (github: @Shawaiz22) )******************************************\\
