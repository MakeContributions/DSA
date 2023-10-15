/*
This problem does the addition the diagonals in a square
matrix and then, it does the difference of both in 
absolute value.

Time of complexity: O(n^2)
*/

namespace Algorithms.Maths
{
    public class Matrix
    {
        public static int diagonalDifference(List<List<int>> arr)
        {
            int firstDiagonal = 0;
            int secondDiagonal = 0;
            int longitud = Convert.ToInt32(arr.LongCount());
            int total = 0;
        /**
        Loop to iterate over the entire matrix twice. Each iteration adds 
        the current element to the corresponding diagonal. 
        **/
            for (int i =0; i < longitud; i++){
                firstDiagonal += arr[i][i];
                secondDiagonal += arr[i][(longitud)-1-i];
            }
        /*
        Difference of both diagonals. The conditional statement will "convert"
        the possible negative value into positive.
        **/
            total = firstDiagonal - secondDiagonal;
            if (total < 0) {
                total = total * (-1);
            }
            return total;
        }

    }



     class Solution
    {
        public static void Main(string[] args)
        {
           //Variable to get the number of rows and columns.
            int n = Convert.ToInt32(Console.ReadLine().Trim());
            
            //Declaring list of two dimensions
            List<List<int>> arr = new List<List<int>>();

            //For loop to save user input into the list
            for (int i = 0; i < n; i++)
            {
                arr.Add(Console.ReadLine().TrimEnd().Split(' ').ToList().Select(arrTemp => Convert.ToInt32(arrTemp)).ToList());
            }

            //Calling the previous method and saving it in result variable
            int result = Matrix.diagonalDifference(arr);

            //Finally it displays out the result
            Console.WriteLine(result);

            
        }   
    }
}

